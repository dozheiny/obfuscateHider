#include <stdio.h>

// limit file size [1MB]
#define MAX_FILE_SIZE (1024 * 1024)

int main(int argc, char **args)
{
		if (argc < 2) {
			printf("usage: %s <file name>\n\n", args[0]);
			return 1;
		}

		char *filename = args[1];
		FILE *fptr;
		char data[MAX_FILE_SIZE];

		fptr = fopen(filename, "rb"); //open file
		if (fptr == NULL) {
			perror(filename);
			return 1;
		}

		int i = 0;
		while (!feof(fptr)) // reading file
		{
				data[i++] = fgetc(fptr);
		}
		fclose(fptr);	

		fptr = fopen(filename, "wb"); // writing file
		if (fptr == NULL) {
			perror(filename);
			return 1;
		}

		for(int j=0; j<i; j++)
		{
			fputc((data[j] ^ 0x60), fptr);
		}
		fclose(fptr);

		return 0;
}

// using hex for encrypting file
