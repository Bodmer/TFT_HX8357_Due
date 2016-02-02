// Attach this header file to your sketch to use the GFX Free Fonts. You can write
// sketches without it, but it makes referencing them easier.

// This calls up ALL the fonts but they only get loaded if you actually
// use them in your sketch.
//
// No changes are needed to this header file unless new fonts are added to the
// HX8357 library "Fonts/GFXFF" folder.
//
// To save a lot of typing long names, each font can easily be referenced in the
// sketch in two ways, either with:
//
//    1. FF# where # is a number determined by looking at the list below
//       an example being:
//
//       tft.setFreeFont(FF32);
//
//    2. An abbreviation of the file name. Look at the list below to see
//       the abbreviations used, for example:
//
//       tft.setFreeFont(FSSBO24)
//
//       Where the letters mean:
//       F = Free font
//       M = Mono
//      SS = Sans Serif (double S to distinguish is form serif fonts)
//       S = Serif
//       B = Bold
//       O = Oblique (letter O not zero)
//       I = Italic
//       # =  point size, either 9, 12, 18 or 24
//
//  Setting the font to NULL will select the GLCD font:
//
//      tft.setFreeFont(NULL); // Set font to GLCD

// Use these when printing or drawing text in GLCD and high rendering speed fonts (FONT2- FONT8)
#define GFXFF 1
#define GLCD  0
#define FONT2 2
#define FONT4 4
#define FONT6 6
#define FONT7 7
#define FONT8 8


#ifdef LOAD_GFXFF // Only include the fonts if LOAD_GFXFF is defined in User_Setup.h

// Use the followinf when calling setFont()
//
// Reserved for GLCD font  // FF0
//
// Mono spaced fonts
#include <Fonts/GFXFF/FreeMono9pt7b.h>  // FF1 or FM9
#include <Fonts/GFXFF/FreeMono12pt7b.h> // FF2 or FM12
#include <Fonts/GFXFF/FreeMono18pt7b.h> // FF3 or FM18
#include <Fonts/GFXFF/FreeMono24pt7b.h> // FF4 or FM24

#include <Fonts/GFXFF/FreeMonoOblique9pt7b.h>  // FF5 or FMO9
#include <Fonts/GFXFF/FreeMonoOblique12pt7b.h> // FF6 or FMO12
#include <Fonts/GFXFF/FreeMonoOblique18pt7b.h> // FF7 or FMO18
#include <Fonts/GFXFF/FreeMonoOblique24pt7b.h> // FF8 or FMO24

#include <Fonts/GFXFF/FreeMonoBold9pt7b.h>  // FF9  or FMB9
#include <Fonts/GFXFF/FreeMonoBold12pt7b.h> // FF10 or FMB12
#include <Fonts/GFXFF/FreeMonoBold18pt7b.h> // FF11 or FMB18
#include <Fonts/GFXFF/FreeMonoBold24pt7b.h> // FF12 or FMB24

#include <Fonts/GFXFF/FreeMonoBoldOblique9pt7b.h>  // FF13 or FMBO9
#include <Fonts/GFXFF/FreeMonoBoldOblique12pt7b.h> // FF14 or FMBO12
#include <Fonts/GFXFF/FreeMonoBoldOblique18pt7b.h> // FF15 or FMBO18
#include <Fonts/GFXFF/FreeMonoBoldOblique24pt7b.h> // FF16 or FMBO24

// Sans serif fonts
#include <Fonts/GFXFF/FreeSans9pt7b.h>  // FF17 or FSS9
#include <Fonts/GFXFF/FreeSans12pt7b.h> // FF18 or FSS12
#include <Fonts/GFXFF/FreeSans18pt7b.h> // FF19 or FSS18
#include <Fonts/GFXFF/FreeSans24pt7b.h> // FF20 or FSS24

