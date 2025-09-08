#include<stdio.h>
#include<stdlib.h>

void arrTraversal(int *A, int size)
{
	for(int i = 0; i < size; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

void merge(int *A, int low, int mid, int high){
	int *B;
	B = (int *)malloc((high+1) * sizeof(int));
	int i = low;
	int j = mid + 1;
	int k = low;

	while(i <= mid && j <= high){
		if(A[i] < A[j]){
			B[k] = A[i];
			k++;
			i++;
		}else{
			B[k] = A[j];
			k++;
			j++;
		}
	}

	while(i <= mid){
		B[k] = A[i];
		k++;
		i++;
	}

	while(j <= high){
		B[k] = A[j];
		k++;
		j++;
	}

	for(int i = low; i <= high; i++){
		A[i] = B[i];
	}
}

void mergeSort(int *A, int low, int high){
	int mid;
	if(low < high){
		mid = (low + high) / 2;
		mergeSort(A, low, mid); //for left sub array
		mergeSort(A, mid + 1, high);// for right sub array
		merge(A, low, mid, high);
	}
}

int main()
{
	int A[10] = {37, 23, 43, 67, 87, 76, 21, 20, 52, 12};
	int size = sizeof(A)/sizeof(int);

	arrTraversal(A, size);
	mergeSort(A, 0, size - 1);
	arrTraversal(A, size);
	return 0; 
}