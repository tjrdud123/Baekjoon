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
int N;
vector<int> ans;
int cnt = 0;
void f(int n) {
	if (n == N) {
		cnt++;
		return;
	}
	
	for (int j = 0; j < N; j++) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (ans[i] == j)
				flag = false;
			if (abs(j - ans[i]) == abs(n - i))
				flag = false;
		}
		if (flag) {
			ans[n] = j;
			f(n + 1);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	ans.resize(N);
	f(0);
	cout << cnt << "\n";
	return 0;
}