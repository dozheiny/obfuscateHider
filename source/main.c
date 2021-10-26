#include <stdio.h>

// limit file size [1MB]
#define MAX_FILE_SIZE (1024 * 1024)
int main()
{
		FILE *fptr;
		char data[MAX_FILE_SIZE];

		fptr = fopen("pic.jpg", "rb"); //open file

		int i = 0;
		while (!feof(fptr)) // reading file
		{
				data[i++] = fgetc(fptr);
		}
		fclose(fptr);	

		fptr = fopen("pic.jpg", "wb"); // writing file

		for(int j=0; j<i; j++)
		{
			fputc((data[j] ^ 0x60), fptr);
		}
		fclose(fptr);

		return 0;
}

// using hex for encrypting file
