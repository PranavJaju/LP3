//Write a program for  analysis of quick sort by using deterministic and randomized 
//variant. 
#include <bits/stdc++.h>
using namespace std;

int deterministicPartition(vector<int> & arr,int low,int high,int & steps){
	int pivot  = arr[high];
	int i = low - 1;
	for(int j = low;j<high;j++){
		steps++;
		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}
void deterministicQuickSort(vector<int> & arr,int low,int high,int & steps){
	if(low<high){
			int pivot = deterministicPartition(arr,low,high,steps);
			deterministicQuickSort(arr,low,pivot-1,steps);
			deterministicQuickSort(arr,pivot+1,high,steps);
	}
}

int randomPartition(vector<int> & arr,int low,int high,int & steps){
	int randomPivotIndex = low + rand() % (high - low + 1);
	swap(arr[randomPivotIndex],arr[high]);
	return deterministicPartition(arr,low,high,steps);
}
void randomizedQuickSort(vector<int> & arr,int low,int high,int & steps){
	if(low<high){
			int pivot = randomPartition(arr,low,high,steps);
			randomizedQuickSort(arr,low,pivot-1,steps);
			randomizedQuickSort(arr,pivot+1,high,steps);
	}
}
void displayArray(const vector<int> &arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}
int main(){
	srand(time(0));
	vector<int> arr = {10, 7, 8, 9, 1, 5};
    vector<int> arrCopy = arr;

    int deterministicComparisons = 0;
    int randomizedComparisons = 0;

    cout << "Original array: ";
    displayArray(arr);

    // Deterministic QuickSort
    deterministicQuickSort(arr, 0, arr.size() - 1, deterministicComparisons);
    cout << "Sorted array (Deterministic QuickSort): ";
    displayArray(arr);
    cout << "Number of comparisons (Deterministic): " << deterministicComparisons << endl;

    // Randomized QuickSort
    randomizedQuickSort(arrCopy, 0, arrCopy.size() - 1, randomizedComparisons);
    cout << "Sorted array (Randomized QuickSort): ";
    displayArray(arrCopy);
    cout << "Number of comparisons (Randomized): " << randomizedComparisons << endl;

    return 0;
}






