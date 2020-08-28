#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
int A[20000], B[20000], C[20000];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(C, 0, sizeof(B));

	string a, b;
	cin >> a >> b;
	int idx = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		A[idx++] = a[i] - '0';
	}
	idx = 0;
	for (int i = b.size() - 1; i >= 0; i--) {
		B[idx++] = b[i] - '0';
	}
	for (int i = 0; i < (int)max(a.size(), b.size()); i++) {
		int value = A[i] + B[i] + C[i];
		C[i] = value % 10;
		C[i + 1] += value / 10;
	}
	for (int i = 0; i < 15000; i++) {
		if (C[i] > 9) {
			C[i + 1] += C[i] / 10;
			C[i] = C[i] % 10;
		}
	}
	for (int i = 19000; i >= 0; i--) {
		if (C[i] != 0) {
			for (int j = i; j >= 0; j--) cout << C[j];
			break;
		}
	}
	return 0;
}