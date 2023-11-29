/* Jens Gustedt * Modern C * Challenge 1 * p.26 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 11

void printfarr(int arrlen, int* arrPtr[]);
void divide(int arrlen, int* arrPtr[]);

int main(int argc, char* argv[]) {
  //srand(time(NULL));

  int* arrPtr[ARR_LEN];
  for (int i=0; i<ARR_LEN; i++) {
    arrPtr[i] = malloc(sizeof(int));
    *arrPtr[i] = rand()%ARR_LEN;
  }
  
  printfarr(ARR_LEN, arrPtr);

  if (ARR_LEN>1) divide(ARR_LEN, arrPtr);
  
  return 0;
}

void printfarr(int arrlen, int* arrPtr[]) {
  for (int i=0; i<arrlen; i++)
    printf("%d\t", *arrPtr[i]);
  putchar('\t');
}

void divide(int arrlen, int* arrPtr[]) {
  int rlen = arrlen/2;
  int llen = arrlen - rlen;
  int ridx = llen;
  putchar('\n');
  printfarr(llen, arrPtr);
  printfarr(rlen, arrPtr+ridx);
}
