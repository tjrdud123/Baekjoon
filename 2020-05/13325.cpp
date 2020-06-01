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
int H;
vector<int> tree;
int myPow(int n) {
	int ret = 1;
	for (int i = 0; i < n; i++)
		ret *= 2;
	return ret;
}
int f(int idx) {
	if (idx >= myPow(H) - 1) {
		return tree[idx];
	}
	int leftV = f(2 * idx + 1);
	int rightV = f(2 * idx + 2);
	//cout << "[" << idx << "]" << "left : " << leftV << " rightV : " << rightV << endl;
	int maxV = max(leftV, rightV);
	if (leftV < maxV) {
		tree[2 * idx + 1] += (maxV - leftV);
	}
	else if (rightV < maxV) {
		tree[2 * idx + 2] += (maxV - rightV);
	}
	return maxV + tree[idx];
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> H;
	int N = 0;
	for (int i = 1; i <= H; i++) {
		N += myPow(i);
	}
	tree.push_back(0);
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		tree.push_back(temp);
	}
	
	
	f(0);
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans += tree[i];
	cout << ans << endl;
	return 0;
}