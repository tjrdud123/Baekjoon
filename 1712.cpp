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
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C) {
		cout << -1 << endl;
	}
	else
		cout << A / (C - B) + 1 << endl;
	return 0;
}