#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N;
vector<double> A;
bool cmp(double a, double b) {
    return a > b;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    double ans = 0.0;
    for(int i = 0; i < N; i++) {
        double t;
        cin >> t;
        A.push_back(t);
    }
    sort(A.begin(), A.end(), cmp);
    ans = A[0];
    
    for(int i = A.size()- 1; i > 0; i--) {
        ans += (A[i] / 2);
    }
    cout << ans;
    return 0;
}