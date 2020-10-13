#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, M, K;
long long INF = 1000000000000;
vector<vector<pair<int, long long>>> adj;
long long dp[10000][21];
bool visited[10000];
long long getCost(int here, int k)
{
    long long &ret = dp[here][k];
    if (ret < INF)
        return ret;

    for (int i = 0; i < adj[here].size(); i++)
    {
        int there = adj[here][i].first;
        long long cost = adj[here][i].second;
        if (visited[there] == false)
        {
            visited[there] = true;
            ret = min(ret, cost + getCost(there, k));
            if (k) ret = min(ret, getCost(there, k - 1));
            visited[there] = false;
        }
    }
    return ret;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    adj.resize(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i <= 20; i++)
        dp[N - 1][i] = 0LL;

    memset(visited, 0, sizeof(visited));
    visited[0] = true;

    cout << getCost(0, K);
    return 0;
}