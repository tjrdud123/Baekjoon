#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N, M, R;
int INF = 987654321;
vector<int> V;
vector<vector<int>> adj;
vector<int> dijkstra(int src) {
    vector<int> dist(N, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));

    while(pq.empty() == false) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < N; i++) {
            if(adj[here][i] == INF) continue;
            int nextDist = cost + adj[here][i];

            if(dist[i] > nextDist) {
                dist[i] = nextDist;
                pq.push(make_pair(-nextDist, i));
            }
        }
    }
    return dist;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    adj.resize(N);
    V.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
        adj[i].assign(N, INF);
    }
    for(int i = 0; i < R; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a][b] = w;
        adj[b][a] = w;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        vector<int> dist = dijkstra(i);
        int sum = 0;
        for(int j = 0; j < dist.size(); j++) {
            if(dist[j] <= M) sum += V[j];
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}