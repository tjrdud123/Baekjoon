#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
    int tagger = 0;
    int location = 0;
	vector<int> circle(numOfAllPlayers - 1);
    vector<bool> isFast(numOfAllPlayers, false);
    vector<int> cnt(numOfAllPlayers, 0);
    cnt[0]++;

    for(int i = 0; i < numOfQuickPlayers; i++) {
        isFast[namesOfQuickPlayers[i] - 'A'] = true;
    }
    for(int i = 0; i < numOfAllPlayers - 1; i++) {
        circle[i] = i + 1;
    }
    for(int g =0; g < numOfGames; g++) {
        int move = numOfMovesPerGame[g];
        location += move;
        if(location < 0) while(location < 0) location += (numOfAllPlayers - 1);
        else if(location >= numOfAllPlayers - 1) location %= (numOfAllPlayers - 1);

        if(isFast[circle[location]]) {
            // 술래 안 바뀜
            cnt[tagger]++;
        }
        else {
						int t = tagger;
            tagger = circle[location];
						circle[location] = t;
            cnt[tagger]++;
        }
    }

    // 출력
    for(int i = 0; i < numOfAllPlayers - 1; i++) {
        cout << (char)(circle[i] + 'A') << " " << cnt[circle[i]] << "\n";
    }
    cout << (char)(tagger + 'A') << " " << cnt[tagger] << "\n";
}