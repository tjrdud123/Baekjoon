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
vector<int> dp;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int temp;
	cin >> temp;
	dp.push_back(temp);
	for (int i = 1; i < N; i++) {
		cin >> temp;
		if (dp.back() < temp)
			dp.push_back(temp);
		else {
			vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), temp);
			*iter = temp;
		}
	}

	cout << dp.size() << endl;

	return 0;
}