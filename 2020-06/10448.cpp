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
int T, N;
vector<int> A;
int flag = 0;
void f(int n, int a) {
	if (a == 0) {
		if (n == 0)
			flag = 1;
		return;
	}
	for (int i = 1; i < A.size(); i++) {
		f(n - A[i], a - 1);
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	A.push_back(0);
	for (int i = 1; ; i++) {
		A.push_back(A[i - 1] + i);
		if (A[i] >= 1000)
			break;
	}

	cin >> T;
	while (T--) {
		cin >> N;
		flag = 0;
		f(N, 3);
		if (flag)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}