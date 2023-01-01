#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numNums;
    cin >> numNums;
    vector<long> vectA, vectB;
    long a, b;
    for (int i = 0; i < numNums; i++) {
        cin >> a;
        vectA.push_back(a);
    }
    for (int j = 0; j < numNums; j++) {
        cin >> b;
        vectB.push_back(b);
    }
    unordered_set<long> setting;
    unordered_map<long, int> mapping;
    for (int k = 0; k < numNums; k++) {
        long x = vectA[k];
        long y = vectB[k];
        if (x != y) {
            if (mapping.find(x) == mapping.end()) {
                mapping[x] = 1;
            } else {
                mapping[x]++;
            }
            if (mapping.find(y) == mapping.end()) {
                mapping[y] = -1;
            } else {
                mapping[y]--;
            }
            if (mapping[x] == 0) {
                setting.erase(x);
            } else {
                setting.insert(x);
            }
            if (mapping[y] == 0) {
                setting.erase(y);
            } else {
                setting.insert(y);
            }
        }
        cout << y << " ";
        if (setting.size() == 0) {
            if (k != numNums - 1) {
                cout << "# ";
            }
            else {
                cout << endl;
            }
        }
    }
    return 0;
}