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
vector<vector<int>> adj, anc;
vector<int> depth;
vector<bool> visited;
void makeTree(int n, int d) {
    depth[n] = d;
    visited[n] = true;
    for(int i = 0; i < adj[n].size(); i++) {
        int there = adj[n][i];
        if(visited[there]) continue;
        anc[there][0] = n;
        makeTree(there, d + 1);
    }
}
int LCA(int a, int b) {
    if(a == b) return a;
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i = 0; ; i++) {
        if(diff == 0) break;
        if(diff % 2) a = anc[a][i];
        diff /= 2;
    }
    
    if(a != b) {
        for(int i = 19; i >= 0; i--) {
            if(anc[a][i] != -1 && anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        a = anc[a][0];
    }
    return a;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    adj.resize(N + 1);
    depth.resize(N + 1);
    anc.resize(N + 1);
    visited.assign(N + 1, false);
    for(int i = 0; i <= N; i++) anc[i].assign(20, -1);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    makeTree(1, 0);
    
    for(int k = 0; k < 19; k++) {
        for(int n = 1; n <= N; n++) {
            if(anc[n][k] != -1) anc[n][k + 1] = anc[anc[n][k]][k];
        }
    }
    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
    return 0;
}