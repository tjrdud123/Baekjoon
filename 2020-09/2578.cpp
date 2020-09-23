#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
pair<int, int> A[26];
vector<int> calls;
int row[6], col[6];
int check() {
	int ret = 0;
	for (int i = 0; i < 6; i++) {
		if (row[i] == 5) ret++;
		if (col[i] == 5) ret++;
	}
	return ret;
}
int main(void) {
	memset(row, 0, sizeof(row));
	memset(row, 0, sizeof(col));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int t; cin >> t;
			A[t] = make_pair(i, j);
		}
	}
	for (int i = 0; i < 25; i++) {
		int t; cin >> t;
		calls.push_back(t);
	}

	for (int i = 0; i < 25; i++) {
		int n = calls[i];
		row[A[n].first]++;
		col[A[n].second]++;
		
		if (A[n].first == A[n].second) row[5]++;
		if (A[n].first + A[n].second == 4) col[5]++;
		
		if (check() >= 3) {
			
			cout << i + 1;
			break;
		}
	}


	return 0;
}