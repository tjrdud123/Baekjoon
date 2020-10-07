#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
int MOD = 1000000;
int dp[5000];
string str;
vector<int> A;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    N = str.size();

    // 해석 불가능 한 경우
    if(str[0] == '0') {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < N - 1; i++) {
        if(str[i] == '0' && str[i + 1] == '0') {
            cout << 0;
            return 0;
        }   
    }

    for(int i = 0; i < N; i++) {
        if(str[i] == '0') A.back() *= 10;
        else A.push_back(str[i] - '0');
        if(A.back() > 26) {
            cout << 0;
            return 0;
        }
    }

    memset(dp, 0, sizeof(dp));
    N = A.size();
    dp[N - 1] = 1;
    if(A[N - 2] * 10 + A[N - 1] <= 26 && A[N - 2] < 10 && A[N - 1] < 10) dp[N - 2] = 2;
    else dp[N - 2] = 1;

    for(int i = N - 3; i >= 0; i--) {
        int t = A[i] * 10 + A[i + 1];
        if(t <= 26 && A[i] < 10 && A[i + 1] < 10) dp[i] += dp[i + 2];
        dp[i] += dp[i + 1];
        dp[i] %= MOD;
    }
    cout << dp[0];

    return 0;
}