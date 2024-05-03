#include <stdio.h>
#include <string.h>

void xorEncryptAndDecrypt(char* plaintext, char* key, char* ciphertext);

int main()
{
	char plaintext[100] = "hello world";
	char plaintext2[100];
	char key[100] = "SOMEKEY";
	char ciphertext[100];
	printf("Encrypt:\n\tPlaintext: ");
	puts(plaintext);
	xorEncryptAndDecrypt(plaintext, key, ciphertext);
	printf("\tCiphertext: ");
	puts(ciphertext);
	printf("Decrypt:\n\tCiphertext: ");
	puts(ciphertext);
	xorEncryptAndDecrypt(ciphertext, key, plaintext2);
	printf("\tPlaintext: ");
	puts(plaintext2);
	return 0;
}

void xorEncryptAndDecrypt(char* plaintext, char* key, char* ciphertext)
{
	for(int i = 0; i < strlen(plaintext); i++)
	{
		ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
	}
	ciphertext[strlen(plaintext)] = '\0';
}