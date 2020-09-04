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
#define LEFT 1
#define RIGHT 2
using namespace std;

bool verify(int n, vector<vector<pair<int, int> > > wall) {
	for (int y = 0; y < n + 1; y++) {
		for (int x = 0; x < n + 1; x++) {
			if (y > 0 && wall[y][x].first == 1 && wall[y][x].second == 0) {
				return false;
			}
			if (wall[y][x].second == RIGHT) {
				if (wall[y][x].first < 2 && 
					wall[y][x + 1].first < 2) return false;
			}
			if (wall[y][x].second == LEFT + RIGHT) {
				if (wall[y][x + 1].second == LEFT) {
					if (wall[y][x].first < 2 && 
						wall[y][x + 1].first < 2) return false;
				}
			}
		}
	}
	return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<pair<int, int> > > wall;
	wall.resize(n + 1);
	for (int i = 0; i < n + 1; i++) {
		wall[i].resize(n + 1);
		for (int j = 0; j < n + 1; j++) {
			wall[i][j] = make_pair(0, 0);
		}
	}

	for (int idx = 0; idx < build_frame.size(); idx++) {
		int x = build_frame[idx][0]; int y = build_frame[idx][1];
		int a = build_frame[idx][2]; int b = build_frame[idx][3];
		if (a == 0) {
			if (b == 0) {
				// 기둥 삭제
				wall[y][x].first--;
				wall[y + 1][x].first -= 2;
				if (verify(n, wall) == false) {
					wall[y][x].first++;
					wall[y + 1][x].first += 2;
				}
			}
			else if (b == 1) {
				// 기둥 설치
				if (y == 0 || wall[y][x].first || (wall[y][x].second && wall[y][x].first == 0)) {
					wall[y][x].first++;
					wall[y + 1][x].first += 2;
				}
			}
		}
		else if (a == 1) {
			if (b == 0) {
				// 보 삭제
				wall[y][x].second -= RIGHT;
				wall[y][x + 1].second -= LEFT;
				if (verify(n, wall) == false) {
					wall[y][x].second += RIGHT;
					wall[y][x + 1].second += LEFT;
				}
				
			}
			else if (b == 1) {
				// 보 설치
				if (wall[y][x].first >= 2 || wall[y][x + 1].first >= 2 || 
					(wall[y][x].second == LEFT && wall[y][x + 1].second == RIGHT)) {
					wall[y][x].second += RIGHT;
					wall[y][x + 1].second += LEFT;
				}
			}
		}
		/*printf("%d %d %d %d\n", y, x, a, b);
		for (int i = n; i >= 0; i--) {
			for (int j = 0; j < n + 1; j++) {
				printf("[%d %d] ", wall[i][j].first, wall[i][j].second);
			} printf("\n");
		}printf("\n");*/
	}
	vector<vector<int>> answer;
	for (int x = 0; x < n + 1; x++) {
		for (int y = 0; y < n + 1; y++) {
			vector<int> elem;
			if (wall[y][x].first == 1 || wall[y][x].first == 3) {
				elem.resize(3);
				elem[0] = x;
				elem[1] = y;
				elem[2] = 0;
				answer.push_back(elem);
			}
			elem.clear();
			if (wall[y][x].second == RIGHT || wall[y][x].second == LEFT + RIGHT) {
				elem.resize(3);
				elem[0] = x;
				elem[1] = y;
				elem[2] = 1;
				answer.push_back(elem);
			}
			elem.clear();
		}
	}
	return answer;
}
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<vector<int>> v;
	vector<int> t;
	t.push_back(5);
	t.push_back(5);
	t.push_back(0);
	t.push_back(1);
	v.push_back(t);
	cout << solution(10, v).size();
	return 0;
}