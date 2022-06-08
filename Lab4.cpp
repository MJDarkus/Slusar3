#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv)
{

	MPI_Init(&argc, &argv);

	int rank, size, k, l;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int i, j;
	int m = size;
	int n = size * 2;
	
        int matrix[m][n];
	int count = m*n;	
	
        for(i = 0; i < m; i++)
        {
                for(j = 0; j < n; j++)
                {
                        matrix[i][j] = (i+j)*2;
			if(rank==0) {
			printf("%d	", matrix[i][j]);}
                }
		if(rank==0) {
		printf("\n");}
        }

	MPI_Barrier(MPI_COMM_WORLD);

	int buff, answ;

	for(k = 0; k < size; k++)
	{
		if(k==rank)
		{
			for(l = 0; l < n; l++)
			{
				if(matrix[k][0] < matrix[k][l]) {
				matrix[k][0] = matrix[k][l];	
				}
			}	
		printf("For rank %d max num is %d\n", k, matrix[k][0]);
		buff = matrix[k][0];
		}
		l = 0;
	}
	
	MPI_Reduce(&buff, &answ, n, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	
	if(rank==0) { printf("Total maximum is %d\n", answ); }		


	MPI_Finalize();
	return(0);
}
