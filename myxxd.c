#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 67
#define ROW   11
#define COL   20
/* get the ascii-art line from file */
static int getAsciiArt(FILE *fp, long bufsize)
{
  long base, count;
  int i, j, k;

  char *buf = calloc(bufsize + 1, sizeof(char));

  /* Read the entire file into memory. */
  size_t newLen = fread(buf, sizeof(char), bufsize, fp);
  buf[++newLen] = '\0'; /* Just to be safe. */

  count = 0;
  /* get the ascii-art, convert vertical to horizontal. */
  for(i = 0; i < ROW; i++) /* each row */
    {
      for (j = 0; j < TOTAL; j++) /* for the nth char */
        {
          base = (j * ROW * (COL + 1)) + i * (COL + 1);
          for (k = 0; k < COL; k++) /* for each column */
            {
              printf("0x%02X, ", buf[base++]); 
              count++;
              if (count % 20 == 0)
                {
                  printf("\n");
                  count= 0;
                }
            }
        }
      printf("0x0A, ");
      count++;
    } /* end outer for */

  /* add terminator */
  printf("0x0");

  free(buf);
  return 0;
}

static int getProperties(FILE *fp, long bufsize)
{
  char properties[256];


  fgets(properties, sizeof(properties), fp);
  fgets(properties, sizeof(properties), fp);
  fgets(properties, sizeof(properties), fp);

  /* The left line is our ascii-art characters */
  getAsciiArt(fp, bufsize);
  return 0;
}

int main()
{
  FILE *fp = NULL;
  long bufsize = 0L;

  fp = fopen("./Blocks.art", "r");

  /* Get file size */
  /* Go to the end of the file. */
  fseek(fp, 0L, SEEK_END);
  /* Get the size of the file. */
  bufsize = ftell(fp);

  /* Go back to the start of the file. */
  fseek(fp, 0L, SEEK_SET);

  getProperties(fp, bufsize);

  fclose(fp);
  return 0;
}
