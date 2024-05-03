#include <stdio.h>
#include <string.h>

void complementEncryptAndDecrypt(char* plaintext, char* ciphertext);

int main()
{
	char plaintext[100] = "hello world";
	char plaintext2[100];
	char ciphertext[100];
	printf("Encrypt:\n\tPlaintext: ");
	puts(plaintext);
	complementEncryptAndDecrypt(plaintext, ciphertext);
	printf("\tCiphertext: ");
	puts(ciphertext);
	printf("Decrypt:\n\tCiphertext: ");
	puts(ciphertext);
	complementEncryptAndDecrypt(ciphertext, plaintext2);
	printf("\tPlaintext: ");
	puts(plaintext);
	return 0;
}

void complementEncryptAndDecrypt(char* plaintext, char* ciphertext)
{
	for(int i = 0; i < strlen(plaintext); i++)
	{
		ciphertext[i] = ~plaintext[i];
	}
	ciphertext[strlen(plaintext)] = '\0';
}