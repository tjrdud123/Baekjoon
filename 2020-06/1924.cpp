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
int x, y;
int m[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y;
	int day = 0;
	for (int i = 1; i < x; i++)
		day += m[i];
	day += y;
	day--;
	int s = day % 7;
	if (s == 0)
		cout << "MON";
	else if (s == 1)
		cout << "TUE";
	else if (s == 2)
		cout << "WED";
	else if (s == 3)
		cout << "THU";
	else if (s == 4)
		cout << "FRI";
	else if (s == 5)
		cout << "SAT";
	else if (s == 6)
		cout << "SUN";
	return 0;
}