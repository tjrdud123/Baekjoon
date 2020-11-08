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
vector<long long> A;
long long dp[1100][1100];
long long sol(int idx, long long combo) {
    if(idx >= N) {
        return 0;
    }
    if(dp[idx][combo] != -999999999999) return dp[idx][combo];
    
    long long ret = A[idx] * combo;
    long long t = ret;
    ret = max(ret, t + sol(idx + 1, combo + 1LL));
    ret = max(ret, t + sol(idx + 2, 1LL));
    ret = max(ret, t + sol(idx + 3, 1LL));
    return dp[idx][combo] = ret;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < 1100; i++) {
        for(int j = 0; j < 1100; j++) {
            dp[i][j] = -999999999999;
        }
    }
    for(int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        A.push_back(t);
    }
    long long ans = 0;
    ans = max(ans, sol(0, 1));
  

    cout << ans;
    return 0;
}