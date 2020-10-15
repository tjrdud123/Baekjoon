#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 1000000
using namespace std;
int maxHeap[MAX_SIZE];
int heapSize = 0;
void hInsert(int key) {
    int idx = ++heapSize;
    while(idx > 1 && maxHeap[idx / 2] < key) {
        maxHeap[idx] = maxHeap[idx / 2];
        idx /= 2;
    }
    maxHeap[idx] = key;
}
int hTop() {
    return maxHeap[1];
}
void hPop() {
    if(heapSize == 0) return;
    maxHeap[1] = maxHeap[heapSize--];

    int idx = 1;
    int maxx, pos;
    while((2 * idx) <= heapSize) {
        maxx = maxHeap[2 * idx];
        pos = 2 * idx;

        if((2 * idx + 1) <= heapSize) {
            if(maxHeap[2 * idx + 1] > maxx) {
                maxx = maxHeap[2 * idx + 1];
                pos = 2 * idx + 1;
            }
        }

        if(maxHeap[idx] > maxx) break;

        int temp = maxHeap[pos];
        maxHeap[pos] = maxHeap[idx];
        maxHeap[idx] = temp;
        idx = pos;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    hInsert(999);
    hInsert(5);
    hInsert(-1);
    hInsert(10);
    hInsert(10);
    hInsert(11);
    hInsert(12);
    hInsert(2);
    
    cout << hTop() << "\n";
    hPop();
    cout << hTop() << "\n";
    hPop();
    cout << hTop() << "\n";

hPop();
    cout << hTop() << "\n";
hPop();
    cout << hTop() << "\n";


    return 0;
}