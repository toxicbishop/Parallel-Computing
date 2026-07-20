/*2). Write a Open MP program that divides the Iteration into 
chunks containing 2 iterations, respectively 
(OMP_SCHEDULE=static, 2). Its input should be the number of 
iteration, and its output should be which iterations of a 
parallelized for loops are executed by which thread. 
For example, if there are two threads and four iterations, the output 
might be the following: 
a. Thread 0 : Iteration 0 – 1 
b. Thread 1:  Iteration 2 – 3 */

#include <stdio.h> 
#include <omp.h> 
int main() 
{ 
int n = 16, thread; 
printf("\n Enter the number of tasks"); 
scanf("%d", &n); 
printf("\n Enter the number of threads"); 
scanf("%d", &thread); 
omp_set_num_threads(thread); 
printf("\n----------------------------\n"); 
int i;  // Declare loop variable outside 
#pragma omp parallel for schedule(static, 2) 
for(i = 0; i < n; i++) 
{ 
printf("Thread %d executes iteration %d\n", omp_get_thread_num(), 
i); 
} 
return  0; 
} 
/*
OUTPUT: 
Enter the number of tasks 24 
Enter the number of threads 12 
Thread 4 executes iteration 8 
Thread 4 executes iteration 9 
Thread 0 executes iteration 0 
Thread 0 executes iteration 1 
Thread 5 executes iteration 10 
Thread 5 executes iteration 11 
Thread 3 executes iteration 6 
Thread 3 executes iteration 7 
Thread 2 executes iteration 4 
Thread 2 executes iteration 5 
Thread 11 executes iteration 22 
Thread 11 executes iteration 23 
Thread 6 executes iteration 12 
Thread 6 executes iteration 13 
Thread 10 executes iteration 20 
Thread 10 executes iteration 21 
Thread 8 executes iteration 16 
Thread 8 executes iteration 17 
Thread 9 executes iteration 18 
Thread 9 executes iteration 19 
Thread 7 executes iteration 14 
Thread 7 executes iteration 15 
Thread 1 executes iteration 2 
Thread 1 executes iteration 3
*/