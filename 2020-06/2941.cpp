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
	string str;
	cin >> str;
	int cnt = 0;
	vector<string> v;
	vector<string> z;
	v.push_back("c=");
	v.push_back("c-");
	v.push_back("d-");
	v.push_back("lj");
	v.push_back("nj");
	v.push_back("s=");
	v.push_back("z=");
	z.push_back("dz=");
	for (int i = 0; i < str.size(); i++) {
		string ts = str.substr(i, 2);
		cnt++;
		for (int j = 0; j < v.size(); j++) {
			if (ts == v[j]) {
				i++;
				break;
			}
		}
		ts = str.substr(i, 3);
		if (ts == z[0]) {

			i += 2;
		}
	}
	cout << cnt;
	return 0;
}