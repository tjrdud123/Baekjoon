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
bool A[31];
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(A, 0, sizeof(A));
	
	int t;
	while (cin >> t) {
		A[t] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (A[i] == false) cout << i << "\n";
	}
	

	return 0;
}