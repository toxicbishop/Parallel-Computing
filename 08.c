#include <mpi.h> 
#include <stdio.h> 
int main(int argc, char *argv[]) { 
int rank, size; 
int send_data[100], recv_data, gathered_data[100]; 
MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
MPI_Comm_size(MPI_COMM_WORLD, &size); 
if (rank == 0) { 
for (int i = 0; i < size; i++) { 
send_data[i] = i * 10; 
} 
} 
MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, 
MPI_COMM_WORLD); 
recv_data = recv_data + rank; 
MPI_Gather(&recv_data, 1, MPI_INT, gathered_data, 1, MPI_INT, 0, 
MPI_COMM_WORLD); 
if (rank == 0) { 
printf("Gathered data in root process:\n"); 
for (int i = 0; i < size; i++) { 
printf("gathered_data[%d] = %d\n", i, gathered_data[i]); 
} 
} 
MPI_Finalize(); 
return 0; 
}