#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, W;
vector<int> A;
int dp[1000][30];
int getMax(int cur, int idx, int w) {
    if(idx == N) return dp[idx][w] = 0;
    int &ret = dp[idx][w];
    if(ret != -1) return ret;

    if(cur == A[idx]) ret = max(ret, 1 + getMax(cur, idx + 1, w));
    else {
        if(w > 0) ret = max(ret, 1 + getMax(cur % 2 + 1, idx + 1, w - 1));
        ret = max(ret, getMax(cur, idx + 1, w));
    }
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W;
    A.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << getMax(1, 0, W);
    return 0;
}