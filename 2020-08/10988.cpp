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
vector<char> A, B;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) A.push_back(str[i]);
	B = A;
	reverse(A.begin(), A.end());
	int flag = 1;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != B[i]) flag = 0;
	}
	if (flag) cout << 1;
	else cout << 0;


	return 0;
}