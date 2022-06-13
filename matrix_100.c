#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int N=100;
	int *ptr = mmap(NULL, N*sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	
	if(ptr == MAP_FAILED){
		printf("Mapping Failed\n");
		return 1;
	}
	
	int matrix1[100][100];
	int matrix2[100][100];
	int matrix_mul[100][100];
	int i, j, k;
	int mul = 0;
	
	srand((int)time(NULL));
	// matrix1
	printf("matrix1\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			ptr[j] = rand() % 10;
			matrix1[i][j] = ptr[j];
			printf("[%d]\t", matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// matrix2
	printf("matrix2\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			ptr[j] = rand() % 10;
			matrix2[i][j] = ptr[j];
			printf("[%d]\t", matrix2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	// matrix multiplication
	printf("matrix multiplication\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				mul += matrix1[i][k] * matrix2[k][j];
			}
			matrix_mul[i][j] = mul;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("[%d]\t", matrix_mul[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	
	int err = munmap(ptr, 10*sizeof(int));
	
	if(err != 0){
		printf("UnMapping Failed\n");
		return 1;
	}
	
	return 0;
}
