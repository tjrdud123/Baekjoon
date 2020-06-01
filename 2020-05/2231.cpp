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
char A[3000][3000];
void f(int n, int r, int c) {
	if (n == 1) {
		A[r][c] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			f(div, r + (div * i), c + (div * j));
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t = i;
		int t2 = t;
		while (t) {
			t2 += t % 10;
			t /= 10;
		}
		if (t2 == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}