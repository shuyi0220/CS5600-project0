#ifndef CAESAR_H
#define CAESAR_H

void encode(char *plaintext, int key);
void decode(char *ciphertext, int key);

void getKey(int *pKey);
void getUserInput(char *pInput);


#endif
