/**
 * Name: Bui Duc Thanh 
 * Matric number: A0243318J
 * Lab groupn number: B01
 * Lab group TA: Muhammad Ayaz Dzulfikar
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <list>
#include <cassert>
#include <unordered_map>

using namespace std;

void read_names(long namesNum, vector<string> &namesVec) {
    string names;
    for (long i = 0; i < namesNum; i++) {
        cin >> names;
        namesVec.push_back(names);
    }    
}

void read_nicknames(long nicknamesNum, vector<string> &nicknamesVec, unordered_map<string, int> &mapNicknameswithNum) {
    string nicknames;
    for (long i = 0; i < nicknamesNum; i++) {
        cin >> nicknames;
        mapNicknameswithNum[nicknames] = 0;
        nicknamesVec.push_back(nicknames);
    }
}

void count_number_of_Names_matched_with_Nicknames(long namesNum, long nicknamesNum, vector<string> &namesVec, vector<string> &nicknamesVec, unordered_map<string, int> &mapNicknameswithNum) {
    for (long i = 0; i < namesNum; i++) {
        for (long j = 1; j <= namesVec[i].length(); j++) {
            string substr = namesVec[i].substr(0, j);
            auto findNickname = mapNicknameswithNum.find(substr);
            if (findNickname != mapNicknameswithNum.end()) {
                findNickname->second++;
            }
        }
    }
}

void print_number_of_Names_matched_with_Nicknames(long nicknamesNum, vector<string> nicknamesVec, unordered_map<string, int> &mapNicknameswithNum) {
    for (long i = 0; i < nicknamesNum; i++) {
        auto findNicknames = mapNicknameswithNum.find(nicknamesVec[i]);
        cout << findNicknames->second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long namesNum, nicknamesNum;
    vector<string> namesVec; 
    vector<string> nicknamesVec; 
    unordered_map<string, int> mapNicknameswithNum;

    cin >> namesNum;
    read_names(namesNum, namesVec);

    cin >> nicknamesNum;
    read_nicknames(nicknamesNum, nicknamesVec, mapNicknameswithNum);

    count_number_of_Names_matched_with_Nicknames(namesNum, nicknamesNum, namesVec, nicknamesVec, mapNicknameswithNum);

    print_number_of_Names_matched_with_Nicknames(nicknamesNum, nicknamesVec, mapNicknameswithNum);
    
    return 0;
}