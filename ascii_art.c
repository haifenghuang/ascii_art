#include <string.h>
#include <stdlib.h>

#include "ascii_art.h"
#include "fonts.h"
/* #include "locale.h" */

/* font file magic */
#define FONT_MAGIC  "art10"

#define FREE(x) {if((x)) { free((void *)(x)); (x) = NULL;}}


static const char *TermColors[]={
    "\033[0m",
    "\033[1;37m",
    "\033[0;30m",
    "\033[0;34m",
    "\033[1;34m",
    "\033[0;32m",
    "\033[1;32m",
    "\033[0;36m",
    "\033[1;36m",
    "\033[0;31m",
    "\033[1;31m",
    "\033[0;35m",
    "\033[1;35m",
    "\033[0;33m",
    "\033[1;33m",
    "\033[1;30m",
    "\033[0;37m",
};

typedef struct _mapInfo{
    char src;
    char dest;
    int  destIdx; /* not used now */
}mapInfo;

struct _AsciiArt
{
  char *fontName;
  char *chararr;
  char *ascii;
  int nRow, nCol;
  int hasLower;

  /* for Load */
  int iLoad;
  char *loadFn; /* Fn: file name */

  /* for mapping font */
  int iMapped; /* is mapped? */

  mapInfo *mapInfo;
  int nMapInfoCount; /* mapInfo's count */
};

static struct _AsciiArt asciiTable[MAX_SYSFONTS];

/* forward declaration */
static AsciiArt *isSysFont(const char *);
static void initAsciiTable(void);
static AsciiArt *Create(void);
static void setFont(AsciiArt *, const char *);
static AsciiArt *CreateWithFontName(const char *);
static int registFont(AsciiArt *, int, int, int, const char *, const char *);
static int getAsciiArt(AsciiArt *, FILE *, int, long);
static int getProperties(AsciiArt *, FILE *, long);
static int Load(AsciiArt *, const char *);
static void freeLoad(AsciiArt *);
static int render(AsciiArt *, const char *, char *);
static int map(AsciiArt *, AsciiArt *, const char *, const char *);
static void getCharInfo(AsciiArt *, AsciiArt *, char, int *, int *);
static int mapRender(AsciiArt *, AsciiArt *, const char *, char *);
static void clearMap(AsciiArt *);
static void Finalize(AsciiArt *);


static AsciiArt *isSysFont(const char *fontName)
{
  int i = 0;
  int sysFontLen = sizeof(asciiTable)/sizeof(asciiTable[0]);

  if (NULL == fontName || '\0' == *fontName) return NULL;

  for (i = 0; i < sysFontLen; i++)
    {
      if (!strcmp(fontName, asciiTable[i].fontName))
          return &asciiTable[i];
    } /* end for */

  return NULL;
}

static void initAsciiTable()
{
  asciiTable[0].fontName = FONTNAME_BANNER;
  asciiTable[0].nRow = 8;
  asciiTable[0].nCol = 8;
  asciiTable[0].hasLower = 0;
  asciiTable[0].chararr = (char *)chararr_banner;
  asciiTable[0].ascii = (char *)banner_ascii;
  asciiTable[0].iLoad = 0;

  asciiTable[1].fontName = FONTNAME_COLOSSAL;
  asciiTable[1].nRow = 8;
  asciiTable[1].nCol = 14;
  asciiTable[1].hasLower = 1;
  asciiTable[1].chararr = (char *)chararr_colossal;
  asciiTable[1].ascii = (char *)colossal_ascii;
  asciiTable[1].iLoad = 0;

  asciiTable[2].fontName = FONTNAME_UNIVERS;
  asciiTable[2].nRow = 8;
  asciiTable[2].nCol = 17;
  asciiTable[2].hasLower = 1;
  asciiTable[2].chararr = (char *)chararr_univers;
  asciiTable[2].ascii = (char *)univers_ascii;
  asciiTable[2].iLoad = 0;

  asciiTable[3].fontName = FONTNAME_BUBBLE;
  asciiTable[3].nRow = 4;
  asciiTable[3].nCol = 6;
  asciiTable[3].hasLower = 1;
  asciiTable[3].chararr = (char *)chararr_bubble;
  asciiTable[3].ascii = (char *)bubble_ascii;
  asciiTable[3].iLoad = 0;

  asciiTable[4].fontName = FONTNAME_BLOCKS;
  asciiTable[4].nRow = 11;
  asciiTable[4].nCol = 20;
  asciiTable[4].hasLower = 0;
  asciiTable[4].chararr = (char *)chararr_blocks;
  asciiTable[4].ascii = (char *)blocks_ascii;
  asciiTable[4].iLoad = 0;

  return;
}

