#include <bits/stdc++.h>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (true) {
        bool hasEnded = false;
        string currProj = " ";
        unordered_map<string, vector<int>> projCount;
        unordered_map<int, string> indexProj;
        vector<pair<string, int>> vect;
        unordered_map<string, int> mapping;
        int proj = -1;
        while (true) {
            string x;
            getline(cin, x);
            if (x == "1") {
                for (auto it = indexProj.begin(); it != indexProj.end(); ++it) {
                    mapping.insert({it->second, 0});
                }
                for (auto it = projCount.begin(); it != projCount.end(); ++it) {
                    if (it->second.size() != 1) {
                        continue;
                    } else {
                        string theProj = indexProj[it->second[0]];
                        ++mapping.find(theProj)->second;
                    }
                }
                for (auto it = mapping.begin(); it != mapping.end(); ++it) {
                    vect.push_back({it->first, it->second});
                }
                sort(vect.begin(), vect.end(), [](const auto& lhs, const auto& rhs) {
                    if (lhs.second > rhs.second) {
                        return true;
                    } else if (lhs.second < rhs.second) {
                        return false;
                    } else {
                        return (lhs.first < rhs.first);
                    }
                });
                for (auto it = vect.begin(); it != vect.end(); ++it) {
                    cout << it->first << " " << it->second << endl;
                }
                break;
            }
            if (x == "0") {
                hasEnded = true;
                sort(vect.begin(), vect.end(), [](const auto& lhs, const auto& rhs) {
                    if (lhs.second > rhs.second) {
                        return true;
                    } else if (lhs.second < rhs.second) {
                        return false;
                    } else {
                        return (lhs.first < rhs.first);
                    }
                });
                for (auto it = vect.begin(); it != vect.end(); ++it) {
                    cout << it->first << " " << it->second << endl;
                }
                break;
            }
            if (isupper(x[0])) {
                ++proj;
                currProj = x;
                indexProj.insert({proj, currProj});
            } else {
                if (projCount.find(x) == projCount.end()) {
                    vector<int> vect2;
                    vect2.push_back(proj);
                    projCount.insert({x, vect2});
                } else {
                    if (projCount[x][projCount[x].size() - 1] == proj) {
                        continue;
                    } else {
                        projCount[x].push_back(proj);
                    }
                }
            }
        }
        if (hasEnded) {
            break;
        }
    }
    return 0;
}