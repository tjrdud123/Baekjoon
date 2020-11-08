#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, M, L;
vector<bool> y;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {

    }
    cin >> L;
    int ans = L;
    y.assign(N + 1, false);
    for(int i = 0; i < L; i++) {
        int t;
        cin >> t;
        y[t] = true;
    }
    return 0;
}