/* addemup.c -- four kinds of statements */
#include <stdio.h>

int main(void)                // find sum of first 20 integers
{
  int count, sum;             // declaration statement

  count = 0;                  // assignment statement
  sum = 0;                    // ditto

  while (count++ < 20)
  {
    sum = sum + count;        // while
  }                           //  statement 

  printf("sum = %d\n", sum);  // function statement

  return 0;
}
