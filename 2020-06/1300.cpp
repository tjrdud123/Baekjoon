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
int N, K;
vector<int> A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	int left = 1;
	int right = K;
	int cnt = 0;
	int ans = 0;
	while (left <= right) {
		cnt = 0;
		int mid = (left + right) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < K)
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
			
	}
	cout << ans;
	return 0;
}