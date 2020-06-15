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


bool cmp(int &a, int &b) {
	return a > b;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;

	vector<int> A;
	for (int i = 0; i < str.size(); i++) {
		A.push_back(str[i] - '0');
	}
	sort(A.begin(), A.end(), cmp);
	for (int i = 0; i < A.size(); i++)
		cout << A[i];

	return 0;
}