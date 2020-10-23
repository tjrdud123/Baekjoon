#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 1000000
using namespace std;
vector<int> sorted;
void merge(vector<int>& arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }
    if(i <= mid) {
        while(i <= mid) sorted[k++] = arr[i++];
    }
    else {
        while(j <= end) sorted[k++] = arr[j++];
    }
    for(int i = start; i <= end; i++) {
        arr[i] = sorted[i];
    }
}
void mergeSort(vector<int>& arr, int start, int end) {
    int mid = (start + end) / 2;

    if(start < end) {
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> arr;
    
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);

    sorted.resize(6);
    mergeSort(arr, 0, 5);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}