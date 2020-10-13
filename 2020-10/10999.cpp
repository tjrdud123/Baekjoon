#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
int N, M, K;
vector<LL> input, tree, lazy;
LL init(int start, int end, int node) {
    if(start == end) tree[node] = input[start];
    else {
        int mid = (start + end) / 2;
        tree[node] = init(start, mid, 2 * node + 1) + init(mid + 1, end, 2 * node + 2);
    }
    return tree[node];
}
LL sum(int left, int right, int start, int end, int node) {
    if(lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(left, right, start, mid, 2 * node + 1)
            + sum(left, right, mid + 1, end, 2 * node + 2);
}
void update(int left, int right, LL diff, int start, int end, int node) {
    if(lazy[node] != 0) {
        tree[node] += (LL)(end - start + 1) * lazy[node];
        if(start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    if(right < start || end < left) return;
    if(left <= start && end <= right) {
        tree[node] += (LL)(end - start + 1) * diff;
        if(start != end) {
            lazy[2 * node + 1] += diff;
            lazy[2 * node + 2] += diff;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(left, right, diff, start, mid, 2 * node + 1);
    update(left, right, diff, mid + 1, end, 2 * node + 2);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];    
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    input.resize(N);
    tree.resize(4 * N);
    lazy.assign(4 * N, 0);
    for(int i = 0; i < N; i++) cin >> input[i];

    init(0, N - 1, 0);
    for(int i = 0; i < M + K; i++) {
        int a, b, c;
        LL d;
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            update(b - 1, c - 1, d, 0, N - 1, 0);
        }
        else if(a == 2){
            cin >> b >> c;
            cout << sum(b - 1, c - 1, 0, N - 1, 0) << "\n";
        }
    }

    return 0;
}