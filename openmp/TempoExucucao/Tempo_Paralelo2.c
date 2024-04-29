#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>


void inicializa(int **v, int size) {
  (*v) = (int *) malloc(sizeof(int)*size);
  for (int i = 0; i < size; i++) {
    (*v)[i] = rand() % 10000;
  }
}

float square(int x){
  int k = 0;
  while(k < 4000) k++;
  return sqrt(x);  
}


int main(int argc, char **argv) {
	srand(time(NULL));
	
	int *vetor;
	int size = 1000000;
	
	
	inicializa(&vetor, size);
	
	#pragma omp parallel for
	for(int i = 0; i < size; i++){
		printf("Thread: %d\n", omp_get_thread_num());
		printf("Raiz quadrada do número: %d\n", vetor[i]);
		vetor[i] = square(vetor[i]);
		printf("= %d\n", vetor[i]);
		printf("\n");
	} 
	  

	return 0;
}