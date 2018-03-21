#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt_decrypt(char ch, int k);

int main(int argc, char* argv[])
{
	int choice, key;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf("Usage: cipher inputFile key outputFile option(e or d)\n");
		printf("Option e for encryption and d for decryption");
		exit(1);
	}

	key = atoi(argv[2]); //ocnvert from string to integer

	if (strcmp(argv[4],"d")==0) //decryption
		key = -key;

	fin = fopen(argv[1], "r");
	fout = fopen(argv[3], "w");

	if(fin == NULL || fout == NULL)
	{
		printf("File could not be opened!\n");
		exit(1);
	}

	while( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt_decrypt(ch, key));
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt_decrypt(char ch, int k)
{
	if ( k<0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';

	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';

	return ch;
}
