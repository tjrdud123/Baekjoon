#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> H;
vector<bool> visited;
int dfs(int src) {
    visited[src] = true;
    int ret = 0;
    for(int i = 0; i < adj[src].size(); i++) {
        int there = adj[src][i].first;
        int cost = adj[src][i].second;
        if(visited[there] == false) {
            int dist = cost + dfs(there);
            ret = max(ret, dist);
            H[src].push_back(dist);
        }
    }
    return ret;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    adj.resize(N + 1);
    H.resize(N + 1);
    visited.assign(N + 1, false);
    for(int i = 1; i <= N; i++) {
        int u, v, w;
        cin >> u;
        while(true) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back(make_pair(v, w));
        }
    }
    int ans = dfs(1);
    for(int i = 1; i <= N; i++) {
        sort(H[i].begin(), H[i].end());
        int idx = H[i].size() - 1;
        if(H[i].size() >= 2) ans = max(ans, H[i][idx] + H[i][idx - 1]);
    }
    cout << ans;
    return 0;
}