static AsciiArt *Create()
{
  AsciiArt *result = NULL;

  result = calloc(1, sizeof(AsciiArt));
  if (NULL == result)
    {
      fprintf(stderr, "Malloc failed in Create().\n");
      return NULL;
    }

  initAsciiTable();

  return result;
}

static void setFont(AsciiArt *art, const char *fontName)
{
  if (NULL == art) return;
  if (NULL == fontName || '\0' == *fontName)
      return;

  if (NULL != art->fontName && strcmp(art->fontName, fontName)) /* not equal */
      freeLoad(art);

  AsciiArt *sysArt = isSysFont(fontName);

  if (sysArt)
    {
      memcpy(art, sysArt, sizeof(AsciiArt));
    }
  else
    {
      art->fontName = (char *)fontName;
      /* you need to call registFont() function to regist custom font */
    }
}

static AsciiArt *CreateWithFontName(const char *fontName)
{
  AsciiArt *result = Create();
  if (NULL == result)
      return NULL;

  setFont(result, fontName);
  return result;

}

static int registFont(AsciiArt *art,
                      int nRow, int nCol,
                      int hasLower,
                      const char *chararr,
                      const char ascii[])
{
  if (NULL == art) return 1;

  if (NULL == art->fontName || '\0' == *art->fontName)
    {
      fprintf(stderr, "Please set fontName using setFont() function!\n");
      return 1;
    }

  art->nRow = nRow;
  art->nCol = nCol;
  art->hasLower = hasLower;
  art->chararr = (char *)chararr;
  art->ascii = (char *)ascii;

  return 0;
}

/* get the ascii-art line from file */
static int getAsciiArt(AsciiArt *art, FILE *fp, int iDirection, long bufsize)
{
  long base, count;
  int i, j, k;
  int iLen, iTotalLine, iLineNo, iCheckLen;
  char artLine[4096]; /* enough ? */

  iLen = (int)strlen(art->chararr);

  FREE(art->ascii);
  art->ascii = calloc(bufsize + 1, sizeof(char));
  if (NULL == art->ascii)
    {
      fprintf(stderr, "Malloc 'ascii' failed\n");
      FREE(art->chararr);
      return 1;
    }

  /* ascii-art line */
  if (0 == iDirection) /* horizontal */
    {
      j = 0;
      iLineNo = 4; /* ascii-art line is started From 4. */

      /* every line must be equal to this length. */
      iCheckLen = art->nCol * iLen + 1;
      iTotalLine = iLineNo + art->nRow;

      memset(artLine, 0x00, sizeof(artLine));
      while (NULL != fgets(artLine, sizeof(artLine), fp))
        {
          int iArtLineLength = (int)strlen(artLine);
          /* check line length */
          if (iLineNo < iTotalLine && iCheckLen != iArtLineLength)
            {
              fprintf(stderr,
                  "ascii-art line[%d] length not valid, expected:[%d], real:[%d]\n",
                  iLineNo, iCheckLen, iArtLineLength);

              FREE(art->ascii);
              return 1;
            }

          /* loop for each character */
          for(i = 0; i < iArtLineLength ; i++)
            {
              art->ascii[j] = artLine[i];
              j++;
            } /* end for */
          memset(artLine, 0x00, sizeof(artLine));
          iLineNo++;
        } /* end while */

      /* add terminator */
      art->ascii[++j] = 0x0;
    }
  else /* Vertical */
    {
      char *buf = NULL;
      buf = calloc(bufsize + 1, sizeof(char));
       if (NULL == buf)
         {
           fprintf(stderr, "Malloc 'ascii' failed\n");
           FREE(art->chararr);
           FREE(art->ascii);
           return 1;
         }

      /* Read the entire file into memory. */
      size_t newLen = fread(buf, sizeof(char), bufsize, fp);
      if (newLen == 0)
        {
          fprintf(stderr, "Error reading file");
          FREE(art->chararr);
          FREE(art->ascii);
          return 1;
        }

      buf[++newLen] = '\0'; /* Just to be safe. */

      count = 0;
      /* get the ascii-art, convert vertical to horizontal. */
      for(i = 0; i < art->nRow; i++) /* each row */
        {
          for (j = 0; j < iLen; j++) /* for the nth char */
            {
              base = (j * art->nRow * (art->nCol + 1)) + i * (art->nCol + 1);
              for (k = 0; k < art->nCol; k++) /* for each column */
                  art->ascii[count++] = buf[base++];
            }
          art->ascii[count++] = 0x0A; /* add a new line character */
        } /* end outer for */

      /* add terminator */
      art->ascii[++count] = 0x0;

      FREE(buf);
    }

  return 0;
}

