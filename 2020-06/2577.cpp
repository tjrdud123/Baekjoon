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
int a, b, c;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b >> c;
	int n = a * b * c;
	vector<int> cnt(10, 0);
	while (n) {
		cnt[n % 10]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << "\n";
	return 0;
}