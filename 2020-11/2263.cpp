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
vector<int> inorder, postorder, getIdx;
void pre(int inS, int inE, int postS, int postE) {
    int lCnt, rCnt;
    int root = postorder[postE];
    int idx = getIdx[root];
    
    lCnt = idx - inS;
    rCnt = inE - idx;
    
    cout << root << " ";

    if(lCnt) {
        pre(inS, idx - 1, postS, postS + lCnt - 1);
    }
    if(rCnt) {
        pre(idx + 1, inE, postS + lCnt, postE - 1);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    inorder.resize(N);
    postorder.resize(N);
    getIdx.resize(N + 1);
    for(int i = 0; i < N; i++) {
        cin >> inorder[i];
        getIdx[inorder[i]] = i;
    }
    for(int i = 0; i < N; i++) cin >> postorder[i];
    pre(0, N - 1, 0, N - 1);
    return 0;
}