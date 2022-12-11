#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numCases;
    cin >> numCases;
    for (int i = 0; i < numCases; ++i) {
        unordered_map<string, int> mapping;
        int numItems;
        cin >> numItems;
        for (int j = 0; j < numItems; ++j) {
            string item;
            int amount;
            cin >> item >> amount;
            if (mapping.find(item) == mapping.end()) {
                mapping.insert({item, amount});
            } else {
                mapping.find(item)->second += amount;
            }
        }
        vector<pair<int, string>> vect;
        for (auto it = mapping.begin(); it != mapping.end(); ++it) {
            vect.push_back({it->second*-1, it->first});
        }
        sort(vect.begin(), vect.end());
        cout << vect.size() << endl;
        for (int j = 0; j < vect.size(); ++j) {
            cout << vect[j].second << " " << vect[j].first * -1 << endl;
        }
    }
    return 0;
}