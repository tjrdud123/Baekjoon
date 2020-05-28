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
int N, M;
vector<bool> picked;
void f(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 1; i <= N; i++) {
			if (picked[i])
				cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx + 1; i <= N; i++) {
		if (!picked[i]) {
			picked[i] = true;
			f(i, cnt + 1);
			picked[i] = false;
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	picked.assign(N + 1, 0);
	f(0, 0);
	return 0;
}