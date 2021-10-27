#include <stdio.h>

// Set chunk size to 1MB
#define CHUNK_SIZE (1024*1024)

int main(int argc, char **args)
{
		if (argc < 2) {
			printf("usage: %s <file name>\n\n", args[0]);
			return 1;
		}

		char *filename = args[1];
		FILE *fptr;
		char chunk[CHUNK_SIZE];
		long int position;

		// open file
		fptr = fopen(filename, "rb+");
		if (fptr == NULL) {
			perror(filename);
			return 1;
		}

		// set position
		position = ftell(fptr);

		size_t count;
		while (1) {
			// read a chunk
			count = fread(chunk, 1, CHUNK_SIZE, fptr);
			
			// encrypt or decrypt chunk
			for (int i = 0; i < count; i++) {
				chunk[i] = (chunk[i]^0x60);
			}

			// seek to start of chunk and write back
			fseek(fptr, position, SEEK_SET);
			fwrite(chunk, 1, count, fptr);

			// save position
			position = ftell(fptr);

			// count is less than CHUNK_SIZE when we reach to end of file
			if (count != CHUNK_SIZE) break;
		}
		
		fclose(fptr); // close file

		return 0;
}

// using hex for encrypting file
