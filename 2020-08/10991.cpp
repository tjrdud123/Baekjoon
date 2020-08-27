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
int N;
vector<vector<char> > A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int idx = N - 1;

	A.resize(N);
	for (int i = 0; i < N; i++) A[i].resize(2 * N - 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			A[i][j] = ' ';
		}
	}

	for (int i = 0; i < N; i++) {
		int n = i + 1;
		for (int j = 0; j < n; j++) {
			A[i][idx + 2*j] = '*';
		}
		idx--;
	}
	idx = N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < idx; j++) {
			cout << A[i][j];
		}
		idx++;
		cout << "\n";
	}

	return 0;
}