#include <Fonts/GFXFF/FreeSansOblique9pt7b.h>  // FF21 or FSSO9
#include <Fonts/GFXFF/FreeSansOblique12pt7b.h> // FF22 or FSSO12
#include <Fonts/GFXFF/FreeSansOblique18pt7b.h> // FF23 or FSSO18
#include <Fonts/GFXFF/FreeSansOblique24pt7b.h> // FF24 or FSSO24

#include <Fonts/GFXFF/FreeSansBold9pt7b.h>  // FF25 or FSSB9
#include <Fonts/GFXFF/FreeSansBold12pt7b.h> // FF26 or FSSB12
#include <Fonts/GFXFF/FreeSansBold18pt7b.h> // FF27 or FSSB18
#include <Fonts/GFXFF/FreeSansBold24pt7b.h> // FF28 or FSSB24

#include <Fonts/GFXFF/FreeSansBoldOblique9pt7b.h>  // FF29 or FSSBO9
#include <Fonts/GFXFF/FreeSansBoldOblique12pt7b.h> // FF30 or FSSBO12
#include <Fonts/GFXFF/FreeSansBoldOblique18pt7b.h> // FF31 or FSSBO18
#include <Fonts/GFXFF/FreeSansBoldOblique24pt7b.h> // FF32 or FSSBO24

// Serif fonts
#include <Fonts/GFXFF/FreeSerif9pt7b.h>  // FF33 or FS9
#include <Fonts/GFXFF/FreeSerif12pt7b.h> // FF34 or FS12
#include <Fonts/GFXFF/FreeSerif18pt7b.h> // FF35 or FS18
#include <Fonts/GFXFF/FreeSerif24pt7b.h> // FF36 or FS24

#include <Fonts/GFXFF/FreeSerifItalic9pt7b.h>  // FF37 or FSI9
#include <Fonts/GFXFF/FreeSerifItalic12pt7b.h> // FF38 or FSI12
#include <Fonts/GFXFF/FreeSerifItalic18pt7b.h> // FF39 or FSI18
#include <Fonts/GFXFF/FreeSerifItalic24pt7b.h> // FF40 or FSI24

#include <Fonts/GFXFF/FreeSerifBold9pt7b.h>  // FF41 or FSB9
#include <Fonts/GFXFF/FreeSerifBold12pt7b.h> // FF42 or FSB12
#include <Fonts/GFXFF/FreeSerifBold18pt7b.h> // FF43 or FSB18
#include <Fonts/GFXFF/FreeSerifBold24pt7b.h> // FF44 or FSB24

#include <Fonts/GFXFF/FreeSerifBoldItalic9pt7b.h>  // FF45 or FSBI9
#include <Fonts/GFXFF/FreeSerifBoldItalic12pt7b.h> // FF46 or FSBI12
#include <Fonts/GFXFF/FreeSerifBoldItalic18pt7b.h> // FF47 or FSBI18
#include <Fonts/GFXFF/FreeSerifBoldItalic24pt7b.h> // FF48 or FSBI24


#define FM9 &FreeMono9pt7b,FreeMono9pt7bBitmaps,FreeMono9pt7bGlyphs
#define FM12 &FreeMono12pt7b,FreeMono12pt7bBitmaps,FreeMono12pt7bGlyphs
#define FM18 &FreeMono18pt7b,FreeMono18pt7bBitmaps,FreeMono18pt7bGlyphs
#define FM24 &FreeMono24pt7b,FreeMono24pt7bBitmaps,FreeMono24pt7bGlyphs

#define FMB9 &FreeMonoBold9pt7b,FreeMonoBold9pt7bBitmaps,FreeMonoBold9pt7bGlyphs
#define FMB12 &FreeMonoBold12pt7b,FreeMonoBold12pt7bBitmaps,FreeMonoBold12pt7bGlyphs
#define FMB18 &FreeMonoBold18pt7b,FreeMonoBold18pt7bBitmaps,FreeMonoBold18pt7bGlyphs
#define FMB24 &FreeMonoBold24pt7b,FreeMonoBold24pt7bBitmaps,FreeMonoBold24pt7bGlyphs

