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
vector<vector<char> > A;
int ans = 1;
void f() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c = A[i][j];
			int t = 0;
			for (int k = j; k < N; k++) {
				if (A[i][k] == c)
					t++;
				else
					break;
			}
			ans = max(ans, t);
			t = 0;
			for (int k = i; k < N; k++) {
				if (A[k][j] == c)
					t++;
				else
					break;
			}
			ans = max(ans, t);
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		A[i].resize(N);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
			A[i][j] = str[j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(A[i][j], A[i][j + 1]);
			f();
			swap(A[i][j], A[i][j + 1]);
		}
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			swap(A[i][j], A[i + 1][j]);
			f();
			swap(A[i][j], A[i + 1][j]);
		}
	}
	cout << ans;
	return 0;
}