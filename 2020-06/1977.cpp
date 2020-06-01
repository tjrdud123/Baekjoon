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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	int sum = 0;
	int min = 0;
	int flag = 0;
	for (int i = a; i <= b; i++) {
		double t1 = sqrt(i);
		int t2 = (int)t1;
		if (t1 == t2) {
			if (flag == 0) {
				min = i;
				flag = 1;
			}
			sum += i;
		}
	}
	if (flag) {
		cout << sum << "\n";
		cout << min;
	}
	else
		cout << -1;
	return 0;
}