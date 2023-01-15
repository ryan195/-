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


int N = 200005;
int fwA[200005];
int fwB[200005];
int fwC[200005];
int fwD[200005];
int fwE[200005];
int fwF[200005];

void update(int x, int v, int i) {
    if (i == 1) {
        for (; x<N; x+=x&(-x)) fwA[x] += v;
    } else if (i == 2) {
        for (; x<N; x+=x&(-x)) fwB[x] += v;
    } else if (i == 3) {
        for (; x<N; x+=x&(-x)) fwC[x] += v;
    } else if (i == 4) {
        for (; x<N; x+=x&(-x)) fwD[x] += v;
    } else if (i == 5) {
        for (; x<N; x+=x&(-x)) fwE[x] += v;
    } else {
        for (; x<N; x+=x&(-x)) fwF[x] += v;
    }
}
ll summ(int x, int i) {
    ll res = 0;
    if (i == 1) {
        for(; x; x-=x&(-x)) res += fwA[x];
    } else if (i == 2) {
        for(; x; x-=x&(-x)) res += fwB[x];
    } else if (i == 3) {
        for(; x; x-=x&(-x)) res += fwC[x];
    } else if (i == 4) {
        for(; x; x-=x&(-x)) res += fwD[x];
    } else if (i == 5) {
        for(; x; x-=x&(-x)) res += fwE[x];
    } else {
        for(; x; x-=x&(-x)) res += fwF[x];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int numGems, numQueries;
    cin >> numGems >> numQueries;
    vi vectGems(6);
    for (int i = 0; i < 6; ++i) {
        cin >> vectGems[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        int x = (int)(s[i] - '0');
        update(i + 1, 1, x);
    }
    for (int i = 0; i < numQueries; ++i) {
        int a, b, c;
        cin >> a >> b >> c; 
        if (a == 1) {
            for (int j = 0; j < 6; ++j) {
                if (summ(b, j) - summ(b - 1, j) == 1) {
                    update(b, -1, j);
                    break;
                }
            }
            update(b, 1, c);
        } else if (a == 2) {
            vectGems[b - 1] = c;
        } else {
            ll total = 0;
            for (int j = 1; j <= 6; ++j) {
                total += ((summ(c, j) - summ(b - 1, j)) * vectGems[j - 1]);
            }
            cout << total << endl;
        }
    }
    return 0;
}