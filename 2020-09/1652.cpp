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
#include <queue>

using namespace std;
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
#include <queue>
using namespace std;
int N;
vector<vector<char> > A;
int garo() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (A[i][j] == '.' && A[i][j + 1] == '.') {
				ret++;
				for (int k = j; k < N; k++) {
					if (A[i][k] == '.') A[i][k] = 'X';
					else break;
				}
			}
		}
	}
	return ret;
}
int sero() {
	int ret = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (A[i][j] == '.' && A[i + 1][j] == '.') {
				ret++;
				for (int k = i; k < N; k++) {
					if (A[k][j] == '.') A[k][j] = 'X';
					else break;
				}
			}
		}
	}
	return ret;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(N);
		string str; cin >> str;
		for (int j = 0; j < N; j++) A[i][j] = str[j];
	}
	vector<vector<char> > B = A;
	cout << garo() << " ";
	A = B;
	cout << sero();
	return 0;
}