/* get char properties from file */
/* TODO: need more check */
static int getProperties(AsciiArt *art, FILE *fp, long bufsize)
{
  char *tmp = NULL;
  int nProp = 0;
  int i, iLen;
  int iDirection = 0;
  int iTotalCount = 0;

  char magic[8];
  char fontName[32];
  char chararr[256];
  char properties[256];

  /* no need to checkk art pointer, because
   * Load() function has alread checked it.
   * */
  /*if (NULL == art) return 1; */

  /* first line is a comment, skip */
  fgets(properties, sizeof(properties), fp);

  /* second line is properties */
  memset(properties, 0x00, sizeof(properties));
  fgets(properties, sizeof(properties), fp);
  properties[sizeof(properties) - 1] = '\0';

  tmp = strtok(properties, " ");
  while (NULL !=  tmp)
    {
      switch(nProp) {
        case 0:
          memset(magic, 0x00, sizeof(magic));
          strncpy(magic, tmp, sizeof(magic)-1);
          magic[sizeof(magic) - 1] = '\0';

          if (strcmp(magic, FONT_MAGIC)) /* not equal */
              return 1;
          break;

        case 1:
          memset(fontName, 0x00, sizeof(fontName));
          strncpy(fontName, tmp, sizeof(fontName)-1);
          fontName[sizeof(fontName) - 1] = '\0';
          break;

        case 2:
          iTotalCount = atoi(tmp); /* check, check, check */
          break;

        case 3:
          art->nRow = atoi(tmp); /* check, check, check */
          break;

        case 4:
          art->nCol = atoi(tmp); /* check, check, check */
          break;

        case 5:
          iDirection = atoi(tmp); /* check, check, check */
          break;

        default:
          break;

      } /* end switch */

      nProp++;
      tmp = strtok(NULL, " ");
    } /* end while */

  /* third line is chararr name.
   * any value is ok, but do not duplicate.
   * value's length is number of chars.
   * */
  memset(chararr, 0x00, sizeof(chararr));
  memset(properties, 0x00, sizeof(properties));
  fgets(properties, sizeof(properties), fp);
  properties[sizeof(properties) - 1] = '\0';

  strncpy(chararr, properties, sizeof(chararr) - 1);
  chararr[sizeof(chararr) - 1] = '\0';

  /* remove trailing space */
  iLen = (int)strlen(chararr);
  i = iLen;
  while(i > 0)
    {
      if (' ' == chararr[i] || '\n' == chararr[i] || '\r' == chararr[i])
          chararr[i] = '\0';
      i--;
    } /* end while */

  iLen = (int)strlen(chararr);
  if (0 == iLen || iLen != iTotalCount)
    {
      fprintf(stderr,
          "file content invalid totalCharCount:[%d], chararr len:[%d]\n",
          iTotalCount, iLen);
      return 1;
    }

  /* chararr */
  FREE(art->chararr);
  art->chararr = calloc(1, (iLen + 1) * sizeof(char));
  if (NULL == art->chararr)
    {
      fprintf(stderr, "Malloc 'chararr' failed\n");
      return 1;
    }
  strcpy(art->chararr, chararr);


#if 0
  printf("chararr=[%s], len=[%d]\n", chararr, iLen);
#endif

  /* The left line is our ascii-art characters */
  i = getAsciiArt(art, fp, iDirection, bufsize);
  if (0 != i)
    {
      FREE(art->ascii);
      FREE(art->chararr);
      return 1;
    }

  /* fontName */
  FREE(art->fontName);
  iLen = (int)strlen(fontName);
  art->fontName = calloc (1, (iLen + 1) * sizeof(char));
  if (NULL == art->fontName)
    {
      fprintf(stderr, "Malloc 'fontName' failed\n");
      FREE(art->ascii);
      FREE(art->chararr);

      return 1;
    }

  strcpy(art->fontName, fontName);
  art->hasLower = 0;

  return 0;
}

static void freeLoad(AsciiArt *art)
{
  if (NULL == art) return;

  if (!art->iLoad)
    {
      art->fontName = NULL;
      art->ascii = NULL;
      art->chararr = NULL;

      return;
    }

  FREE(art->fontName);
  FREE(art->chararr);
  FREE(art->ascii);
  FREE(art->loadFn);

  art->iLoad = 0;
}

