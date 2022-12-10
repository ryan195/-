#include <bits/stdc++.h>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string things;
    map<string, double> counts;
    double totalCount = 0;
    while (true) {
        getline(cin, things);
        if (things.length() == 0) {
            break;
        }
        ++totalCount;
        if (counts.find(things) == counts.end()) {
            counts.insert({things, 1});
        } else {
            ++counts.find(things)->second;
        }
    }
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        cout << it->first << " " << it->second/totalCount*100 << endl;
    }
    return 0;
}