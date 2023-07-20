#include<iostream>
using namespace std;


//in 1st round, last ele is correctly placed, in 2nd round sec last ele is corr place
int bubblesort( int arr[50], int n){
    for ( int i=0; i<(n-1); i++){
        for ( int j=0; j<(n-i-1); j++){
            if ( arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }

        }
    }
}






//in every round, we pick the min element and place it at the right spot
int selectionsort( int arr[], int n){
	 for ( int i=0; i<n-1; i++){
	 	int min=i;
        for ( int j=i+1; j<n; j++){
            if ( arr[j]<arr[min]){
            	min=j;
            	
            }

        }
         swap(arr[min],arr[i]);
    }
    
   
}






void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}











int partition(int *arr, int p, int r){
	int i=-1, pivot=arr[r];
	for( int j=0; j<r; j++){
		if (arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return (i+1);
}

int quicksort( int *arr, int p, int r){   //start pos=p, end pos=r;
	 if (p<r){
	 	int q;
	 	q=partition(arr,p,r);
	 	quicksort(arr,p,q-1);
	 	quicksort(arr,q+1,r);
	 }
}






void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for ( int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


void printarr( int *arr, int n){

for(int i=0; i<n;i++){
    cout<<arr[i]<<" ";
}
}


int main(){
int arr[50],n,p,q,r;
cin>>n;
for(int i=0; i<n;i++){
    cin>>arr[i];
}
mergesort(arr,0,n-1);
printarr(arr,n);

return 0;
}
