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
vector<vector<int> > A;
int dp[16][16][3];
bool valid(int y, int x) {
    if(0 <= y && y < N && 0 <= x && x < N) {
        return A[y][x] == 0;
    }
    return false;
}
int getCase(int y, int x, int dir) {
    int &ret = dp[y][x][dir];
    if(ret != -1) return ret;

    int sum = 0;
    if(dir == 0) {
        if(valid(y, x + 2)) sum += getCase(y, x + 1, 0);
        if(valid(y, x + 2) && valid(y + 1, x + 2) && valid(y + 1, x + 1)) {
            sum += getCase(y, x + 1, 1);
        }
    }
    else if(dir == 1) {
        if(valid(y + 1, x + 2)) sum += getCase(y + 1, x + 1, 0);
        if(valid(y + 2, x + 1)) sum += getCase(y + 1, x + 1, 2);
        if(valid(y + 1, x + 2) && valid(y + 2, x + 2) && valid(y + 2, x + 1)) {
            sum += getCase(y + 1, x + 1, 1);
        }
    }
    else if(dir == 2) {
        if(valid(y + 2, x)) sum += getCase(y + 1, x, 2);
        if(valid(y + 2, x) && valid(y + 2, x + 1) && valid(y + 1, x + 1)) {
            sum += getCase(y + 1, x, 1);
        }
    }
    return ret = sum;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) {
        A[i].resize(N);
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[N - 1][N - 2][0] = dp[N - 2][N - 1][2] = dp[N - 2][N - 2][1] = 1;

    cout << getCase(0, 0, 0);
    return 0;
}