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
vector<pair<int, int> > infos;
int solution(vector<string> lines) {
	int h = 3600000, m = 60000, s = 1000;
	for (int i = 0; i < lines.size(); i++) {
		string line = lines[i];
		int HH = stoi(line.substr(11, 2)) * h;
		int MM = stoi(line.substr(14, 2)) * m;
		int SS = stoi(line.substr(17, 2)) * s;
		int MS = stoi(line.substr(20, 3));
		int end = HH + MM + SS + MS;

		int N = line.size();
		int et = (int)(stod(line.substr(24, N - 25)) * 1000);
		int start = end - et + 1;
		infos.push_back(make_pair(start, end));
	}

	int ans = 0;
	for (int i = 0; i < infos.size(); i++) {
		int start = infos[i].second;
		int end = start + 999;

		int cnt = 1;
		for (int j = i + 1; j < infos.size(); j++) {
			if (end + 3000 < infos[j].second) break;
			if (end < infos[j].first) continue;
			cnt++;
		}
		ans = max(ans, cnt);
	}

	return ans;
}