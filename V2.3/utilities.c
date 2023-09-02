#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#include "m.c"
TYPE min(uint8_t *buffer, int n)
{
  TYPE min = 127;
  for(size_t i = 0; i < n; i++)
    if(*(buffer + i) < min){
      min = *(buffer + i);
    }                                                              return min;
}

TYPE max(uint8_t *buffer, int n)
{
  TYPE max = 0;
  for(size_t i = 0; i < n; i++)
    if(*(buffer + i) > max)
      max = *(buffer + i);
  return max;
}

