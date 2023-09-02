#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FILE_NAME_SIZE 100
#define CHAR_COUNT     96

int main(void){
	char *file_name = (char *)malloc(FILE_NAME_SIZE);
	printf("Write the name of the file: ");
	scanf("%s", file_name);

	FILE *flow = fopen(file_name, "r");

	if(flow == NULL){
		perror("Error al abrir el archivo");
		return 1;
	}

	char *file;
	fseek(flow, 0, SEEK_END);
	int *elem = (int *)malloc(sizeof(int));
	*elem = (int)ftell(flow);
	file = (char *)calloc(sizeof(char), *elem);

	rewind(flow);
	fread(file, 1, *elem, flow);
	

	fflush(flow);
	fclose(flow);

	// Es extremadamente importante inicializar este arreglo, sino, depende de tu suerte el funcionamiento
	char p[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

	srand(time(NULL));

	int y;

	for(int i = 32; i <= 127; i++){
		y = rand()%96;
		if(p[y] == NULL)
			p[y] = (char)i;
		else
			--i;
	}


	for(int i = 0; file[i] != NULL; i++){
		if(file[i] < 32)
			continue;
		file[i] = p[file[i] - 32];
	}

	strcat(file_name, ".crypt");
	FILE *new = fopen(file_name, "wb");
	fputs(file, new);

	printf("\"%s\" was created \nSIZE: %iB\n\n", file_name, *elem);
	printf("This is the random generated password: \n%s\n\n", p);

	fflush(new);
	fclose(new);

	return 0;
	
}

