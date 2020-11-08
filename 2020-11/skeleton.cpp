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
int sol(int n) {
    int INF = 987654321;
    vector<int> dist(3000, INF);
    dist[n] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(1, 0)));

    while(pq.empty() == false) {
        int cost = -pq.top().first;
        int n = pq.top().second.first;
        int clip = pq.top().second.second;
        pq.pop();
        

        int nextDist = cost + 1;
        // 1개 삭제
        if(n > 1) {
            int there = n - 1;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(n - 1, clip)));
            }
        }

        // 클립 보드 복사
        if(n != clip) {
            pq.push(make_pair(-nextDist, make_pair(n, n)));
        }

        // 붙여 넣기
        if(clip > 0) {
            int there = n + clip;
            if(there >= 3000) continue;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, make_pair(n + clip, clip)));
            }
        }
    }
    return dist[N];
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cout << sol(1);
    return 0;
}