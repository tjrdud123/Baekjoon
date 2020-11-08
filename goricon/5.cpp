#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, L;
vector<long long> A, total;
vector<double> x;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    total.assign(N , 0LL);
    x.assign(N, 0);
    for(int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        A.push_back(t);
    }
    total[N - 1] = A[N - 1];
    for(int i = N - 2; i >= 0; i--) {
        total[i] = total[i + 1] + A[i];
        
    }
    for(int i = 0; i < N; i++) {
        x[i] = total[i] / (N - i);
        x[i] += (double)(total[i] % (N-i)) / (N - 1); 
    }
    string ans = "stable";
    for(int i = 0; i < N - 1; i++) {
        int n = N - i - 1;
        if(x[i + 1] <= A[i] - L || x[i + 1] >= A[i] + L) ans = "unstable";
    }
    cout << ans;
    return 0;
}