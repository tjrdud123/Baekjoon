#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
void dfs(int from, int n) {
    visited[n] = true;
    parent[n] = from;

    for(int i = 0; i < adj[n].size(); i++) {
        int there = adj[n][i];
        if(visited[there] == false) dfs(n, there);
    }
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    adj.resize(N + 1);
    parent.resize(N + 1);
    visited.assign(N + 1, false);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(-1, 1);
    for(int i = 2; i <= N; i++) cout << parent[i] << "\n";
    return 0;
}