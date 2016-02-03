/*
  Example for TFT_HX8357_Due library

  Created by Bodmer 3/2/16

  This example draws all fonts (as used by the Adafruit_GFX library) onto the
  screen. These fonts are called the GFX Free Fonts (GFXFF) in this library.

  The fonts are referenced by a short name, see the Free_Fonts.h file
  attached to this sketch.

  Other True Type fonts could be converted using the utility within the
  "fontconvert" folder inside the library. This converted has also been
  copied from the Adafruit_GFX library. 

  Since these fonts are a recent addition Adafruit do not have a tutorial
  available yet on how to use the fontconvert utility.   Linux users will
  no doubt figure it out!  In the meantime there are 48 font files to use
  in sizes from 9 point to 24 point, and in normal, bold, and italic or
  oblique styles.

  This example sketch uses both the print class and drawString() functions
  to plot text to the screen.

  Make sure LOAD_GFXFF is defined in the User_Setup.h file within the
  TFT_HX8357_Due library folder.

  --------------------------- NOTE ----------------------------------------
  The free font encoding format does not lend itself easily to plotting
  the background without flicker. For values that changes on screen it is
  better to use Fonts 1- 8 which are encoded specifically for rapid
  drawing with background.
  -------------------------------------------------------------------------

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  ######       TO SELECT YOUR DISPLAY TYPE AND ENABLE FONTS          ######
  #########################################################################
*/

#include <TFT_HX8357_Due.h> // Hardware-specific library

#include "Free_Fonts.h" // Include the header file attached to this sketch

TFT_HX8357_Due tft = TFT_HX8357_Due();       // Invoke custom library

unsigned long drawTime = 0;

void setup(void) {

  tft.begin();

  tft.setRotation(1);

}

void loop() {

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Show all 48 fonts in centre of screen ( x,y coordinate 240,160)
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  // Where font sizes increase the screen is not cleared as the larger fonts overwrite
  // the smaller one with the background colour.

  // Set text datum to middle centre
  tft.setTextDatum(MC_DATUM);

  // Set text colour to orange with black background
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  
  tft.fillScreen(TFT_BLACK);            // Clear screen
  tft.setFreeFont(FF1);                 // Select the font
  tft.drawString(sFF1, 240, 160, GFXFF);// Print the string name of the font
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF2);
  tft.drawString(sFF2, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF3);
  tft.drawString(sFF3, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF4);
  tft.drawString(sFF4, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF5);
  tft.drawString(sFF5, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF6);
  tft.drawString(sFF6, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF7);
  tft.drawString(sFF7, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF8);
  tft.drawString(sFF8, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF9);
  tft.drawString(sFF9, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF10);
  tft.drawString(sFF10, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF11);
  tft.drawString(sFF11, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF12);
    tft.drawString(sFF12, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF13);
  tft.drawString(sFF13, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF14);
  tft.drawString(sFF14, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF15);
  tft.drawString(sFF15, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF16);
    tft.drawString(sFF16, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF17);
  tft.drawString(sFF17, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF18);
  tft.drawString(sFF18, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF19);
  tft.drawString(sFF19, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF20);
    tft.drawString(sFF20, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF21);
  tft.drawString(sFF21, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF22);
  tft.drawString(sFF22, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF23);
  tft.drawString(sFF23, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF24);
  tft.drawString(sFF24, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF25);
  tft.drawString(sFF25, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF26);
  tft.drawString(sFF26, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF27);
  tft.drawString(sFF27, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF28);
  tft.drawString(sFF28, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF29);
  tft.drawString(sFF29, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF30);
  tft.drawString(sFF30, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF31);
  tft.drawString(sFF31, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF32);
  tft.drawString(sFF32, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF33);
  tft.drawString(sFF33, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF34);
  tft.drawString(sFF34, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF35);
  tft.drawString(sFF35, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF36);
  tft.drawString(sFF36, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF37);
  tft.drawString(sFF37, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF38);
  tft.drawString(sFF38, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF39);
  tft.drawString(sFF39, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF40);
  tft.drawString(sFF40, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF41);
  tft.drawString(sFF41, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF42);
  tft.drawString(sFF42, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF43);
  tft.drawString(sFF43, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF44);
  tft.drawString(sFF44, 240, 160, GFXFF);
  delay(1000);
  
  tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF45);
  tft.drawString(sFF45, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF46);
  tft.drawString(sFF46, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF47);
  tft.drawString(sFF47, 240, 160, GFXFF);
  delay(1000);
  //tft.fillScreen(TFT_BLACK);
  tft.setFreeFont(FF48);
  tft.drawString(sFF48, 240, 160, GFXFF);
  delay(1000);

}

// There follows a crude way of flagging that this example sketch needs fonts which
// have not been enbabled in the User_Setup.h file inside the TFT_HX8357 library.
//
// These lines produce errors during compile time if settings in User_Setup are not correct
//
// The error will be "does not name a type" but ignore this and read the text between ''
// it will indicate which font or feature needs to be enabled
//
// Either delete all the following lines if you do not want warnings, or change the lines
// to suit your sketch modifications.

#ifndef LOAD_GLCD
//ERROR_Please_enable_LOAD_GLCD_in_User_Setup
#endif

#ifndef LOAD_FONT2
//ERROR_Please_enable_LOAD_FONT2_in_User_Setup!
#endif

#ifndef LOAD_FONT4
//ERROR_Please_enable_LOAD_FONT4_in_User_Setup!
#endif

#ifndef LOAD_FONT6
//ERROR_Please_enable_LOAD_FONT6_in_User_Setup!
#endif

#ifndef LOAD_FONT7
//ERROR_Please_enable_LOAD_FONT7_in_User_Setup!
#endif

#ifndef LOAD_FONT8
//ERROR_Please_enable_LOAD_FONT8_in_User_Setup!
#endif

#ifndef LOAD_GFXFF
ERROR_Please_enable_LOAD_GFXFF_in_User_Setup!
#endif

