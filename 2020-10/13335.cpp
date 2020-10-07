#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int N, W, L;
vector<int> trucks;
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W >> L;
    trucks.resize(N);
    for(int i = 0; i < N; i++) cin >> trucks[i];

    int idx = 0, time = 0, cnt = 0, sum = 0;

    queue<int> bridge;
    while(cnt < N) {
        if(bridge.size() >= W) {
            if(bridge.front() != 0) cnt++;
            sum -= bridge.front();
            bridge.pop();
        }
        if(idx < N && trucks[idx] + sum <= L) {
            sum += trucks[idx];
            bridge.push(trucks[idx++]);
        }
        else bridge.push(0);
        
        time++;
    }
    cout << time;
    return 0;
}