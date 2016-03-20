/***************************************************
  Arduino TFT graphics library targetted at the
  Due board, HX8357B/C and ILI9481 display drivers.

  This library has been derived from the Adafruit_GFX
  library and the associated driver library. See text
  at the end of this file.

  This is a standalone library that contains the
  hardware driver, the graphics functions and the
  proportional fonts.

  The larger fonts are Run Length Encoded to reduce
  their FLASH footprint and speed rendering.

 ****************************************************/

// Include header file that defines the fonts loaded and the pins to be used
#include <User_Setup.h>

// These share the same code, only the port writes are affected for the 8 bit interface
#ifdef ILI9481_8BIT
  #define ILI9481
#endif

// Stop fonts etc being loaded multiple times
#ifndef _TFT_HX8357_DueH_
#define _TFT_HX8357_DueH_

// Only load the fonts defined in User_Setup.h (to save space)
// Sets flag so RLE rendering code is optionally compiled

#ifdef LOAD_GLCD
  #include <Fonts/glcdfont.c>
#endif

#ifdef LOAD_FONT2
  #include <Fonts/Font16.h>
#endif

#ifdef LOAD_FONT4
  #include <Fonts/Font32rle.h>
  #define LOAD_RLE
#endif

#ifdef LOAD_FONT6
  #include <Fonts/Font64rle.h>
  #ifndef LOAD_RLE
    #define LOAD_RLE
  #endif
#endif

#ifdef LOAD_FONT7
  #include <Fonts/Font7srle.h>
  #ifndef LOAD_RLE
    #define LOAD_RLE
  #endif
#endif

#ifdef LOAD_FONT8
  #include <Fonts/Font72rle.h>
  #ifndef LOAD_RLE
    #define LOAD_RLE
  #endif
#endif



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#define PROGMEM

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#include <Fonts/GFXFF/gfxfont.h>

// Swap any type
template <typename T> static inline void
swap(T& a, T& b) { T t = a; a = b; b = t; }



//These define the ports and port bits used for the write, chip select (CS) and data/command (RS) lines



#ifndef ILI9481

// Set WR low
  #define WR_L REG_PIOC_CODR = 0x1 << 7

// Set WR high
  #define WR_H REG_PIOC_SODR = 0x1 << 7

// Long write strobe, hold low for two periods then high
// Use in tight loops to avoid too narrow low pulses
  #define WR_STB REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_SODR = 0x1 << 7;

// Short write strobe, hold low for one period then high
// Use where write is already set low during data setup
  #define WR_SB  REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_SODR = 0x1 << 7;

// Chip select must be toggled during setup so these are a special case
  #define SETUP_CS_H REG_PIOC_SODR = 0x1 << 8
  #define SETUP_CS_L REG_PIOC_CODR = 0x1 << 8

// Chip select can optionally be kept low after setup
  #ifndef KEEP_CS_LOW
    #define CS_H REG_PIOC_SODR = 0x1 << 8
    #define CS_L REG_PIOC_CODR = 0x1 << 8
  #else
    #define CS_H // We do not define this so CS will not be set high
    #define CS_L REG_PIOC_CODR = 0x1 << 8 // Play safe here
  #endif

// Change RS line state
  #define RS_L REG_PIOC_CODR = 0x1 << 6
  #define RS_H REG_PIOC_SODR = 0x1 << 6

#else

  #ifdef ILI9481_8BIT

// Set WR low
  #define WR_L REG_PIOA_CODR = 0x1 << 24;

// Set WR high
  #define WR_H REG_PIOA_SODR = 0x1 << 24

// Write strobe low and then high
  #define WR_STB REG_PIOA_CODR = 0x1 << 24; REG_PIOA_CODR = 0x1 << 24; REG_PIOA_CODR = 0x1 << 24;   REG_PIOA_SODR = 0x1 << 24;

// Short write strobe
// Use where write is already set low during data setup
  #define WR_SB  REG_PIOA_CODR = 0x1 << 24; REG_PIOA_CODR = 0x1 << 24; REG_PIOA_SODR = 0x1 << 24;

// Set RD low
  #define RD_L REG_PIOA_CODR = 0x1 << 16

// Set RD high
  #define RD_H REG_PIOA_SODR = 0x1 << 16

// Chip select must be toggled during setup so these are a special case
  #define SETUP_CS_H REG_PIOA_SODR = 0x1 << 22;
  #define SETUP_CS_L REG_PIOA_CODR = 0x1 << 22;

