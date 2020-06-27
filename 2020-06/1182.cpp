#include <math.h>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <utility>
using namespace std;
int N, S;
int ans = 0;
vector<int> A;

void f(int idx, int pSum) {
	if (idx == N) {
		if (pSum == S)
			ans++;
		return;
	}
	f(idx + 1, pSum);
	f(idx + 1, pSum + A[idx]);
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	f(0, 0);
	if (S)
		cout << ans;
	else
		cout << ans - 1;
	return 0;
}