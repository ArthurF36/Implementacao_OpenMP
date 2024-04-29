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
	int thread_num = 0;
	int thread_size = 1;
	
	
	inicializa(&vetor, size);
	
	#pragma omp parallel
	{
		#if _OPENMP
            thread_num = omp_get_thread_num();
			thread_size = omp_get_num_threads();
        #endif

		// divisão do trabalho
		int local_init, local_end, chunk;
		chunk = size / thread_size;
		local_init = thread_num * chunk;
		local_end = (thread_num+1) * chunk;
		if((thread_size  - 1) == thread_num)local_end = size;
		
		// calculo, cada thread responsável por seu bloco de memória
		for(int i = 0; i < size; i++){
			printf("Thread: %d\n", thread_num);
			printf("Raiz quadrada do número: %d\n", vetor[i]);
			vetor[i] = square(vetor[i]);
			printf("= %d\n", vetor[i]);
			printf("\n");
		} 
	}
	  

	return 0;
}