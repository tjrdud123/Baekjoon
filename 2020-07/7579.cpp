#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N, M;
vector<int> A, C;
int cache[100][10001];
int ans = 2000000000;
int f(int idx, int cost) {
	if (idx == N)
		return 0;

	int &ret = cache[idx][cost];
	if (ret != -1)
		return ret;

	ret = f(idx + 1, cost);
	if (C[idx] <= cost)
		ret = max(ret, A[idx] + f(idx + 1, cost - C[idx]));
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	A.resize(N);
	C.resize(N);
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> C[i];

	for (int i = 1; ; i++) {
		if (f(0, i) >= M) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}