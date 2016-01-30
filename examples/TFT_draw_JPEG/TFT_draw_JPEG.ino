/*
  Descendant of SerialCsvOut.ino
  Sample code of JPEG Decoder for Arduino
  Public domain, Makoto Kurauchi <http://yushakobo.jp>
*/

// Adapted to display images on a 480 x 320 HX8357 or ILI9481
// 16 bit parallel TFT by Bodmer (aka rowboteer)
// Version 0.01 29/1/16

// This example draws an SD Card file called "480Mouse.jpg" onto the screen
// the image is 480 x 320 pixels, it was created with IrfanView with an
// image quality factor of 20. This compressed the image from 450 KBytes
// to a mere 6.45 KBytes (70 times smaller). The image can be found in the
// "extras" folder within the HX8357 library.

// JPEG compression works best on images with smooth variations of tone and color.
// Very high compression ratio will create increasingly apparent image artifacts.

// As well as the HX8357_Due TFT library yo will need the JPEG Decoder library.
// A copy can be downloaded here:
// https://github.com/Bodmer/JPEGDecoder

// A preconfigured copy of the SdFat library to work with the Due is availble here:
// https://github.com/Bodmer/SdFat

#include <SPI.h>
#include <arduino.h>

// Comment out next #define to use the SD library (note: works with Mega only).
// Otherwise the SdFat library will be used (works with Mega or Due)
#define USE_SDFAT

#ifdef USE_SDFAT
  #include <SdFat.h>           // Use the SdFat library
  SdFat SD;                    // Permit SD function call compatibility with no sketch changes :-)
#else
  #include <SD.h>              // Use the SD library
#endif

#include <JPEGDecoder.h>

//#include <TFT_HX8357.h> // Hardware-specific Mega library
//TFT_HX8357 tft = TFT_HX8357(); // Invoke custom Mega library

#include <TFT_HX8357_Due.h> // Hardware-specific Mega library
TFT_HX8357_Due tft = TFT_HX8357_Due(); // Invoke custom Mega library

// CS Pin of SD card
#define SD_CS 53

void setup() {

  Serial.begin(115200);

  tft.begin();
  tft.setRotation(1);  // landscape
  tft.fillScreen(TFT_BLACK);

  Serial.print("Initializing SD card...");

  if (!SD.begin(SD_CS, SPI_DIV3_SPEED)) { // <<<<<<<<<<<<< On Due use SPI_DIV3_SPEED
    //                                                     as SPI_FULL_SPEED may not work
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop() {

  drawJpeg("480Mouse.jpg");

  while (1);
}

// Draw a JPEG on the TFT, it is assumed that the image fits within the screen area
void drawJpeg(char *filename) {

  JpegDec.decode(filename, 0);

  jpegInfo(); // Print information from the JPEG file (could comment this line out)
    
  uint8 *pImg;
  uint16_t x, y;
  uint16_t mcu_w = JpegDec.MCUWidth;    // Width of MCU
  uint16_t mcu_h = JpegDec.MCUHeight;   // Height of MCU
  uint32_t mcu_pixels = mcu_w * mcu_h;  // Total number of pixels in an MCU

  uint32_t drawTime = millis(); // For comparison purpose the draw time is measured

  // Fetch data from the file, decode and display
  while (JpegDec.read()) {    // While there is more data in the file
    
    pImg = JpegDec.pImage ;   // Decode a MCU (Minimum Coding Unit, typically a 8x8 or 16x16 pixel block)

    int mcu_x = JpegDec.MCUx * mcu_w;  // Calculate coordinates of top left corner of current MCU
    int mcu_y = JpegDec.MCUy * mcu_h;

    // Now set a bounding window on the TFT to push pixels into (x, y, x + width - 1, y + height - 1)
    tft.setWindow(mcu_x, mcu_y, mcu_x + mcu_w - 1, mcu_y + mcu_h - 1);

    // Decode and push pixels to the TFT window
    uint32_t count = mcu_pixels;
    while (count--) {
      // Push each pixel to the TFT MCU area
      // The pImg [B]lue, [G]reen and [R]ed  8 bit array values are converted to 5+6+5 [B]+[G]+[R] 16 bit format)
      tft.pushColor(pImg[2] >> 3 | (pImg[1] & 0xFC) << 3 | (pImg[0] & 0xF8) << 8);
      // Decode and fetch the next pixel
      pImg += JpegDec.comps ;
    }
  }

  showTime(millis() - drawTime);

}

void jpegInfo() {

  // Print information extracted from the JPEG file
  Serial.print("JPEG file information");
  Serial.print("Width     :");
  Serial.println(JpegDec.width);
  Serial.print("Height    :");
  Serial.println(JpegDec.height);
  Serial.print("Components:");
  Serial.println(JpegDec.comps);
  Serial.print("MCU / row :");
  Serial.println(JpegDec.MCUSPerRow);
  Serial.print("MCU / col :");
  Serial.println(JpegDec.MCUSPerCol);
  Serial.print("Scan type :");
  Serial.println(JpegDec.scanType);
  Serial.print("MCU width :");
  Serial.println(JpegDec.MCUWidth);
  Serial.print("MCU height:");
  Serial.println(JpegDec.MCUHeight);
  Serial.println("");
}

void showTime(uint32_t msTime) {
  tft.setCursor(0,0);
  tft.setTextFont(4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.print(F("JPEG image drawn in "));
  tft.print(msTime);
  tft.print(F(" ms"));
}

//####################################################################################################
// How to setup SdFat to work with the JPEGDecoder library
//####################################################################################################

// The SD library can be used on the Mega only, it will not work with the Due as the TFT
// display is not connected to the hardware SPI pins. The SD library does NOT need to be
// modified.

// The SdFat library can be used with the Mega or Due.

// To use SdFat with the Due you must edit the SdFatConfig.h file so
// that the Software (bit bashed) SPI signal driving will be employed.
//
// You can get a copy of the SdFat library that has already been modified here:
// https://github.com/Bodmer/SdFat

//  The changes to be made to the SdFatConfig.h file are indicated by =>> below:

//=>>    #define SD_SPI_CONFIGURATION 2  // Set to 0 for Mega, 2 for Due
//------------------------------------------------------------------------------
/**
   If SD_SPI_CONFIGURATION is defined to be two, these definitions
   will define the pins used for software SPI.

   The default definition allows Uno shields to be used on other boards.
*/
/** Software SPI Master Out Slave In pin */
//=>>             uint8_t const SOFT_SPI_MOSI_PIN = 51;
/** Software SPI Master In Slave Out pin */
//=>>             uint8_t const SOFT_SPI_MISO_PIN = 50;
/** Software SPI Clock pin */
//=>>             uint8_t const SOFT_SPI_SCK_PIN  = 52;
//------------------------------------------------------------------------------

// You MUST also modify the SdFat.h file to make the created SD class members 'global' so
// they can be used in this sketch and by the JPEGDecoder library.
// (The SD library makes the equivalent class global without modifications)
// There may be an easier way to do this but it works OK.
//
// The line to add is 'extern SdFat SD;', this must be addedat around line 283
// after the SdFat class is specified.
// When the change has been made the following line sequence should appear in the
// SdFat.h file (do not add the /* or */ !):
/*

extern SdFat SD; //<<= Line to add, the next 2 lines are ALREADY in the file, they
                 //    are included here just to help locate the right place!
//==============================================================================
#if SD_SPI_CONFIGURATION >= 3 || defined(DOXYGEN)

*/
