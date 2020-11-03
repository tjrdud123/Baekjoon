#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, root;
int number = 1;
vector<int> ll, rr, col;
vector<bool> isRoot, visited;
vector<vector<int>> depth;
void inorder(int node) {
    if(ll[node] != -1) inorder(ll[node]);
    col[node] = number++;
    if(rr[node] != -1) inorder(rr[node]);
}
void dfs(int n, int d) {
    visited[n] = true;
    depth[d].push_back(n);
    if(ll[n] != -1 && visited[ll[n]] == false) dfs(ll[n], d + 1);
    if(rr[n] != -1 && visited[rr[n]] == false) dfs(rr[n], d + 1);
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    ll.resize(N + 1);
    rr.resize(N + 1);
    col.resize(N + 1);
    depth.resize(N + 1);
    isRoot.assign(N + 1, true);
    visited.assign(N + 1, false);
    for(int i = 0; i < N; i++) {
        int n, l, r;
        cin >> n >> l >> r;
        ll[n] = l;
        rr[n] = r;
        if(l != -1) isRoot[l] = false;
        if(r != -1) isRoot[r] = false;
    }
    for(int i = 1; i <= N; i++) {
        if(isRoot[i]) {
            root = i;
            break;
        }
    }
    inorder(root);
    dfs(root, 1);
    int level;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int minn = 9999999;
        int maxx = -1;
        for(int j = 0; j < depth[i].size(); j++) {
            minn = min(minn, col[depth[i][j]]);
            maxx = max(maxx, col[depth[i][j]]);
        }
        if(ans < maxx - minn + 1) {
            level = i;
            ans = maxx - minn + 1;
        }
    }
    cout << level << " " << ans;
    return 0;
}