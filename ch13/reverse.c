/* reverse.c -- displays a file in reverse order */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'       // EOF marker in DOS text files
#define SLEN 50

int main(void)
{
  char file[SLEN];
  char ch;
  FILE *fp;
  long count, last;

  puts("Enter the name of the file to be processed:");
  gets(file);

  if ((fp = fopen(file, "rb")) == NULL)
  {
    printf("reverse can't open %s\n", file);
    exit(1);
  }

  fseek(fp, 0L, SEEK_END);      // go to end of file
  last = ftell(fp);

  for (count = 1L; count <= last; count++)
  {
    fseek(fp, -count, SEEK_END);   // go backward
    ch = getc(fp);

    // for DOS, works with Unix
    if (ch != CNTL_Z && ch != '\r')
    {
      putchar(ch);
    }

    // for Macintosh
/*  if (ch == '\r')
    {
      putchar('\n');
    }
    else
    {
      putchar(ch);
    }
*/
  }

  putchar('\n');
  fclose(fp);

  return 0;
}
