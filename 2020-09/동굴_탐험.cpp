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
vector<bool> isLocked;
map<int, int> key;
vector<vector<int> > adj;
vector<bool> visited;
bool bfs(int src, int n) {
	visited[src] = true;

	queue<int> q;
	q.push(0);

	vector<bool> hold(n, false);
	while (q.empty() == false) {
		int here = q.front();
		q.pop();

		if (isLocked[here]) {
			hold[here] = true;
			continue;
		}

		visited[here] = true;
		int room = key[here];
		isLocked[room] = false;
		if (hold[room]) {
			q.push(room);
			hold[room] = false;
		}

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];

			if (visited[there] == false) q.push(there);
		}
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) return false;
	}
	return true;
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	isLocked.assign(n, false);
	visited.assign(n, false);
	for (int i = 0; i < order.size(); i++) {
		isLocked[order[i][1]] = true;
		key[order[i][0]] = order[i][1];
	}
	adj.resize(n);
	for (int i = 0; i < path.size(); i++) {
		int a = path[i][0];
		int b = path[i][1];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	return bfs(0, n);
}