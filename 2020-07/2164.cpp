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
queue<int> q;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);

	if (N == 1) {
		cout << 1;
		return 0;
	}

	while (1) {
		q.pop();
		if (q.size() == 1) {
			cout << q.front();
			return 0;
		}
		int t = q.front();
		q.pop();
		q.push(t);
	}

	return 0;
}