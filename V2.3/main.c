#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "menu.c"

//#define DataSectionSize 4092
int main(void){
  srand(time(NULL));
  return PrincipalMenu();

  return 0;
}
