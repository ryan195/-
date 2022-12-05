#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<int, long long> map;
    unordered_map<int, long long> checks;
    int numCows, numChecks;
    long long numFarms;
    cin >> numCows >> numFarms >> numChecks;
    for (int i = 0; i < numFarms; i++) {
        int cows;
        cin >> cows;
        auto itr = map.find(cows);
        if (itr != map.end()) {
            itr->second++;
        } else {
            map.insert({cows, 1});
        }
    }
    checks.insert({0, numFarms});
    for (int i = 1; i < 51; i++) {
        long long amount = 0;
        unordered_map<int, long long> map2;
        for (int j = 1; j < 1001; j++) {
            if (map.find(j) != map.end()) {
                if (j * 2 <= numCows) {
                    amount += map[j];
                    map2.insert({j * 2, map[j]});
                } else {
                    amount += (map[j] * 2);
                    if (map2.find(j) != map.end()) {
                        map2.find(j)->second += (map[j] * 2);
                    } else {
                        map2.insert({j, map[j] * 2});
                    }
                }
            }
        }
        map = map2;
        checks.insert({i, amount});
    }
    for (int i = 0; i < numChecks; i++) {
        int val;
        cin >> val;
        cout << checks[val] << endl;
    }
    return 0;
}