static int Load(AsciiArt *art, const char *filename)
{
  FILE *fp = NULL;
  int iResult;
  long bufsize = 0L;

  if (NULL == art) return 1;
  if (NULL == filename || '\0' == *filename) return 1;

  if (NULL != art->loadFn && !strcmp(art->loadFn, filename)) /* same file load again */
      return 0;

  art->loadFn = calloc(1, strlen(filename + 1) * sizeof(char));
  if (NULL == art->loadFn)
    {
      fprintf(stderr, "Malloc filename[%s] buffer failed!\n", filename);
      return 1;
    }
  strcpy(art->loadFn, filename);

  fp = fopen(filename, "r");
  if (NULL == fp)
    {
      fprintf(stderr, "file [%s] open failed!\n", filename);
      FREE(art->loadFn);
      return 1;
    }

    /* Get file size */
    /* Go to the end of the file. */
    fseek(fp, 0L, SEEK_END);
    /* Get the size of the file. */
    bufsize = ftell(fp);

    /* Go back to the start of the file. */
    fseek(fp, 0L, SEEK_SET);

  /* must free used, then getProperties */
  freeLoad(art);

  iResult = getProperties(art, fp, bufsize);
  if (0 != iResult) /* reading file contents error */
    {
      FREE(art->loadFn);
      fclose(fp);
      return iResult;
    }

  art->iLoad = 1;

  fclose(fp);
  return 0;
}

static int *createColorMapping(const char *ascii, char *color)
{
  int *out;
  char *token = NULL;
  int iAsciiLen, iColorLen, iOutLen;
  int nCount = 0;
  int i;
  char *sColor = NULL;

  iAsciiLen = (int)strlen(ascii);
  iColorLen = (int)strlen(color);
  iOutLen = (iAsciiLen > iColorLen) ? iAsciiLen : iColorLen;

  out = calloc(iOutLen + 1, sizeof(int));
  if (NULL == out)
    {
      fprintf(stderr, "Malloc ColorMapping failed!\n");
      return NULL;
    }

  sColor = calloc(iOutLen + 1, sizeof(char));
  if (NULL == sColor)
    {
      free(out);
      fprintf(stderr, "Malloc ColorMapping failed!\n");
      return NULL;
    }
  strcpy(sColor, color);

  /* MacosX: bus error, very strange. */
  /* while ((token = strsep(&color, ",")) != NULL)  */
  
  while ((token = strsep(&sColor, ",")) != NULL)
    {
      i = atoi(token);
      if (i < 0 || i >= COLOR_MAX) i = 0;
      out[nCount++] = i;
    }

    if (iAsciiLen - nCount >= 0) 
        for (i = nCount; i < iAsciiLen; i++) out[i] = 0;

  free(sColor);

  return out;
}

static int render(AsciiArt *art, const char *ascii, char *color)
{
  char *tmpAscii = NULL;
  int *colorMapping = NULL;

  int i, j, k;
  int iFound = 0;

  if (NULL == art) return 1;
  if (NULL == art->ascii || NULL == art->chararr) return 1;

  int jLen = (int)strlen(art->chararr);
  if (jLen == 0) return 1;

  if (NULL == ascii || '\0' == *ascii) /* print all ascii-art */
      tmpAscii = art->chararr;
  else
    {
      /* check all the ascii exists in art->chararr */
      tmpAscii = (char *)ascii;

      for (j = 0; j < strlen(ascii); j++)
        {
          if (NULL == strchr(art->chararr, ascii[j]))
            {
              fprintf(stderr, "char<%c> not found in ascii-art!\n", ascii[j]);
              return 1;
            }
        } /* end outer for */
    }

  const char* ptr = art->ascii;
  int iLen = (int)strlen(tmpAscii);

  int *charIdx = malloc(iLen * sizeof(int));
  if (charIdx == NULL)
    {
      fprintf(stderr, "Malloc 'charIdx' failed\n");
      return 1;
    }

  /* search for each printed ascii char in ascii-art,
   * find it's index, and save to charIdx[]. */
  for (i = 0; i < iLen; i++)
    {
      for (j = 0; j < jLen; j++)
        {
          if (tmpAscii[i] == art->chararr[j])
            {
              iFound = 1;
              break;
            }
        } /* end inner for */
      charIdx[i] = j;
#if 0
      /* debug */
      printf("charIdx[%d]=[%d]\n", i, j);
#endif
    } /* end outer for */

  /* the printed ascii character is not found in ascii-art. */
  if (!iFound)
    {
      fprintf(stderr, "char array not found\n");
      FREE(charIdx);
      return 1;
    }

  if (NULL == color || 0 == *color)
     colorMapping = NULL;
  else
    {
      colorMapping = createColorMapping(tmpAscii, color);
      if (!colorMapping)
        {
          FREE(charIdx);
          return 1;
        }
    }

  /* print the ascii-art character */
  for (k = 0; k < art->nRow; k++) /* for each row */
    {
      for (i = 0; i < iLen; i++) /* for each char */
        {
          ptr = art->ascii; /* reset */
          ptr += k * (jLen * art->nCol + 1); /* to next line. +1: for newline */
          ptr += charIdx[i] * art->nCol;  /* to next line char column index */
          for (j = 0; j < art->nCol; j++)
            {
              if (NULL == colorMapping)
                  printf("%c", *ptr++);
              else
                  printf("%s%c%s", TermColors[colorMapping[i]], *ptr++, TermColors[0]);
            } /* end for */

        } /* end inner for */

      printf("\n");
    } /* end outer for */

  FREE(colorMapping);

  FREE(charIdx);
  return 0;
}

