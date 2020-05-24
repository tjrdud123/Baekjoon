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
long long N;
queue<long long> q;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	if (N <= 10LL) {
		cout << N << endl;
		return 0;
	}
	else if (N == 1022) {
		cout << 9876543210 << endl;
		return 0;
	}
	else if (N >= 1023) {
		cout << -1 << endl;
		return 0;
	}
	long long cnt = -1;
	for (long long i = 0ll; i < 10ll; i++) {
		q.push(i);
		cnt++;
	}
	while (1) {
		int n = q.front();
		q.pop();
		if (n == 9876543210ll) {
			cout << -1 << endl;
			return 0;
		}
		int temp = n % 10;
		n *= 10;
		for (int i = 0; i < temp; i++) {
			q.push(n + i);
			cnt++;
			if (cnt == N) {
				cout << n + i << endl;
				return 0;
			}
		}
	}
	return 0;
}