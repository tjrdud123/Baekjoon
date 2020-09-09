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
typedef struct elem {
	int idx;
	string head, number, tail;
} elem;
vector<elem> v;
bool cmp(elem v1, elem v2) {
	for (int i = 0; i < v1.head.size(); i++) {
		if ('A' <= v1.head[i] && v1.head[i] <= 'Z') v1.head[i] += 32;
		
	}
	for (int i = 0; i < v2.head.size(); i++) {
		
		if ('A' <= v2.head[i] && v2.head[i] <= 'Z') v2.head[i] += 32;
	}
	if (v1.head == v2.head) {
		int n1 = stoi(v1.number);
		int n2 = stoi(v2.number);
		if (n1 == n2) {
			return v1.idx < v2.idx;
		}
		else return n1 < n2;
	}
	else return v1.head < v2.head;
}
vector<string> parse(string name) {
	vector<string> ret(3);
	int N = name.size();
	int i;
	for (i = 0; i < N; i++) {
		char ch = name[i];
		if ('0' <= ch && ch <= '9') {
			ret[0] = name.substr(0, i);
			break;
		}
	}
	
	for (int j = 0; i + j <= N; j++) {
		char ch = name[i + j];
		if (ch < '0' || ch > '9') {
			ret[1] = name.substr(i, j);
			i += j;
			break;
		}
	}
	ret[2] = name.substr(i, 100);
	return ret;
}
vector<string> solution(vector<string> files) {
	int N = files.size();
	v.resize(N);
	for (int i = 0; i < N; i++) {
		vector<string> temp = parse(files[i]);
		v[i].idx = i;
		v[i].head = temp[0];
		v[i].number = temp[1];
		v[i].tail = temp[2];
		//cout << v[0].first << " " << v[0].second.first << " " << v[0].second.second << "\n";
	}
	sort(v.begin(), v.end(), cmp);
	vector<string> ans(N);
	for (int i = 0; i < N; i++) {
		ans[i] += v[i].head;
		ans[i] += v[i].number;
		ans[i] += v[i].tail;
		//cout << ans[i] << "\n";
	}
	return ans;
}