#include <stdio.h>
#include <string.h>

void encrypt(char* plaintext, int key, char* ciphertext);
void decrypt(char* plaintext, int key, char* ciphertext);

int main()
{

	char plaintext[100] = "hello world";
	char plaintext2[100];
	char ciphertext[100];
    int key = 3;
	printf("Encrypt:\n\tPlaintext: ");
	puts(plaintext);
	encrypt(plaintext, key, ciphertext);
	printf("\tCiphertext: ");
	puts(ciphertext);
	printf("Decrypt:\n\tCiphertext: ");
	puts(ciphertext);
	decrypt(ciphertext, key, plaintext2);
	printf("\tPlaintext: ");
	puts(plaintext2);
	return 0;
}

void encrypt(char* plaintext, int key, char* ciphertext)
{
	for(int i = 0; i < strlen(plaintext); i++)
	{
		ciphertext[i] = (((plaintext[i]) << key) | ((plaintext[i]) >> (8 - key)));
	}
	ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char* ciphertext, int key, char* plaintext)
{
	for(int i = 0; i < strlen(ciphertext); i++)
	{
	    if((ciphertext[i] & 0b10000000) == 0b10000000)
        {
            plaintext[i] = (((ciphertext[i] & 0b01111111) >> key) | ((ciphertext[i] & 0b01111111) << (8 - key))) 
															| ((0b10000000 >> key) | (0b10000000 << (8 - key)));
        }
        else
		{
		    plaintext[i] = ((ciphertext[i] >> key) | (ciphertext[i] << (8 - key)));
		}
	}
	plaintext[strlen(ciphertext)] = '\0';
}