/* NOTE:
 *  You must make sure that 'art' contains "from", 'art2' contains 'to',
 *  This function will not check it for you.
 *
 * TODO:
 *   Need more check
 * */
static int map(AsciiArt *art, AsciiArt *art2, const char *from, const char *to)
{
  char *toCharPtr = NULL;
  int i, j;
  int iLenFrom, iLenTo;

  /*=================================================
   *     CHECK, CHECK, CHECK, God please help me!
   *=================================================
   */
  if (NULL == art || NULL == art2)
    {
      /* do nothing, just return */
      return 1;
    }

  if (art == art2)  /* map with self? */
    {
      fprintf(stderr, "map with youself?\n");
      return 1;
    }

  if (art->nRow != art2->nRow || art->nCol != art2->nCol)
    {
      fprintf(stderr, "art's row-column is not equal to art2's.\n");
      return 1;
    }

  if (NULL == art->fontName || '\0' == *art->fontName)
    {
      fprintf(stderr, "You must set 'art' fontName first .\n");
      return 1;
    }

  if (NULL == art2->fontName || '\0' == *art2->fontName)
    {
      fprintf(stderr, "You must set 'art2' fontName first .\n");
      return 1;
    }

  if (NULL == from) /* map all art's chararr to art2's chararr */
    {
      /* 'to' parameter will be ignored */

      iLenFrom = (int)strlen(art->chararr);
      iLenTo = (int)strlen(art2->chararr);
      if (iLenFrom != iLenTo)
        {
          fprintf(stderr, "art's chararr length not equal to art2's chararr length.\n");
          return 1;
        }

      toCharPtr = art2->chararr;
    }
  else if ('\0' == *from)
    {
      fprintf(stderr, "'from' length is zero.\n");
      return 1;
    }
  else /* 'from' contains character */
    {
      iLenFrom = (int)strlen(from);
      if (NULL == to || '\0' == *to)
        {
          iLenTo = iLenFrom;
          toCharPtr = (char *)from; /* map art's "abc" to art2's "abc" */
        }
      else
        {
          iLenTo = (int)strlen(to);
          toCharPtr = (char *)to;
        }

      if (iLenTo != iLenFrom)
        {
          fprintf(stderr, "'from' length is not equal to 'to' length .\n");
          return 1;
        }
    }

  art->mapInfo = calloc(iLenFrom, sizeof(mapInfo));
  if (NULL == art->mapInfo)
    {
      fprintf(stderr, "Malloc failed in map().\n");
      return 1;
    }
  art->nMapInfoCount = iLenFrom;

  /* map all */
  if (toCharPtr == art2->chararr)
    {
      for (i = 0; i < iLenFrom; i++)
        {
          art->mapInfo[i].src = from[i];
          art->mapInfo[i].dest = to[i];
          art->mapInfo[i].destIdx = i;
        } /* end for */

      /* return early */
      art->iMapped = 1;
      return 0;
    }

  for (i = 0; i < iLenFrom; i++)
    {
      art->mapInfo[i].src = from[i];
      art->mapInfo[i].dest = toCharPtr[i];
#if 0
printf("map: src[%c]===>dest[%c]\n", from[i], toCharPtr[i]);
#endif
      for (j = 0; j < strlen(art2->chararr); j++)
        {
          if ( toCharPtr[i] == art2->chararr[j])
            {
              art->mapInfo[i].destIdx = j;
              break;
            }
        } /* end inner for */
    } /* end outer for */

  art->iMapped = 1;
  return 0;
}

