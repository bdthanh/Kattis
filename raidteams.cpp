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
#include <set>

using namespace std;

class Player {
public:
    long s1, s2, s3;
    string name;

    Player(string _name, long _s1, long _s2, long _s3) {
        name = _name;
        s1 = _s1;
        s2 = _s2;
        s3 = _s3;
    }
};

struct CustomComparator1 {
    bool operator() (const Player &a, const Player &b) const {
        if (a.s1 != b.s1) 
            return a.s1 > b.s1;
        return a.name < b.name;
    }
};

struct CustomComparator2 {
    bool operator() (const Player &a, const Player &b) const {
        if (a.s2 != b.s2) 
            return a.s2 > b.s2;
        return a.name < b.name;
    }
};

struct CustomComparator3 {
    bool operator() (const Player &a, const Player &b) const {
        if (a.s3 != b.s3) 
            return a.s3 > b.s3;
        return a.name < b.name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string name;
    long n, s1, s2, s3; 
    cin >> n;
    set<Player, CustomComparator1> playerSortedbySkill1;
    set<Player, CustomComparator2> playerSortedbySkill2;
    set<Player, CustomComparator3> playerSortedbySkill3;
    for (int i=0; i < n; i++) {
        cin >> name >> s1 >> s2 >> s3;
        Player player(name, s1, s2, s3);
        playerSortedbySkill1.insert(player);
        playerSortedbySkill2.insert(player);
        playerSortedbySkill3.insert(player);
    }
    while (playerSortedbySkill1.size() >= 3) {
        vector<string> team;
        playerSortedbySkill2.erase(*(playerSortedbySkill1.begin()));
        playerSortedbySkill3.erase(*(playerSortedbySkill1.begin()));
        team.push_back((*(playerSortedbySkill1.begin())).name);
        playerSortedbySkill1.erase(*(playerSortedbySkill1.begin()));

        playerSortedbySkill1.erase(*(playerSortedbySkill2.begin()));
        playerSortedbySkill3.erase(*(playerSortedbySkill2.begin()));
        team.push_back((*(playerSortedbySkill2.begin())).name);
        playerSortedbySkill2.erase(*(playerSortedbySkill2.begin()));

        playerSortedbySkill1.erase(*(playerSortedbySkill3.begin()));
        playerSortedbySkill2.erase(*(playerSortedbySkill3.begin()));
        team.push_back((*(playerSortedbySkill3.begin())).name);
        playerSortedbySkill3.erase(*(playerSortedbySkill3.begin()));
        sort(team.begin(), team.end());
        cout <<  team[0] << ' ' << team[1] << ' '  << team[2] << '\n';
    }
    // string p1 = "", p2 = "", p3 = ""; //store the new team member name
    // vector<string> team;
    // team.push_back(p1); team.push_back(p2); team.push_back(p3);
    // while (player.size() >= 3) {
    //     make_heap(player.begin(), player.end(), sortPlayerSkill1);
    //     p1 = player[0].name;
    //     pop_heap(player.begin(), player.end(), sortPlayerSkill1);
    //     player.pop_back();
    //     make_heap(player.begin(), player.end(), sortPlayerSkill2);
    //     p2 = player[0].name;
    //     pop_heap(player.begin(), player.end(), sortPlayerSkill2);
    //     player.pop_back();
    //     make_heap(player.begin(), player.end(), sortPlayerSkill3);
    //     p3 = player[0].name;
    //     pop_heap(player.begin(), player.end(), sortPlayerSkill3);
    //     player.pop_back();
    //     team[0] = p1; team[1] = p2; team[2] = p3;
    //     sort(team.begin(), team.end());
    //     cout <<  team[0] << ' ' << team[1] << ' '  << team[2] << '\n';
    // }
    return 0;
}