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
#include <stack>
#include <cassert>
#include <unordered_map>

using namespace std; 

class Player {
public:
    long year;
    long strength;

    Player(long _year, long _strength) {
        year = _year;
        strength = _strength;
    }
};

bool sortPlayer(const Player &p1, const Player &p2) {
    return p1.year < p2.year;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<long> tournament;

    long k, n, y, s, winYear = 2011;
    cin >> k >> n >> y >> s;
    Player karl(y, s);
    vector<Player> players;
    players.push_back(karl);
    for (long i = 0; i < n + k - 2; i++) {
        cin >> y >> s;
        players.push_back(Player(y, s));
    }
    sort(players.begin(), players.end(), sortPlayer);
    for (long i = 0; i < k; i++) {
        tournament.push(players[i].strength);
    }
    for (long i = k; i < n + k - 1; i++) {
        if (tournament.top() == karl.strength) {
            cout << winYear;
            return 0;
        } else {
            tournament.pop();
            tournament.push(players[i].strength);
            winYear++;
        }
    }
    if (tournament.top() == karl.strength) {
        cout << winYear << '\n';
    } else {
        cout << "unknown\n";
    }

    return 0;
}