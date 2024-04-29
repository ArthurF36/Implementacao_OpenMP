#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {
    int thread_num = 0;
    int i = 0;
    printf("Marcador antes do inicio do serial\n");
    
    #pragma omp parallel 
    {
        #if _OPENMP
            thread_num = omp_get_thread_num();
        #endif

        i++;
        printf("A Thread está sendo executada agora: %d\n", thread_num);
    }

    printf("Marcador depois do fim do seial\n");
   
    return 0;
}