// Chip select can optionally be kept low after setup
  #ifndef KEEP_CS_LOW
    #define CS_H REG_PIOA_SODR = 0x1 << 22;
    #define CS_L REG_PIOA_CODR = 0x1 << 22;
  #else
    #define CS_H // We do not define this so CS will not be set high
    #define CS_L REG_PIOA_CODR = 0x1 << 22; // Play safe here
  #endif

// Change RS line state
  #define RS_L REG_PIOA_CODR = 0x1 << 23
  #define RS_H REG_PIOA_SODR = 0x1 << 23

  #else

// Set WR low
  #define WR_L REG_PIOC_CODR = 0x1 << 7

// Set WR high
  #define WR_H REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_SODR = 0x1 << 7

// The ILI9481 is slower and needs a longer write strobe to avoid spurious pixels
  #define WR_STB REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_SODR = 0x1 << 7;

// Short write strobe, hold low for two periods then high
// Use where write is already set low during data setup
  #define WR_SB REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_CODR = 0x1 << 7;  REG_PIOC_SODR = 0x1 << 7;

// Chip select must be toggled during setup so these are a special case
  #define SETUP_CS_H REG_PIOC_SODR = 0x1 << 8
  #define SETUP_CS_L REG_PIOC_CODR = 0x1 << 8

// Chip select can optionally be kept low after setup
  #ifndef KEEP_CS_LOW
    #define CS_H REG_PIOC_SODR = 0x1 << 8
    #define CS_L REG_PIOC_CODR = 0x1 << 8
  #else
    #define CS_H // We do not define this so CS will not be set high
    #define CS_L REG_PIOC_CODR = 0x1 << 8 // Play safe here
  #endif

// Change RS line state
  #define RS_L REG_PIOC_CODR = 0x1 << 6
  #define RS_H REG_PIOC_SODR = 0x1 << 6

  #endif

#endif



// These register enumerations are not all used, but kept for possible future use
#define HX8357D_XXX 0xD
#define HX8357B_XXX 0xB

#define HX8357_NOP     0x00
#define HX8357_SWRESET 0x01
#define HX8357_RDDID   0x04
#define HX8357_RDDST   0x09

#define HX8357_RDPOWMODE  0x0A
#define HX8357_RDMADCTL  0x0B
#define HX8357_RDCOLMOD  0x0C
#define HX8357_RDDIM  0x0D
#define HX8357_RDDSDR  0x0F

#define HX8357_SLPIN   0x10
#define HX8357_SLPOUT  0x11
#define HX8357B_PTLON   0x12
#define HX8357B_NORON   0x13

#define HX8357_INVOFF  0x20
#define HX8357_INVON   0x21
#define HX8357_DISPOFF 0x28
#define HX8357_DISPON  0x29

#define HX8357_CASET   0x2A
#define HX8357_PASET   0x2B
#define HX8357_RAMWR   0x2C
#define HX8357_RAMRD   0x2E

#define HX8357B_PTLAR   0x30
#define HX8357_TEON  0x35
#define HX8357_TEARLINE  0x44
#define HX8357_MADCTL  0x36
#define HX8357_COLMOD  0x3A

#define HX8357_SETOSC 0xB0
#define HX8357_SETPWR1 0xB1
#define HX8357B_SETDISPLAY 0xB2
#define HX8357_SETRGB 0xB3
#define HX8357D_SETCOM  0xB6

#define HX8357B_SETDISPMODE  0xB4
#define HX8357D_SETCYC  0xB4
#define HX8357B_SETOTP 0xB7
#define HX8357D_SETC 0xB9

#define HX8357B_SET_PANEL_DRIVING 0xC0
#define HX8357D_SETSTBA 0xC0
#define HX8357B_SETDGC  0xC1
#define HX8357B_SETID  0xC3
#define HX8357B_SETDDB  0xC4
#define HX8357B_SETDISPLAYFRAME 0xC5
#define HX8357B_GAMMASET 0xC8
#define HX8357B_SETCABC  0xC9
#define HX8357_SETPANEL  0xCC


#define HX8357B_SETPOWER 0xD0
#define HX8357B_SETVCOM 0xD1
#define HX8357B_SETPWRNORMAL 0xD2

#define HX8357B_RDID1   0xDA
#define HX8357B_RDID2   0xDB
#define HX8357B_RDID3   0xDC
#define HX8357B_RDID4   0xDD

#define HX8357D_SETGAMMA 0xE0

#define HX8357B_SETGAMMA 0xC8
#define HX8357B_SETPANELRELATED  0xE9

// Class member functions and variables
class TFT_HX8357_Due

 : public Print // Invoke the print class so tft.print(...) and tft.println(...) are supported

