#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
vector<vector<int>> A;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	A.resize(str1.size());
	for (int i = 0; i < A.size(); i++) A[i].resize(str2.size());

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			if (i == 0 || j == 0) {
				A[i][j] = (str1[i] == str2[j]);
			}
			else {
				if (str1[i] == str2[j]) A[i][j] = A[i - 1][j - 1] + 1;
				else A[i][j] = 0;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			ans = max(ans, A[i][j]);
			//cout << A[i][j] << " ";
		} 
		//cout << "\n";
	}
	cout << ans;
	return 0;
}