#define FMO9 &FreeMonoOblique9pt7b,FreeMonoOblique9pt7bBitmaps,FreeMonoOblique9pt7bGlyphs
#define FMO12 &FreeMonoOblique12pt7b,FreeMonoOblique12pt7bBitmaps,FreeMonoOblique12pt7bGlyphs
#define FMO18 &FreeMonoOblique18pt7b,FreeMonoOblique18pt7bBitmaps,FreeMonoOblique18pt7bGlyphs
#define FMO24 &FreeMonoOblique24pt7b,FreeMonoOblique24pt7bBitmaps,FreeMonoOblique24pt7bGlyphs

#define FMBO9 &FreeMonoBoldOblique9pt7b,FreeMonoBoldOblique9pt7bBitmaps,FreeMonoBoldOblique9pt7bGlyphs
#define FMBO12 &FreeMonoBoldOblique12pt7b,FreeMonoBoldOblique12pt7bBitmaps,FreeMonoBoldOblique12pt7bGlyphs
#define FMBO18 &FreeMonoBoldOblique18pt7b,FreeMonoBoldOblique18pt7bBitmaps,FreeMonoBoldOblique18pt7bGlyphs
#define FMBO24 &FreeMonoBoldOblique24pt7b,FreeMonoBoldOblique24pt7bBitmaps,FreeMonoBoldOblique24pt7bGlyphs

#define FSS9 &FreeSans9pt7b,FreeSans9pt7bBitmaps,FreeSans9pt7bGlyphs
#define FSS12 &FreeSans12pt7b,FreeSans12pt7bBitmaps,FreeSans12pt7bGlyphs
#define FSS18 &FreeSans18pt7b,FreeSans18pt7bBitmaps,FreeSans18pt7bGlyphs
#define FSS24 &FreeSans24pt7b,FreeSans24pt7bBitmaps,FreeSans24pt7bGlyphs

#define FSSB9 &FreeSansBold9pt7b,FreeSansBold9pt7bBitmaps,FreeSansBold9pt7bGlyphs
#define FSSB12 &FreeSansBold12pt7b,FreeSansBold12pt7bBitmaps,FreeSansBold12pt7bGlyphs
#define FSSB18 &FreeSansBold18pt7b,FreeSansBold18pt7bBitmaps,FreeSansBold18pt7bGlyphs
#define FSSB24 &FreeSansBold24pt7b,FreeSansBold24pt7bBitmaps,FreeSansBold24pt7bGlyphs

#define FSSO9 &FreeSansOblique9pt7b,FreeSansOblique9pt7bBitmaps,FreeSansOblique9pt7bGlyphs
#define FSSO12 &FreeSansOblique12pt7b,FreeSansOblique12pt7bBitmaps,FreeSansOblique12pt7bGlyphs
#define FSSO18 &FreeSansOblique18pt7b,FreeSansOblique18pt7bBitmaps,FreeSansOblique18pt7bGlyphs
#define FSSO24 &FreeSansOblique24pt7b,FreeSansOblique24pt7bBitmaps,FreeSansOblique24pt7bGlyphs

#define FSSBO9 &FreeSansBoldOblique9pt7b,FreeSansBoldOblique9pt7bBitmaps,FreeSansBoldOblique9pt7bGlyphs
#define FSSBO12 &FreeSansBoldOblique12pt7b,FreeSansBoldOblique12pt7bBitmaps,FreeSansBoldOblique12pt7bGlyphs
#define FSSBO18 &FreeSansBoldOblique18pt7b,FreeSansBoldOblique18pt7bBitmaps,FreeSansBoldOblique18pt7bGlyphs
#define FSSBO24 &FreeSansBoldOblique24pt7b,FreeSansBoldOblique24pt7bBitmaps,FreeSansBoldOblique24pt7bGlyphs

