#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.c"

int CryptMenu(void){
  printf("Write the name of the file to crypt: ");
  char *file_name = (char *)malloc(MAX_NAME_LEN);

  scanf(" %s", file_name);
  printf("File to crypt: %s\n", file_name);

  FILE *flow = fopen(file_name, "rb");
  if (NULL == flow) {
    printf("ERROR: \"%s\" does not exist!\n", file_name);
    exit(OPEN_FILE_ERROR);
  }

  char crypt_name[strlen(file_name) + 6];
  strcpy(crypt_name, file_name);
  strcat(crypt_name, ".crypt");

  FCrypterAlgorithm(flow, crypt_name);
  printf("SUCCEED\n");

  //free(crypt_name);
  free(file_name);

  fflush(flow);
  fclose(flow);
  
  system(PAUSE);
  return 0;
}

int UncryptMenu(void) {
  //printf("This option is not suported yet! (it will be tomorrow)\n");
  char *uncrypt_name = (char *)malloc(MAX_NAME_LEN);
  printf("Write the name of the file to uncrypt: ");
  scanf(" %s", uncrypt_name);

  //strcat(uncrypt_name, ".uncrypt");
  FUncrypterAlgorithm(uncrypt_name);
  free(uncrypt_name);

  system(PAUSE);
  return 0;
}

int PrincipalMenu(void){
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("|          FCrypter       |\n");
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("               Poor crypter\n");

  printf("You have three attemps\nSelect options:\n");
  printf("1. Crypt\n");
  printf("2. Uncrypt\n");
  printf("3. Quit\n");

  printf("> ");

  int tries = 0;
  int aux;
  while (true) {
    switch(((aux = getchar() - '0') == '\n' - '0') ? aux = getchar() : aux)
    {
      case 1 :
        fflush(stdin);
        return CryptMenu(); break;

      case 2 :
        fflush(stdin);
        return UncryptMenu(); break;

      case 3 :
        exit(SUCCEED); break;

      default :
        ++tries;
        if(tries == 3){
	  printf("Muy boludo sos ya sos\n");
          exit(POR_BOLUDO);
	}

        while(getc(stdin) != '\n'); // delete all after the ooption letter
        system(CLEAR);
        printf("retry\n");
        printf("> ");
    }
  }

  return 0;
}
