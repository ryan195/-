#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numBefore, numAfter;
    cin >> numBefore >> numAfter;
    unordered_set<int> set;
    vi ori;
    for (int i = 1; i <= numBefore; i++) {
        set.insert({i});
    }
    for (int i = 0; i < numAfter; i++) {
        int num;
        cin >> num;
        set.erase(num);
        ori.push_back(num);
    }
    vi vect;
    for (auto it = set.begin(); it != set.end(); it++) {
        vect.push_back(*it);
    }
    sort(vect.begin(), vect.end());
    int index = 0;
    for (int i = 0; i < ori.size(); i++) {
        while ((vect.size() > index) && (vect[index] < ori[i])) {
            cout << vect[index] << endl;
            index++;
        }
        cout << ori[i] << endl;
    }
    while (vect.size() > index) {
        cout << vect[index] << endl;
        index++;
    }
    return 0;
}