/*4). Write a Open MP program to find the prime numbers from 1 
to n employing parallel for directive. Record both serial and 
parallel execution times.  
*/

#include <stdio.h> 
#include <math.h> 
#include <omp.h> 
int is_prime(int num) { 
    if (num < 2) return 0; 
    for (int i = 2; i <= sqrt(num); i++) { 
        if (num % i == 0) 
            return 0; 
    } 
    return 1; 
} 
int main() { 
 int n; 
 printf("Enter the value of n: "); 
  scanf("%d", &n); 
 printf("\nPrime numbers from 1 to %d:\n", n); 
 for (int i = 1; i <= n; i++) { 
 if (is_prime(i)) 
  printf("%d ", i); 
    } 
  printf("\n"); 
 double start_time, end_time; 
 start_time = omp_get_wtime(); 
 for (int i = 1; i <= n; i++) { 
  is_prime(i); 
    } 
    end_time = omp_get_wtime(); 
    printf("Serial Time: %f seconds\n", end_time - start_time); 
    start_time = omp_get_wtime(); 
    #pragma omp parallel for 
    for (int i = 1; i <= n; i++) { 
    is_prime(i); 
    } 
    end_time = omp_get_wtime(); 
    printf("Parallel Time: %f seconds\n", end_time - start_time); 
    return 0; 
} 
/*OUTPUT:
Prime numbers from 1 to 200: 
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 
163, 167, 173, 179, 181, 191, 193, 197, 199 
Serial Time: 0.000004 seconds 
Parallel Time: 0.000633 seconds
*/