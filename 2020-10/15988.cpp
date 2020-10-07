#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int T;
int MOD = 1000000009;
int dp[1000001];
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
        dp[i] += dp[i - 3];
        dp[i] %= MOD;
    }
    while(T--) {
        int N; cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}