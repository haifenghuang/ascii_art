#ifndef  __ASCII_ART__H 
#define  __ASCII_ART__H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* fontName macros */
#define FONTNAME_BANNER   "banner"
#define chararr_banner    " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

#define FONTNAME_COLOSSAL "colossal"
#define chararr_colossal  " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

#define FONTNAME_UNIVERS  "univers"
#define chararr_univers   " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

#define FONTNAME_BUBBLE   "bubble"
#define chararr_bubble    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

#define FONTNAME_BLOCKS   "blocks"
#define chararr_blocks    "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#%&'()*+,-./:;<=>?@[\\]^_`{|}~"

/* change if you add new sys fonts */
#define MAX_SYSFONTS 5

/* Do not change the value */
enum TERM_COLOR{
  COLOR_NC = 0,
  COLOR_WHITE = 1,
  COLOR_BLACK = 2,
  COLOR_BLUE = 3,
  COLOR_LIGHT_BLUE = 4,
  COLOR_GREEN = 5,
  COLOR_LIGHT_GREEN = 6,
  COLOR_CYAN = 7,
  COLOR_LIGHT_CYAN = 8,
  COLOR_RED = 9,
  COLOR_LIGHT_RED = 10,
  COLOR_PURPLE = 11,
  COLOR_LIGHT_PURPLE = 12,
  COLOR_YELLOW = 13,
  COLOR_LIGHT_YELLOW = 14,
  COLOR_GRAY = 15,
  COLOR_LIGHT_GRAY = 16,

  COLOR_MAX = 17
};

/* typedefs */
typedef struct _AsciiArt AsciiArt;
typedef struct tagASCIIArtAPI{
    /* constructor */
    AsciiArt *(*Create)(void);
    AsciiArt *(*CreateWithFontName)(const char *fontName);

    /* set font to use */
    void (*setFont)(AsciiArt *art, const char *fontName);

    /* render ascii-art 'ascii' using 'color'. */
    /* spearate color using ','. e.g. "1, 2, 4" */
    int  (*render)(AsciiArt *art, const char *ascii, char *color);

    /* regist custom font */
    int  (*registFont)(AsciiArt *art,
                      int nRow, int nCol, 
                      int hasLower, /* not used */
                      const char *charArr,
                      const char ascii[]);

    /* IO: Load from file */
    int (*Load)(AsciiArt *art, const char *filename);

    /* map: map one art's character to art2's character */
    int (*map)(AsciiArt *art, AsciiArt *art2, const char *from, const char *to);
    /* spearate color using ','. e.g. "1, 2, 4" */
    int (*mapRender)(AsciiArt *art, AsciiArt *art2, const char *ascii, char *color);
    void (*clearMap)(AsciiArt *art);

    /* destructor */
    void (*Finalize)(AsciiArt *art);
}ASCIIArtAPI;

extern ASCIIArtAPI iAsciiArt;

#endif
