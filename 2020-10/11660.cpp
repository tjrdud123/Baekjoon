#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int> > A, S;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    A.resize(N);
    S.resize(N);
    for(int i = 0; i < N; i++) {
        A[i].resize(N);
        S[i].resize(N);
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    S[0][0] = A[0][0];
    for(int i = 1; i < N; i++) S[i][0] = S[i - 1][0] + A[i][0];
    for(int j = 1; j < N; j++) S[0][j] = S[0][j - 1] + A[0][j];
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            S[i][j] = A[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }

    for(int i = 0; i < M; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--; y1--; x2--; y2--;

        int ans = S[y2][x2];
        if(x1 > 0) {
            ans -= S[y2][x1 - 1];
        }
        if(y1 > 0) {
            ans -= S[y1 - 1][x2];
        }
        if(x1 > 0 && y1 > 0) ans += S[y1 - 1][x1 - 1];
        cout << ans << "\n";
    }

    return 0;
}