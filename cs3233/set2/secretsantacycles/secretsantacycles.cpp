#include <bits/stdc++.h>

#define INF INT_MAX
#define pb push_back
#define ub upper_bound
#define lb lower_bound

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long>>;
using vvll = vector<vector<long long>>;
using mii = map<int, int>;
using pii = pair<int, int>;

int p[10005];
int r[10005];
int par(int x) { return (p[x]==x)? x:p[x]=par(p[x]); }
bool isSameGroup(int a, int b) { return par(a) == par(b); }
void merge(int a, int b) {
    p[par(a)] = par(b);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        merge(i, x);
        ++r[x];
    }
    for (int i = 1; i <= n; ++i) {
        p[i] = par(p[i]);
    }
    mii mapp;
    for (int i = 1; i <= n; ++i) {
        mapp[p[i]] += ((r[i] == 0) ? 1 : 0);
    }
    int total = 0;
    if ((mapp.size() > 1) || (mapp.begin()->second > 0)) {
        for (auto it = mapp.begin(); it != mapp.end(); ++it) {
            total += max(it->second, 1);
        }
    }
    cout << total << endl;
    return 0;
}