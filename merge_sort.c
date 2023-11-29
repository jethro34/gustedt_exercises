/* Jens Gustedt * Modern C * Challenge 1 * p.26 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN 11

void printfarr(int arrlen, int* arrPtr[]);
void divide(int arrlen, int* arrPtr[]);
void merge(int llen, int* larrPtr[], int rlen, int* rarrPtr[]);

int main(int argc, char* argv[]) {
  srand(time(NULL));

  // create & fill in orig ptr to int arr 
  int* arrPtr[ARR_LEN];
  for (int i=0; i<ARR_LEN; i++) {
    arrPtr[i] = malloc(sizeof(int));
    *arrPtr[i] = rand()%ARR_LEN;
  }
  
  printfarr(ARR_LEN, arrPtr);
  
  // initial call
  if (ARR_LEN>1) divide(ARR_LEN, arrPtr);
    
  printfarr(ARR_LEN, arrPtr);
  return 0;
}

void printfarr(int arrlen, int* arrPtr[]) {
  putchar('\n');
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
  
  // recursive cases
  if (llen>1) divide(llen, arrPtr);
  if (rlen>1) divide(rlen, arrPtr+ridx);
  
  // base case
  merge(llen, arrPtr, rlen, arrPtr+ridx);
}

// merge two arrays of pointers to int in-place
void merge(int llen, int* larrPtr[], int rlen, int* rarrPtr[]) {

  // create temp ptr to int arr to store merged arrs
  int* temp[llen + rlen];
  for (int i=0; i < llen+rlen; i++)
    temp[i] = malloc(sizeof(int));
  
  // comp & copy orig values to temp arr values
  int lidx=0, ridx=0, tidx=0;
  while ((lidx < llen) && (ridx < rlen))
    if (*larrPtr[lidx] < *rarrPtr[ridx])
      *temp[tidx++] = *larrPtr[lidx++];
    else
      *temp[tidx++] = *rarrPtr[ridx++];
  
  if (lidx == llen)
    while (tidx < llen+rlen)
      *temp[tidx++] = *rarrPtr[ridx++];
  else if (ridx == rlen)
    while (tidx < llen+rlen)
      *temp[tidx++] = *larrPtr[lidx++];

  // copy temp values to orig arr values
  for (int i=0; i < tidx; i++) {
    *larrPtr[i] = *temp[i];
    free(temp[i]);    // free temp arr
  }
  
}

