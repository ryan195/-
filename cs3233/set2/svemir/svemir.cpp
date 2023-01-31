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

struct trip {
    int a, b, c;
    trip(int x, int y, int z) {
        a = x; b = y; c = z;
    }
    
};

bool operator<(trip lhs, trip rhs) {
    return lhs.a > rhs.a;
}

struct quart {
    int a, b, c, d;
};

int p[100100], numGroups;
int par(int x) { return (p[x]==x)? x:p[x]=par(p[x]); }
bool isSameGroup(int a, int b) { return par(a) == par(b); }
void merge(int a, int b) {
    numGroups -= (!isSameGroup(a, b));
    p[par(a)] = par(b);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int numPlanets;
    cin >> numPlanets;
    int x, y, z;
    vector<quart> vect(numPlanets);
    numGroups = numPlanets;
    for (int i = 0; i < numPlanets; ++i) {
        cin >> x >> y >> z;
        p[i] = i;
        vect[i].a = x; vect[i].b = y; vect[i].c = z; vect[i].d = i;
    }
    priority_queue<trip> pq;
    sort(vect.begin(), vect.end(), [](auto &lhs, auto &rhs) {
        return lhs.a < rhs.a;
    });
    for (int i = 1; i < numPlanets; ++i) {
        trip x(vect[i].a - vect[i - 1].a, vect[i - 1].d, vect[i].d);
        pq.push(x);
    }
    sort(vect.begin(), vect.end(), [](auto &lhs, auto &rhs) {
        return lhs.b < rhs.b;
    });
    for (int i = 1; i < numPlanets; ++i) {
        trip x(vect[i].b - vect[i - 1].b, vect[i - 1].d, vect[i].d);
        pq.push(x);
    }
    sort(vect.begin(), vect.end(), [](auto &lhs, auto &rhs) {
        return lhs.c < rhs.c;
    });
    for (int i = 1; i < numPlanets; ++i) {
        trip x(vect[i].c - vect[i - 1].c, vect[i - 1].d, vect[i].d);
        pq.push(x);
    }
    ll ans = 0;
    while (numGroups != 1) {
        trip x = pq.top();
        pq.pop();
        ans += (isSameGroup(x.b, x.c) ? 0 : x.a);
        merge(x.b, x.c);
    }
    cout << ans << endl;
    return 0;
}