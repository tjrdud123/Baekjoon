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
int N, K, F;
bool isFriend[901][901];
bool visited[901];
vector<int> v;
void f(int src) {
	visited[src] = 1;
	v.push_back(src);
	
	if (v.size() == K) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << endl;
		exit(0);
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			int flag = 1;
			for (int j = 0; j < v.size(); j++) {
				if (isFriend[i][v[j]] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag)
				f(i);
		}
	}
	v.pop_back();
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N >> F;
	memset(isFriend, 0, sizeof(isFriend));
	
	for (int i = 0; i < F; i++) {
		int a, b;
		cin >> a >> b;
		isFriend[a][b] = 1;
		isFriend[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		v.clear();
		f(i);
	}
	cout << -1 << endl;
	return 0;
}