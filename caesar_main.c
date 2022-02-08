#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"

int main(void) {
  char *input = malloc(sizeof(char));
  // char *input2 = malloc(sizeof(char));
  // if (input == NULL) {
  //   perror("\nERROR: Memory not initialized\n");
  //   exit(-1);
  // }
  // if (input2 == NULL) {
  //   perror("\nERROR: Memory not initialized\n");
  //   exit(-1);
  //

  int key1;
  getUserInput(input);
  getKey(&key1);
  encode(input, key1);
  decode(input, key1);
  free(input);

  // int key2;
  // getUserInput(input);
  // getKey(&key2);
  // decode(input, key2);
  // free(input);
  return 0;
}
