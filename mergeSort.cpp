#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void merge(int A[], int begin, int mid, int end){
	int i,j,k;
	int n1 = mid-begin+1;
	int n2 = end-mid;
	int A1[n1], A2[n2];
	for(i=0;i<n1;i++){
		A1[i]=A[begin+i];
	}
	for(j=0;j<n2;j++){
		A2[j]=A[mid+1+j];
	}
	i=0;
	j=0;
	k=begin;
	while(i<n1 && j<n2){
		if(A1[i]<=A2[j]){
			A[k]=A1[i];
			i++;
		}
		else{
			A[k]=A2[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k]=A1[i];
		i++;
		k++;
	}
	while(j<n2){
		A[k]=A2[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int begin, int end){
	if(begin<end){
		int mid=begin+(end-begin)/2;
		mergeSort(A, begin, mid);
		mergeSort(A, mid+1, end);
		merge(A, begin, mid, end);
	}
}

int main(int argc, char** argv) {
	int n=20;
	int arr[n];
	srand(time(0));
	cout << "Array is\n";
	for(int i=0; i<n; i++){
		arr[i]=rand() %100+1;
		cout << arr[i] << " ";
	}
	
	mergeSort(arr, 0, n-1);
	
	cout << "\nSorted array is \n";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