/* check 'c' is in art/art2? and return it's charIdx in art/art2. */
static void getCharInfo(AsciiArt *art, AsciiArt *art2, char c,
                        int *inWhichArt, int *charIdx)
{
  AsciiArt *tmpArt = NULL;
  int i;
  int iCharArrLen;

  char tmpC;

  /* check char is in which art */
  *inWhichArt = 1;
  tmpArt = art;
  iCharArrLen = (int)strlen(art->chararr);
  tmpC = c;

  for (i = 0; i < art->nMapInfoCount; i++)
    {
      if (c == art->mapInfo[i].src)
        {
          *inWhichArt = 2; /* char is in art2 */
          tmpC = art->mapInfo[i].dest;
          tmpArt = art2;
          iCharArrLen = (int)strlen(art2->chararr);
          break;
        }
    } /* end for */

  /* check char's index in art/art2. */
  for (i = 0; i < iCharArrLen; i++)
    {
      if (tmpC == tmpArt->chararr[i])
        {
          *charIdx = i;
          break;
        }
    } /* end for */
}

static int mapRender(AsciiArt *art, AsciiArt *art2, const char *ascii, char *color)
{
  const char* ptr = NULL;
  int *colorMapping = NULL;
  int inWhichArt;
  int charIdx;

  int iResult;
  int i, j, k;

  int iLen, jLen = 0;
  int nRow, nCol;

  if (NULL == art)
    {
      /* do nothing, just return */
      return 1;
    }

  if (NULL == ascii || '\0' == *ascii) /* print all ascii-art character */
    {
      /* print with mapping, here we only use art2, not art. */
      iResult = render(art2, NULL, color);
      return iResult;
    }

  if (art == art2 || NULL == art2 || NULL == art->mapInfo)
    {
      /* print without mapping, here we noly use art, not art2 */
      iResult = render(art, ascii, color);
      return iResult;
    }

  if (0 == art->iMapped)  /* clearMap() has been called */
    {
      iResult = render(art, ascii, color);
      return iResult;
    };

  if (NULL == color || 0 == *color)
     colorMapping = NULL;
  else
    {
      colorMapping = createColorMapping(ascii, color);
      if (!colorMapping)
        {
          return 1;
        }
    }

  /* print the ascii-art character */
  iLen = (int)strlen(ascii);
  nRow = art->nRow;
  nCol = art->nCol;
  for (k = 0; k < nRow; k++) /* for each row */
    {
      inWhichArt = 0;
      charIdx = 0;
      for (i = 0; i < iLen; i++) /* for each char */
        {
          getCharInfo(art, art2, ascii[i], &inWhichArt, &charIdx);
          if (inWhichArt == 2) /* in art2 */
            {
              ptr = art2->ascii; /* reset */
              jLen = (int)strlen(art2->chararr);
            }
          else if (inWhichArt == 1) /* in art */
            {
              ptr = art->ascii; /* reset */
              jLen = (int)strlen(art->chararr);
            }

          ptr += k * (jLen * nCol + 1); /* to next line. +1: for newline */
          ptr += charIdx * nCol;  /* to next line char column index */

          for (j = 0; j < nCol; j++)
            {
              if (NULL == colorMapping)
                  printf("%c", *ptr++);
              else
                  printf("%s%c%s", TermColors[colorMapping[i]], *ptr++, TermColors[0]);
            }
        } /* end inner for */

      printf("\n");
    } /* end outer for */

  FREE(colorMapping);
  return 0;
}

static void clearMap(AsciiArt *art)
{
  if (NULL == art) return;
  if (0 == art->iMapped) return;

  /* free mapInfo */
  FREE(art->mapInfo);

  art->iMapped = 0;
}

static void Finalize(AsciiArt *art)
{
  if (NULL == art) return;

  freeLoad(art);
  clearMap(art);

  /* Caution: do not use FREE macro, because
   * it is a pointer, not double pointer. */
  if (NULL != art) free((void *)art);
}

ASCIIArtAPI iAsciiArt = {
    Create,
    CreateWithFontName,
    setFont,
    render,
    registFont,
    Load,
    map,
    mapRender,
    clearMap,
    Finalize,
};

