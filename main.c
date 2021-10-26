#include <stdio.h>

#define MAX_FILE_SIZE (1024 * 1024)
int main()
{
		FILE *fptr;
		char data[MAX_FILE_SIZE];

		fptr = fopen("pic.jpg", "rb");


		int i = 0;
		while (!feof(fptr))
		{
				data[i++] = fgetc(fptr);
		}
		fclose(fptr);	

		fptr = fopen("pic.jpg", "wb");

		for(int j=0; j<i; j++)
		{
			fputc((data[j] ^ 0x60), fptr);
		}
		fclose(fptr);

		return 0;
}