#define FS9 &FreeSerif9pt7b,FreeSerif9pt7bBitmaps,FreeSerif9pt7bGlyphs
#define FS12 &FreeSerif12pt7b,FreeSerif12pt7bBitmaps,FreeSerif12pt7bGlyphs
#define FS18 &FreeSerif18pt7b,FreeSerif18pt7bBitmaps,FreeSerif18pt7bGlyphs
#define FS24 &FreeSerif24pt7b,FreeSerif24pt7bBitmaps,FreeSerif24pt7bGlyphs

#define FSI9 &FreeSerifItalic9pt7b,FreeSerifItalic9pt7bBitmaps,FreeSerifItalic9pt7bGlyphs
#define FSI12 &FreeSerifItalic12pt7b,FreeSerifItalic12pt7bBitmaps,FreeSerifItalic12pt7bGlyphs
#define FSI19 &FreeSerifItalic18pt7b,FreeSerifItalic18pt7bBitmaps,FreeSerifItalic18pt7bGlyphs
#define FSI24 &FreeSerifItalic24pt7b,FreeSerifItalic24pt7bBitmaps,FreeSerifItalic24pt7bGlyphs

#define FSB9 &FreeSerifBold9pt7b,FreeSerifBold9pt7bBitmaps,FreeSerifBold9pt7bGlyphs
#define FSB12 &FreeSerifBold12pt7b,FreeSerifBold12pt7bBitmaps,FreeSerifBold12pt7bGlyphs
#define FSB18 &FreeSerifBold18pt7b,FreeSerifBold18pt7bBitmaps,FreeSerifBold18pt7bGlyphs
#define FSB24 &FreeSerifBold24pt7b,FreeSerifBold24pt7bBitmaps,FreeSerifBold24pt7bGlyphs

#define FSBI9 &FreeSerifBoldItalic9pt7b,FreeSerifBoldItalic9pt7bBitmaps,FreeSerifBoldItalic9pt7bGlyphs
#define FSBI12 &FreeSerifBoldItalic12pt7b,FreeSerifBoldItalic12pt7bBitmaps,FreeSerifBoldItalic12pt7bGlyphs
#define FSBI18 &FreeSerifBoldItalic18pt7b,FreeSerifBoldItalic18pt7bBitmaps,FreeSerifBoldItalic18pt7bGlyphs
#define FSBI24 &FreeSerifBoldItalic24pt7b,FreeSerifBoldItalic24pt7bBitmaps,FreeSerifBoldItalic24pt7bGlyphs

#define FF0 NULL //ff0 reserved for GLCD
#define FF1 &FreeMono9pt7b,FreeMono9pt7bBitmaps,FreeMono9pt7bGlyphs
#define FF2 &FreeMono12pt7b,FreeMono12pt7bBitmaps,FreeMono12pt7bGlyphs
#define FF3 &FreeMono18pt7b,FreeMono18pt7bBitmaps,FreeMono18pt7bGlyphs
#define FF4 &FreeMono24pt7b,FreeMono24pt7bBitmaps,FreeMono24pt7bGlyphs

#define FF5 &FreeMonoBold9pt7b,FreeMonoBold9pt7bBitmaps,FreeMonoBold9pt7bGlyphs
#define FF6 &FreeMonoBold12pt7b,FreeMonoBold12pt7bBitmaps,FreeMonoBold12pt7bGlyphs
#define FF7 &FreeMonoBold18pt7b,FreeMonoBold18pt7bBitmaps,FreeMonoBold18pt7bGlyphs
#define FF8 &FreeMonoBold24pt7b,FreeMonoBold24pt7bBitmaps,FreeMonoBold24pt7bGlyphs

#define FF9 &FreeMonoOblique9pt7b,FreeMonoOblique9pt7bBitmaps,FreeMonoOblique9pt7bGlyphs
#define FF10 &FreeMonoOblique12pt7b,FreeMonoOblique12pt7bBitmaps,FreeMonoOblique12pt7bGlyphs
#define FF11 &FreeMonoOblique18pt7b,FreeMonoOblique18pt7bBitmaps,FreeMonoOblique18pt7bGlyphs
#define FF12 &FreeMonoOblique24pt7b,FreeMonoOblique24pt7bBitmaps,FreeMonoOblique24pt7bGlyphs

