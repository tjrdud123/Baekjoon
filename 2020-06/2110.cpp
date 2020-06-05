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
int N, C;
vector<int> A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());
	
	int left = 1;
	int right = A.back() - A.front();
	
	int d = 0;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int start = A[0];
		int cnt = 1;

		for (int i = 1; i < N; i++) {
			d = A[i] - start;
			if (mid <= d) {
				cnt++;
				start = A[i];
			}
		}

		if (cnt >= C) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}