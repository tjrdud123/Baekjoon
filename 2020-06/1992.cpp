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
vector<vector<int> > A;
void f(int r, int c, int n) {
	if (n == 1) {
		cout << A[r][c];
		return;
	}
	int color = A[r][c];
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[r + i][c + j] != color) {
				flag = 1;
				break;
			}
		}
	}
	
	if (flag) {
		cout << "(";
		f(r, c, n / 2);
		f(r, c + n / 2, n / 2);
		f(r + n / 2, c, n / 2);
		f(r + n / 2, c + n / 2, n / 2);
		cout << ")";
	}
	else {
		cout << color;
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
		for (int j = 0; j < N; j++) {
			A[i][j] = str[j] - '0';
		}
	}
	f(0, 0, N);

	return 0;
}