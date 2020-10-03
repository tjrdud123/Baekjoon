#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i >= j && i * j <= N) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}