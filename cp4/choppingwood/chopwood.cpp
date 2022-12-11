#include <bits/stdc++.h>
#include <unordered_map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numList;
    cin >> numList;
    unordered_map<int, int> count;
    set<int> available;
    vi vect;
    for (int i = 1; i < numList + 2; ++i) {
        available.insert({i});
    }
    int x;
    for (int i = 0; i < numList; ++i) {
        cin >> x;
        if (available.find(x) != available.end()) {
            available.erase(x);
        }
        if (count.find(x) == count.end()) {
            count[x] = 1;
        } else {
            ++count[x];
        }
        vect.push_back(x);
    }
    vi ans;
    for (int i = 0; i < numList; ++i) {
        int curr = vect[i];
        if (*available.begin() > numList) {
            cout << "Error" << endl;
            return 0;
        } else {
            ans.push_back(*available.begin());
            available.erase(*available.begin());
            --count[curr];
            if (count[curr] == 0) {
                available.insert({curr});
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}