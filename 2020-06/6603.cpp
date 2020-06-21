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
vector<int> A;
vector<int> picked;
void pick(int idx, int toPick) {
	if (toPick == 0) {
		for (int i = 0; i < picked.size(); i++) {
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = idx; i < N; i++) {
		picked.push_back(A[i]);
		pick(i + 1, toPick - 1);
		picked.pop_back();
	}
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> N;
		if (!N)
			break;
		A.clear();
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			A.push_back(t);
		}
		pick(0, 6);
		cout << "\n";
	}
	return 0;
}