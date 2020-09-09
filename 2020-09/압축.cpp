#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <ctype.h>
using namespace std;
vector<int> solution(string msg) {
	map<string, int> m;
	string str = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 1; i < str.size(); i++) {
		m[str.substr(i, 1)] = i;
	}
	
	int idx = 27;
	vector<int> ret;
	for (int i = 0; i < msg.size(); ) {
		string w, t;
		for (int j = 1; ; j++) {
			t = msg.substr(i, j);
			if (m[t] != 0) {
				w = t;
			}
			else if(m[t] == 0) {
				i += (j - 1);
				break;
			}
			if (i + j > msg.size()) {
				i += (j - 1);
				break;
			}
		}
		ret.push_back(m[w]);
		m[t] = idx;
		idx++;
	}
	return ret;
}