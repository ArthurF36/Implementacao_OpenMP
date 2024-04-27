#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {
    int thread_num = 0;
    int i = 0;
    printf("Marcador antes do inicio da paralelização\n");
    
    #pragma omp parallel 
    {
        #if _OPENMP
            thread_num = omp_get_thread_num();
        #endif

        i++;
        printf("A Thread %d está sendo executada agora\n", thread_num);
        printf("Ultima thread executada: %d\n", thread_num);
    }

    printf("Marcador depois do fim da paralelização\n");
   
    return 0;
}
