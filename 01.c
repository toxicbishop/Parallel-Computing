#include <stdio.h> 
#include <stdlib.h> 
#include <omp.h> 
void merge(int arr[], int l, int m, int r) { 
int i = l, j = m + 1, k = 0; 
int temp[r - l + 1]; 
while (i <= m && j <= r) { 
if (arr[i] <= arr[j]) 
temp[k++] = arr[i++]; 
else 
temp[k++] = arr[j++]; 
} 
while (i <= m) temp[k++] = arr[i++]; 
while (j <= r) temp[k++] = arr[j++]; 
for (i = l, k = 0; i <= r; i++, k++) 
arr[i] = temp[k]; 
} 
void sequentialMergeSort(int arr[], int l, int r) { 
if (l < r) { 
        int m = (l + r) / 2; 
        sequentialMergeSort(arr, l, m); 
        sequentialMergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 
void parallelMergeSort(int arr[], int l, int r) { 
    if (l < r) { 
        int m = (l + r) / 2; 
#pragma omp parallel sections 
        { 
 #pragma omp section 
   parallelMergeSort(arr, l, m); 
 #pragma omp section 
   parallelMergeSort(arr, m + 1, r); 
        } 
   merge(arr, l, m, r); 
    } 
} 
    int main() { 
    int n = 100000; 
    int arr1[n], arr2[n]; 
 for (int i = 0; i < n; i++) { 
        arr1[i] = rand() % 1000; /*Case01 is for 1000 elements and Case02 is for 100000 elements Case03 is for 1000000 elements*/
        arr2[i] = arr1[i]; 
    } 
  double start, end; 
    start = omp_get_wtime(); 
    sequentialMergeSort(arr1, 0, n - 1); 
    end = omp_get_wtime(); 
    printf("Sequential Merge Sort Time: %f seconds\n", end - start); 
 
    start = omp_get_wtime(); 
    parallelMergeSort(arr2, 0, n - 1); 
    end = omp_get_wtime(); 
    printf("Parallel Merge Sort Time: %f seconds\n", end - start); 
 
    return 0; 
}

/*Output:
==========Case 1:  Array Size = 1000 ======== 
Serial Merge Sort Time: 0.004405 sec 
Parallel Merge Sort Time: 0.000428 sec 
=========== Case 2:  Array Size = 10000 ======== 
Serial Merge Sort Time: 0.001092 sec 
Parallel Merge Sort Time: 0.000733 sec 
=========== Case 3:  Array Size = 100000 ======== 
Serial Merge Sort Time: 0.205361 sec 
Parallel Merge Sort Time: 0.006890 sec */