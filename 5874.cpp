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
string str;
vector<int> A;
vector<int> B;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(' && str[i + 1] == '(')
			A.push_back(i);
		if (str[i] == ')' && str[i + 1] == ')')
			B.push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = B.size() - 1; j >= 0; j--) {
			if (A[i] < B[j])
				ans++;
			else
				break;
		}
	}
	cout << ans << endl;
	return 0;
}