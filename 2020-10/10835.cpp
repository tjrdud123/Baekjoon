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
vector<int> leftC, rightC;
int dp[2001][2001];
int getMax(int a, int b) {
    int &ret = dp[a][b];
    if(a == N || b == N) return ret = 0;
    if(ret != -1) return ret;

    if(leftC[a] > rightC[b]) ret = max(dp[a][b], getMax(a, b + 1) + rightC[b]);

    ret = max(ret, getMax(a + 1, b));
    ret = max(ret, getMax(a + 1, b + 1));
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    leftC.resize(N);
    rightC.resize(N);

    for(int i = 0; i < N; i++) cin >> leftC[i];
    for(int i = 0; i < N; i++) cin >> rightC[i];
    memset(dp, -1, sizeof(dp));

    cout << getMax(0, 0);
    return 0;
}