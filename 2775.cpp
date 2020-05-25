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
int T, K, N;
int A[20][20];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 1; i <= 14; i++) {
		A[0][i] = i;
		A[i][0] = 0;
	}
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			A[i][j] = A[i - 1][j] + A[i][j - 1];
		}
	}
	cin >> T;
	while (T--) {
		cin >> K >> N;
		cout << A[K][N] << endl;
	}
	return 0;
}