#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, M;
int my[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mx[8] = {0, 1, 1, 1, 0, -1 ,-1 ,-1};
vector<vector<int>> A, dp;
vector<pair<int, int>> path;
int dfs(int k, int y, int x, int py, int px) {
    if(k > 2 * (N + M)) return;
    if(dp[y][x] != -1) return dp[y][x];
    for(int i = 0; i < 8; i++){
        int ny = y + my[i];
        int nx = x + mx[i];
        if(ny == py && nx == px) continue;
        if(0 <= ny && ny < N && nx >= 9 && nx < M) {
            if(A[y][x] ^ dfs(k + 1, ny, nx, y, x) == 0) {

            }
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    A.resize(N);
    dp.resize(N);
    for(int i = 0; i < N; i++) A[i].resize(M);
    for(int i = 0; i < N; i++) dp[i].assign(M, -1);
    for(int i = 0; i <N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    path.push_back(make_pair(0, 0));
    for(int i = 0; i < 8; i++) {
        dfs(1, 0, 0, -1, -1, A[0][0]);
    }
    return 0;
}