#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {

	printf("Marcador antes do inicio da paralelização\n");

	#pragma omp parallel
	printf("A Thread %d está sendo executada agora\n", omp_get_thread_num());

    printf("Marcador depois do fim da paralelização\n");

	return 0;
}