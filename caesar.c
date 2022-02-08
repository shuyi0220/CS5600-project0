#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"

void encode(char *plaintext, int key) {
  char temp;
  char *pInput = (char*) plaintext;


  printf("[Before]Encode input string: %s\n", pInput);
  for (int i = 0; pInput[i] != '\0'; i++) {
    temp = pInput[i];
    if (temp >= 'a' && temp <= 'z') {
      pInput[i] = 'a' + ((temp-'a'+key)%26);
    } else if ( temp >= 'A' && temp <= 'Z') {
      pInput[i] = 'A' + ((temp-'A'+key)%26);
    }
  }
  printf("[After]Encrypted Message: %s\n", plaintext);
}

void decode(char *ciphertext, int key){
  char temp;
  char *pInput = (char*) ciphertext;

  printf("[Before]Decode input string: %s\n", pInput);
  for (int i = 0; pInput[i] != '\0'; i++) {
    temp = pInput[i];
    if (temp >= 'a' && temp <= 'z') {
      pInput[i] = 'a' + ((temp-'a'-key)%26);
    } else if ( temp >= 'A' && temp <= 'Z') {
      pInput[i] = 'A' + ((temp-'A'-key)%26);
      }
  }
  printf("[After]Decrypted Message: %s\n", ciphertext);
}

void getKey(int *pKey){
  printf("Enter key: ");
  scanf("%d", pKey);
  if (*pKey < 0 || *pKey > 25) {
    perror("ERROR: Decode input NULL\n");
    exit(-1);
  }
}

void getUserInput(char *pInput){
  int c;
  int i = 0;
  printf("Enter the message: ");
  while ((c = getchar()) != '\n' && c != EOF) {
    pInput[i++] = c;
    pInput = realloc(pInput, i+1);
  }
  pInput[i] = '\0';
}
