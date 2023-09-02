#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "utilities.h"
#include "macros.c"

struct DataSection{
  size_t size;
  uint8_t data[DataSectionSize];
} __attribute__((packed));

struct Password{
  uint8_t PasswordMin;
  uint8_t PasswordMax;
  uint8_t password[255];
} __attribute__((packed));

typedef struct DataSection DataSection;
typedef struct Password Password;

// As remembering
// Sets to null first n bytes of buff
// Insecure function
void zero(void *buff, size_t n)
{
  for(register unsigned i = 0; i < n; i++)
    *((uint8_t *)buff + i) = 0;
}

Password *GetPassword(TYPE from, TYPE to)
{
	TYPE aux = 0;
	if (from == to)
		exit(POR_BOLUDO);

	if(from > to){
		aux = from;
		from = to;
		to = aux;
  }

	Password *password = (Password *)malloc(sizeof(Password));

	if(NULL == password)
		exit(FAILED_ALLOCATION);

  zero((void *)password, sizeof(Password));

	for(size_t i = from; i < to + 1; ){
		aux = rand() % (to - from + 1);
		if(0 == *(password -> password + aux)){
			*(password -> password + aux) = i;
			++i;
		}
	}

	password -> PasswordMin = from;
	password -> PasswordMax = to;

	return password;
}

// Returns a pointer to a password structure after loading it to the memory

Password *LoadPassword(char *password_file_name)
{
	Password *password = (Password *)malloc(sizeof(Password));
  zero(password, sizeof(Password));

	if(NULL == password)
		exit(FAILED_ALLOCATION);

  FILE *flow = fopen(password_file_name, "rb");
	if(NULL == flow)
  {
    perror("Could not find the password file\n");
    exit(OPEN_FILE_ERROR);
    //printf("You can write the password instead (with limitations):\n");
    //int c;
    /*
      *
      * TODO
      *
      */
    //for(int i = 0; password = ());
  }
  fread(password, sizeof(Password), 1, flow);
  /*
  password -> PasswordMin = min(password -> password, password_len);
  password -> PasswordMax = max(password -> password, password_len);
  */
 // printf("%i\n", *(password -> password));
  printf("Loaded password: %s\n", password -> password);
  return password;
}


// Integer because it will return status values
// With fread() it's completly unusefull
/*
int LoadFileSection(FILE *flow, DataSection *data)
{
int8_t c;
for(int i = 0; i < data -> size; i++){
  c = getc(flow);
  if(c == EOF){
			data -> size = i;
			return EOF;
		}
		*(data -> data + i) = c;
	}

	return 0;
}
*/

// Encrypts first n bytes of *buffer 
/*
void bog(size_t i){
  printf("b%zu\n", i);
  //sleep(1);
}
*/
int crypt1(DataSection *Data, Password *Password)
{
	TYPE aux;
  for(size_t i = 0; i < Data -> size && i <= DataSectionSize; i++){
		aux = *(Data -> data + i);

		if(aux < Password -> PasswordMin || aux > Password -> PasswordMax)
			continue;
		*(Data -> data + i) = *(Password -> password + aux - (Password -> PasswordMin));
    aux = *(Data -> data + i);
  }

	return 0;
}

DataSection *CreateDataSection(void)
{
	DataSection *NewData = (DataSection *)malloc(sizeof(DataSection));
	zero(NewData, sizeof(DataSection));
	NewData -> size = DataSectionSize;
  //printf("CreateDataSection: NewData -> size == %zu\n", NewData -> size);
	return NewData;
}

/*
 completly unusefull with fwrite
int FputData(DataSection *Data, FILE *flow)
{
	for(int i = 0; i < Data -> size; i++)
		putc((int)(*(Data -> data + i)), flow);
	return 0;
}
*/
Password *re_password(Password *password){
  size_t password_len = PasswordLen(password);
  Password *re_password = (Password *)malloc(sizeof(Password));

  for(int i = 0; i < password_len; i++)
    *(re_password -> password + *(password -> password + i) - password -> PasswordMin) = i + password -> PasswordMin;
  re_password -> PasswordMin = password -> PasswordMin;
  re_password -> PasswordMax = password -> PasswordMax;
  return re_password;
}


