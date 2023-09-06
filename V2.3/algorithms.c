#include <unistd.h>

#include "functions.c"
#include "macros.c"
/*
void bug(){
  printf("a\n");
  sleep(1);
}
*/
int FCrypterAlgorithm(FILE *flow, char *crypt_name)
{
  FILE *CryptedFile = fopen(crypt_name, "r");
  if(NULL != CryptedFile){
    printf("ERROR: \"%s\" already exists!\n", crypt_name);
      exit(OPEN_FILE_ERROR);
  }

  //fflush(CryptedFile);
  //fclose(CryptedFile);

  CryptedFile = fopen(crypt_name, "wb");
  if(NULL == CryptedFile)
    exit(OPEN_FILE_ERROR);

  DataSection *Data_buffer = CreateDataSection();
  Password *password = GetPassword((TYPE)32, (TYPE)126);

  char *password_file_name = malloc(strlen(crypt_name) + 9);
  strcpy(password_file_name, crypt_name);
  strcat(password_file_name, ".password");

  FILE *password_file = fopen(password_file_name, "rb");
  if(NULL != password_file){
    printf("ERROR: \"%s\" already exists!\n", password_file_name);
    exit(OPEN_FILE_ERROR);
  }
  fflush(password_file);

  password_file = fopen(password_file_name, "wb");
  fwrite(password, sizeof(Password), 1, password_file);

  fflush(password_file);
  fclose(password_file);

  // Status tells if there's more file or not
  int status = 1;
  while(status)
  {
    //bug();
    zero(Data_buffer, sizeof(DataSection));

    //bug();
    Data_buffer -> size = fread(Data_buffer -> data, 1, DataSectionSize, flow);

    //bug();
    if(feof(flow))
      status = 0;
      //printf("EOF\n");

    //bug();
    crypt1(Data_buffer, password);
    //bug();
    fwrite(Data_buffer, sizeof(DataSection), 1, CryptedFile);
  }

  //printf("a");
  free(Data_buffer);

  printf("Password: \n");
  printf("%s\n", (char *)password -> password);

  free(password);

  fflush(CryptedFile);
  fclose(CryptedFile);

  system(PAUSE);
  return 0;
}

int FUncrypterAlgorithm(char *name){
  FILE *to_uncrypt = fopen(name, "rb");
  if(NULL == to_uncrypt){
    perror("Could not open the file to uncrypt!\n");
    exit(OPEN_FILE_ERROR);
  }

  char *uncrypt_name = (char *)malloc(strlen(name));
  strcpy(uncrypt_name, name);
  int k_len_p = strlen(name) - 1;

  for(int i = k_len_p; i > k_len_p - 6; i--)
    uncrypt_name[i] = '\0';

  FILE *dcrypt = fopen(uncrypt_name, "r");
  if(NULL != dcrypt){
    printf("ERROR: \"%s\" already exists!\n", uncrypt_name);
    exit(OPEN_FILE_ERROR);
  }

  dcrypt = fopen(uncrypt_name, "wb");
  if(NULL == dcrypt){
    printf("ERROR: Could not create \"%s\"!\n", uncrypt_name);
    exit(OPEN_FILE_ERROR);
  }

  printf("Searching for password file... ");
  char *password_file_name = malloc(strlen(name) + 9);
  zero((int8_t *)password_file_name, strlen(name) + 9);

  strcpy(password_file_name, name);
  strcat(password_file_name, ".password");

  Password *password = LoadPassword(password_file_name);
  printf("DONE\n");

  Password *ree_password = re_password(password);
  DataSection *Data_buffer = CreateDataSection();

  // status tells if there's more file or not
  printf("Uncrypting... ");
  int status = 1;
  int readed;
  while(status)
  {
    // inverted arguments to know how many bytes where readed
    readed = fread(Data_buffer, 1, sizeof(DataSection), to_uncrypt);

    //fseek(to_uncrypt, 1, SEEK_CUR);

    if(readed != sizeof(DataSection))
       break;
    
    //fseek(to_uncrypt, -1, SEEK_CUR);
    crypt1(Data_buffer, ree_password);
    fwrite(Data_buffer -> data, Data_buffer -> size, 1, dcrypt);
  }
  printf("DONE\n");
  free(password);
  free(ree_password);

  fflush(dcrypt);
  fclose(dcrypt);

  fflush(to_uncrypt);
  fclose(to_uncrypt);

  system(PAUSE);
  return 0;
}
