#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int N;
vector<int> cnt;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int ans = 0;
	cnt.assign(7, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 7; j++) cnt[j] = 0;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cnt[a]++; cnt[b]++; cnt[c]++; cnt[d]++;

		vector<pair<int, int> > v;
		for (int j = 1; j <= 6; j++) {
			if(cnt[j])
				v.push_back(make_pair(j, cnt[j]));
		}
		
		if (v.size() == 1) {
			ans = max(ans, 50000 + 5000 * v[0].first);
		}
		else if (v.size() == 2 && (v[0].second == 3 || v[1].second == 3)) {
			for (int k = 0; k < 2; k++) {
				if (v[k].second == 3) {
					ans = max(ans, v[k].first * 1000 + 10000);
					break;
				}
			}
		}
		else if (v.size() == 2 && (v[0].second == 2 && v[1].second == 2)) {
			ans = max(ans, 2000 + v[0].first * 500 + v[1].first * 500);
		}
		else if (v.size() == 3) {
			for (int k = 0; k < 3; k++) {
				if (v[k].second == 2) {
					ans = max(ans, v[k].first * 100 + 1000);
					break;
				}
			}
		}
		else {
			ans = max(ans, v[3].first * 100);
		}
	}
	cout << ans;
	return 0;
}