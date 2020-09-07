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
int binarySearch(vector<int> v, int target) {
	int N = v.size();
	int left = 0, right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (v[mid] > target) right = mid - 1;
		else if (v[mid] < target) left = mid + 1;
		else return mid;
	}
	return -1;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	return 0;
}