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
vector<int> v;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v.push_back(0);
	for (int i = 666; ; i++) {
		int t = i;
		while (t) {
			if (t % 1000 == 666) {
				v.push_back(i);
				break;
			}
			t /= 10;
		}
		if (v.size() == 10001)
			break;
	}
	sort(v.begin(), v.end());
	cout << v[N];
	return 0;
}