#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
bool visited[100][100];
vector<double> prob(4, 0);
double ans = 0.0;
void f(double pr, int r, int c, int toMove) {
	if (visited[r][c]) {
		return;
	}
	if (toMove == 0) {
		ans += pr;
		return;
	}
		
	visited[r][c] = true;
	f(pr * prob[0], r, c + 1, toMove - 1);
	f(pr * prob[1], r, c - 1, toMove - 1);
	f(pr * prob[2], r + 1, c, toMove - 1);
	f(pr * prob[3], r - 1, c, toMove - 1);
	visited[r][c] = false;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 4; i++)
		cin >> prob[i];
	for (int i = 0; i < 4; i++)
		prob[i] /= 100.0;
	f(1.0, 50, 50, N);
	cout.precision(11); cout << fixed;
	cout << ans;
	return 0;
}