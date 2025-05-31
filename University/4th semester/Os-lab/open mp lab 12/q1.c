#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 100

void print(int matrix[][N])
{
	int i, j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}


int main()
{
    srand(time(0));

    int matrix1[N][N], matrix2[N][N], i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix1[i][j] = rand() % 100 + 1;
            matrix2[i][j] = rand() % 100 + 1;
        }
    }

    int n=100;
    print(matrix1);
    print(matrix2);

    int sum[N][N];

    #pragma omp parallel private(i, j) shared(sum)
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {

	    #pragma omp critical
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    print(sum);

    return 0;
}