{

 public:

  TFT_HX8357_Due(int16_t _W = HX8357_TFTWIDTH, int16_t _H = HX8357_TFTHEIGHT);

  void     init(void), begin(void), // Same - begin included for backwards compatibility

           drawPixel(uint16_t x, uint16_t y, uint16_t color),

           drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t font),
           setWindow(int16_t x0, int16_t y0, int16_t x1, int16_t y1),

           pushColor(uint16_t color),
           pushColor(uint16_t color, uint16_t len),

           pushColors(uint16_t *data, uint8_t  len),
           pushColors(uint8_t  *data, uint16_t len),
           pushColor16(uint16_t *data, uint16_t len),

           fillScreen(uint16_t color),

           drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),
           drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
           drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),

           drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
           fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
           drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color),
           fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color),

           setRotation(uint8_t r),
           invertDisplay(boolean i),

           drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
           drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color),
           fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
           fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color),

           drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color),
           fillEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color),

           drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color),
           fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color),

           drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color),

           setCursor(int16_t x, int16_t y),
           setCursor(int16_t x, int16_t y, uint8_t font),
           setTextColor(uint16_t color),
           setTextColor(uint16_t fgcolor, uint16_t bgcolor),
           setTextSize(uint8_t size),
           setTextFont(uint8_t font),
           setTextWrap(boolean wrap),
           setTextDatum(uint8_t datum),
           setTextPadding(uint16_t x_width),

#ifdef LOAD_GFXFF
           setFreeFont(const GFXfont *f = NULL, const uint8_t *glyphBitmap = 0, const GFXglyph *glyphTable = 0),
           //setTextFont(const GFXfont *f = NULL, const uint8_t *glyphBitmap = 0, const GFXglyph *glyphTable = 0),
#else
           setFreeFont(uint8_t font),
#endif

           writecommand(uint8_t c),
           writedata(uint8_t d),
           fgColor(uint16_t),
           bgColor(uint16_t),
           fgWrite(void),
           bgWrite(void),
           addrCmd(uint8_t cmd),
           caset(void),
           paset(void),
           ramwr(void),
           commandList(const uint8_t *addr);

  uint8_t  getRotation(void);

  uint16_t fontsLoaded(void),
           color565(uint8_t r, uint8_t g, uint8_t b);

  int16_t  drawChar(uint16_t uniCode, int16_t x, int16_t y, int16_t font),
           drawNumber(int32_t long_num,int16_t poX, int16_t poY, int16_t font),
           drawFloat(float floatNumber,int16_t decimal,int16_t poX, int16_t poY, int16_t font),

           drawString(char *string, int16_t poX, int16_t poY, int16_t font),
           drawCentreString(char *string, int16_t dX, int16_t poY, int16_t font),
           drawRightString(char *string, int16_t dX, int16_t poY, int16_t font),

           height(void),
           width(void),
           textWidth(char *string, int16_t font),
           fontHeight(int16_t font);

  virtual  size_t write(uint8_t);

 private:
    // Sketches should use setWindow(...) instead of this one
    void  setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

    void  write16(uint16_t word);
    void  lo_byte(uint16_t lo);
    void  lo_byte1(void);
    void  lo_byte2(void);
    void  plo_byte1(uint16_t lo);
    void  plo_byte2(uint16_t lo);
  uint8_t  tabcolor;

 protected:

  int16_t  _width, _height,           // Display w/h as modified by current rotation
           cursor_x, cursor_y, padX;  // Text cursor position and width padding

  uint16_t textcolor, textbgcolor,
           pixelfg, pixelbg,          // Pixel colours pre-computed
           fontsloaded;
  uint32_t glyphBitmap, glyphTable;

  uint32_t fgA, fgB, fgC, fgD, bgA, bgB, bgC, bgD; // Pre-computed colour bit patterns
  uint32_t lo1A, lo1B, lo1C, lo1D, lo2A, lo2B, lo2C, lo2D; // Pre-computed byte bit patterns
  uint8_t  glyph_ab,  // glyph height above baseline
           glyph_bb,  // glyph height below baseline
           textfont,  // Current selected font
           textsize,  // Current font size multiplier
           textdatum, // Text reference datum
           rotation;  // Display rotation (0-3)

  int8_t   _cs, _rs, _rst, _wr, _fcs; // Control lines

  boolean  textwrap; // If set, 'wrap' text at right edge of display

#ifdef LOAD_GFXFF
  GFXfont
    *gfxFont;
#endif

};

#endif

/***************************************************

  ORIGINAL LIBRARY HEADER

  This is our library for the Adafruit  HX8357 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
