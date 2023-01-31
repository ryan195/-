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

vi gotCrack(500);
vi visited(29000000);
int total, givenA, givenB, givenC;
bool dfs(int a, int b, int c) {
    int currSum = a + b*2 + c*3;
    visited[a + b*310 + c *95000] = 1;
    if (currSum == total) {
        return true;
    } else if ((currSum > total) || (gotCrack[currSum] == 1)) {
        return false;
    } else {
        bool recur = false;
        if ((a < givenA) && (visited[a + b*310 + c *95000 + 1] == 0)) {
            recur = (recur || dfs(a + 1, b, c));
        }
        if ((b < givenB) && (visited[a + b*310 + c *95000 + 310] == 0)) {
            recur = (recur || dfs(a, b + 1, c));
        }
        if ((c < givenC) && (visited[a + b*310 + c *95000 + 95000] == 0)) {
            recur = (recur || dfs(a, b, c + 1));
        }
        return recur;
    }
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int numBricks, x;
    cin >> numBricks >> givenA >> givenB >> givenC;
    total = 0;
    for (int i = 0; i < numBricks; ++i) {
        cin >> x;
        total += x;
        gotCrack[total] = 1;
    }
    cout << ((dfs(0, 0, 0)) ? "YES" : "NO") << endl;
    return 0;
}