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
vector<vector<int>> A;
bool checkRange(int y, int x) {
	int N = A.size(); int M = A[0].size();
	if (0 <= y && y < N && 0 <= x && x < M) return true;
	return false;
}

int getType(int y, int x) {
	int num = A[y][x];

	if (checkRange(y + 1, x)) {
		if (A[y + 1][x] != num) return -1;
		if (checkRange(y + 1, x + 1) && checkRange(y + 1, x + 2)) {
			if (A[y + 1][x + 1] == num && A[y + 1][x + 2] == num) return 0;
		}
		if (checkRange(y + 1, x - 1) && checkRange(y + 1, x + 1)) {
			if (A[y + 1][x - 1] == num && A[y + 1][x + 1] == num) return 1;
		}
		if (checkRange(y + 1, x - 1) && checkRange(y + 1, x - 2)) {
			if (A[y + 1][x - 1] == num && A[y + 1][x - 2] == num) return 2;
		}
		if (checkRange(y + 2, x)) {
			if (A[y + 2][x] != num) return -1;
			if (checkRange(y + 2, x + 1) && A[y + 2][x + 1] == num) return 3;
			if (checkRange(y + 2, x - 1) && A[y + 2][x - 1] == num) return 4;
		}
	}
	return -1;
}
bool isFall(int y, int x) {
	if (A[y][x] != 0) return false;
	for (int i = y - 1; i >= 0; i--) {
		if (A[i][x] != 0) return false;
	}
	return true;
}
void remove(int y, int x, int type) {
	if (type <= 2) {
		A[y][x] = A[y + 1][x] = 0;
		if (type == 0) A[y + 1][x + 1] = A[y + 1][x + 2] = 0;
		else if (type == 1) A[y + 1][x - 1] = A[y + 1][x + 1] = 0;
		else if (type == 2) A[y + 1][x - 1] = A[y + 1][x - 2] = 0;
	}
	else {
		A[y][x] = A[y + 1][x] = A[y + 2][x] = 0;
		if (type == 3) A[y + 2][x + 1] = 0;
		else if (type == 4) A[y + 2][x - 1] = 0;
	}
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	A = board;

	int N = A.size(), M = A[0].size();
	while (true) {
		int flag = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (A[i][j] != 0) {
					int type = getType(i, j);
					if (type != -1) cout << type << "\n";
					if (type == 0) {
						if (isFall(i, j + 1) && isFall(i, j + 2)) {
							
							flag = 0;
						}
					}
					else if (type == 1) {
						if (isFall(i, j + 1) && isFall(i, j - 1)) {
							
							flag = 0;
						}
					}
					else if (type == 2) {
						if (isFall(i, j - 1) && isFall(i, j - 2)) {
							
							flag = 0;
						}
					}
					else if (type == 3) {
						if (isFall(i, j + 1) && isFall(i + 1, j + 1)) {
							
							flag = 0;
						}
					}
					else if (type == 4) {
						if (isFall(i, j - 1) && isFall(i + 1, j - 1)) {
							
							flag = 0;
						}
					}
					if (!flag) {
						remove(i, j, type);
						break;
					}
				}
			}
			if (!flag) break;
		}
		if (flag) break;
		else answer++;
	}

	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	return 0;
}