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
vector<vector<pair<int, int>>> adj;
vector<int> depth, dist;
vector<vector<int>> anc;
void dfs(int n, int d, int c) {
    depth[n] = d;
    for(int i = 0; i < adj[n].size(); i++) {
        int there = adj[n][i].first;
        if(depth[there] != -1) continue;
        dist[there] = c + adj[n][i].second;
        anc[there][0] = n;
        dfs(there, d + 1, c + adj[n][i].second);
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
    if(a == b) return a;
    for(int k = 19; k >= 0; k--) {
        if(anc[a][k] != -1 && anc[a][k] != anc[b][k]) {
            a = anc[a][k];
            b = anc[b][k];
        }
    }
    a = anc[a][0];
    return a;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    adj.resize(N + 1);
    depth.assign(N + 1, -1);
    dist.resize(N + 1);
    dist[1] = 0;
    anc.resize(N + 1);
    for(int i = 0; i <= N; i++) anc[i].assign(20, -1);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dfs(1, 0, 0);

    for(int k = 0; k < 19; k++) {
        for(int n = 1; n <= N; n++) {
            if(anc[n][k] != -1) anc[n][k + 1] = anc[anc[n][k]][k];
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        int ans = dist[a] + dist[b] - 2 * dist[lca];
        cout << ans << "\n";
    }
    return 0;
}