#define FF13 &FreeMonoBoldOblique9pt7b,FreeMonoBoldOblique9pt7bBitmaps,FreeMonoBoldOblique9pt7bGlyphs
#define FF14 &FreeMonoBoldOblique12pt7b,FreeMonoBoldOblique12pt7bBitmaps,FreeMonoBoldOblique12pt7bGlyphs
#define FF15 &FreeMonoBoldOblique18pt7b,FreeMonoBoldOblique18pt7bBitmaps,FreeMonoBoldOblique18pt7bGlyphs
#define FF16 &FreeMonoBoldOblique24pt7b,FreeMonoBoldOblique24pt7bBitmaps,FreeMonoBoldOblique24pt7bGlyphs

#define FF17 &FreeSans9pt7b,FreeSans9pt7bBitmaps,FreeSans9pt7bGlyphs
#define FF18 &FreeSans12pt7b,FreeSans12pt7bBitmaps,FreeSans12pt7bGlyphs
#define FF19 &FreeSans18pt7b,FreeSans18pt7bBitmaps,FreeSans18pt7bGlyphs
#define FF20 &FreeSans24pt7b,FreeSans24pt7bBitmaps,FreeSans24pt7bGlyphs

#define FF21 &FreeSansBold9pt7b,FreeSansBold9pt7bBitmaps,FreeSansBold9pt7bGlyphs
#define FF22 &FreeSansBold12pt7b,FreeSansBold12pt7bBitmaps,FreeSansBold12pt7bGlyphs
#define FF23 &FreeSansBold18pt7b,FreeSansBold18pt7bBitmaps,FreeSansBold18pt7bGlyphs
#define FF24 &FreeSansBold24pt7b,FreeSansBold24pt7bBitmaps,FreeSansBold24pt7bGlyphs

#define FF25 &FreeSansOblique9pt7b,FreeSansOblique9pt7bBitmaps,FreeSansOblique9pt7bGlyphs
#define FF26 &FreeSansOblique12pt7b,FreeSansOblique12pt7bBitmaps,FreeSansOblique12pt7bGlyphs
#define FF27 &FreeSansOblique18pt7b,FreeSansOblique18pt7bBitmaps,FreeSansOblique18pt7bGlyphs
#define FF28 &FreeSansOblique24pt7b,FreeSansOblique24pt7bBitmaps,FreeSansOblique24pt7bGlyphs

#define FF29 &FreeSansBoldOblique9pt7b,FreeSansBoldOblique9pt7bBitmaps,FreeSansBoldOblique9pt7bGlyphs
#define FF30 &FreeSansBoldOblique12pt7b,FreeSansBoldOblique12pt7bBitmaps,FreeSansBoldOblique12pt7bGlyphs
#define FF31 &FreeSansBoldOblique18pt7b,FreeSansBoldOblique18pt7bBitmaps,FreeSansBoldOblique18pt7bGlyphs
#define FF32 &FreeSansBoldOblique24pt7b,FreeSansBoldOblique24pt7bBitmaps,FreeSansBoldOblique24pt7bGlyphs

#define FF33 &FreeSerif9pt7b,FreeSerif9pt7bBitmaps,FreeSerif9pt7bGlyphs
#define FF34 &FreeSerif12pt7b,FreeSerif12pt7bBitmaps,FreeSerif12pt7bGlyphs
#define FF35 &FreeSerif18pt7b,FreeSerif18pt7bBitmaps,FreeSerif18pt7bGlyphs
#define FF36 &FreeSerif24pt7b,FreeSerif24pt7bBitmaps,FreeSerif24pt7bGlyphs

#define FF37 &FreeSerifItalic9pt7b,FreeSerifItalic9pt7bBitmaps,FreeSerifItalic9pt7bGlyphs
#define FF38 &FreeSerifItalic12pt7b,FreeSerifItalic12pt7bBitmaps,FreeSerifItalic12pt7bGlyphs
#define FF39 &FreeSerifItalic18pt7b,FreeSerifItalic18pt7bBitmaps,FreeSerifItalic18pt7bGlyphs
#define FF40 &FreeSerifItalic24pt7b,FreeSerifItalic24pt7bBitmaps,FreeSerifItalic24pt7bGlyphs

