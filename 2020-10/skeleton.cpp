#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> A;
int main(void) {
    cin >> N >> M;
    A.resize(N + 1);
    
    for(int i = 0; i <= N; i++) A[i] = i;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int t = A[a];
        A[a] = A[b];
    }
    for(int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    return 0;
}