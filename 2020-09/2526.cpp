#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N, P;
vector<bool> isAppear;
vector<int> v;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	isAppear.assign(P, false);
	v.push_back(N);
	int cnt = 0;
	int T = N;
	while (true) {
		N *= T;
		N %= P;

		if (isAppear[N]) break;
		isAppear[N] = true;
		cnt++;
		v.push_back(N);
	}

	for (int i = 0; v.size(); i++) {
		if (v[i] == N) {
			cout << cnt - i + 1;
			break;
		}
	}

	return 0;
}