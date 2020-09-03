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
bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.second > p2.second;
}
bool cmp2(pair<int, int>& p1, pair<int, int>& p2) {
	return p1.first < p2.first;
}
int solution(vector<int> food_times, long long k) {
	int N = food_times.size();
	vector<pair<int, int>> sorted;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sorted.push_back(make_pair(i + 1, food_times[i]));
		sum += (long long)food_times[i];
	}
	sort(sorted.begin(), sorted.end(), cmp);
	if (sum <= k) return -1;
	int lap = 0;
	while ((long long)N <= k) {
		k -= (long long)N;
		lap++;
		while (sorted[N - 1].second == lap) {
			sorted.pop_back();
			N--;
		}
	}
	sort(sorted.begin(), sorted.end(), cmp2);
	return sorted[k].first;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	return 0;
}