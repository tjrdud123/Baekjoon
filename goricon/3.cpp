#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, H, W;
vector<string> A;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> H >> W; 
    A.resize(H);
    for(int i = 0; i < H; i++) {
        cin >> A[i];
    }
    for(int j = 0; j < N * W; j++) {
        for(int i= 0; i < H; i++) {
            if(A[i][j] != '?') {
                A[0][j] = A[i][j];
            }
        }
    }
    string ans;
    for(int i = 0; i < N; i++) {
        char ch = '?';
        for(int j = 0; j < W; j++) {
            if(A[0][i * W + j] != '?') ch = A[0][i * W + j];
        }
        ans += ch;
    }
    cout << ans;
    return 0;
}