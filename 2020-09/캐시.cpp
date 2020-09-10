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
bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}
int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) {
		return cities.size() * 5;
	}
	vector<pair<string, int> > cache;
	int ans = 0;
	for (int i = 0; i < cities.size(); i++) {
		string city = cities[i];
		for (int j = 0; j < city.size(); j++) {
			if ('A' <= city[j] && city[j] <= 'Z') city[j] += 32;
		}
		bool isHit = false;
		for (int j = 0; j < cache.size(); j++) {
			if (city == cache[j].first) {
				isHit = true;
				cache[j].second = i;
				break;
			}
		}
		if (isHit) ans++;
		else {
			ans += 5;
			if (cache.size() < cacheSize) cache.push_back(make_pair(city, i));
			else cache[0] = make_pair(city, i);
		}
		sort(cache.begin(), cache.end(), cmp);
	}
	return ans;
}