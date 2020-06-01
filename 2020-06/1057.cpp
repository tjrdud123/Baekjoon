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
int N, a, b;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> a >> b;
	int cnt = 0;
	while (a != b) {
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}