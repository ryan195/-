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

int t = 0;
vector<int> adjList[100005];
int be[100005], en[100005];

void dfs(int x) {
    be[x] = t;
    ++t;
    for (int i = 0; i < adjList[x].size(); ++i) {
        dfs(adjList[x][i]);
        ++t;
    }
    en[x] = t;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        adjList[x].pb(i + 2);
    }

    dfs(1);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        int aS = be[a], aE = en[a], bS = be[b], bE = en[b];
        if ((bS < aS) && (bE > aE)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}