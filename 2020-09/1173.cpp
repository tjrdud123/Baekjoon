#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;

	int mb = m;
	int cnt = 0;
	for (int i = 0; ; i++) {
		if (mb + T <= M) {
			mb += T;
			cnt++;
		}
		else {
			mb -= R;
			if (mb < m) mb = m;
		}
		if (cnt == N) {
			cout << i + 1;
			break;
		}
		if (i == 10000) {
			cout << "-1";
			break;
		}
	}
	return 0;
}