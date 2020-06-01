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
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (x1 == x2)
		cout << x3 << " ";
	else if (x1 == x3)
		cout << x2 << " ";
	else
		cout << x1 << " ";

	if (y1 == y2)
		cout << y3 << " ";
	else if (y2 == y3)
		cout << y1 << " ";
	else
		cout << y2 << " ";
	return 0;
}