#define FF41 &FreeSerifBold9pt7b,FreeSerifBold9pt7bBitmaps,FreeSerifBold9pt7bGlyphs
#define FF42 &FreeSerifBold12pt7b,FreeSerifBold12pt7bBitmaps,FreeSerifBold12pt7bGlyphs
#define FF43 &FreeSerifBold18pt7b,FreeSerifBold18pt7bBitmaps,FreeSerifBold18pt7bGlyphs
#define FF44 &FreeSerifBold24pt7b,FreeSerifBold24pt7bBitmaps,FreeSerifBold24pt7bGlyphs

#define FF45 &FreeSerifBoldItalic9pt7b,FreeSerifBoldItalic9pt7bBitmaps,FreeSerifBoldItalic9pt7bGlyphs
#define FF46 &FreeSerifBoldItalic12pt7b,FreeSerifBoldItalic12pt7bBitmaps,FreeSerifBoldItalic12pt7bGlyphs
#define FF47 &FreeSerifBoldItalic18pt7b,FreeSerifBoldItalic18pt7bBitmaps,FreeSerifBoldItalic18pt7bGlyphs
#define FF48 &FreeSerifBoldItalic24pt7b,FreeSerifBoldItalic24pt7bBitmaps,FreeSerifBoldItalic24pt7bGlyphs

#else // LOAD_GFXFF not defined so setup defaults to prevent error messages

// Free fonts are not loaded in User_Setup.h so define as font 1 (GLCD)
// to prevent compile error messages

#define GLCD  1
#define GFXFF  1
#define FF0 1
#define FF1 1
#define FF2 1
#define FF3 1
#define FF4 1
#define FF5 1
#define FF6 1
#define FF7 1
#define FF8 1
#define FF9 1
#define FF10 1
#define FF11 1
#define FF12 1
#define FF13 1
#define FF14 1
#define FF15 1
#define FF16 1
#define FF17 1
#define FF18 1
#define FF19 1
#define FF20 1
#define FF21 1
#define FF22 1
#define FF23 1
#define FF24 1
#define FF25 1
#define FF26 1
#define FF27 1
#define FF28 1
#define FF29 1
#define FF30 1
#define FF31 1
#define FF32 1
#define FF33 1
#define FF34 1
#define FF35 1
#define FF36 1
#define FF37 1
#define FF38 1
#define FF39 1
#define FF40 1
#define FF41 1
#define FF42 1
#define FF43 1
#define FF44 1
#define FF45 1
#define FF46 1
#define FF47 1
#define FF48 1

#define FM9  1
#define FM12 1
#define FM18 1
#define FM24 1

#define FMB9  1
#define FMB12 1
#define FMB18 1
#define FMB24 1

#define FMO9  1
#define FMO12 1
#define FMO18 1
#define FMO24 1

#define FMBO9  1
#define FMBO12 1
#define FMBO18 1
#define FMBO24 1

#define FSS9  1
#define FSS12 1
#define FSS18 1
#define FSS24 1

#define FSSB9  1
#define FSSB12 1
#define FSSB18 1
#define FSSB24 1

#define FSSO9  1
#define FSSO12 1
#define FSSO18 1
#define FSSO24 1

#define FSSBO9  1
#define FSSBO12 1
#define FSSBO18 1
#define FSSBO24 1

#define FS9  1
#define FS12 1
#define FS18 1
#define FS24 1

#define FSI9  1
#define FSI12 1
#define FSI19 1
#define FSI24 1

#define FSB9  1
#define FSB12 1
#define FSB18 1
#define FSB24 1

#define FSBI9  1
#define FSBI12 1
#define FSBI18 1
#define FSBI24 1

#endif // LOAD_GFXFF
