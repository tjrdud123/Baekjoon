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
	map<string, int> m;
	m["black"] = 0;
	m["brown"] = 1;
	m["red"] = 2;
	m["orange"] = 3;
	m["yellow"] = 4;
	m["green"] = 5;
	m["blue"] = 6;
	m["violet"] = 7;
	m["grey"] = 8;
	m["white"] = 9;
	int v[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << ((long long)m[s1] * 10 + (long long)m[s2]) * (long long)v[m[s3]] << endl;


	return 0;
}