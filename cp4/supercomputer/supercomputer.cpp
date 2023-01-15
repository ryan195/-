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

int fw[1000005];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int numBits, numQueries;
    cin >> numBits >> numQueries;
    for (int i = 0 ; i < numQueries; ++i) {
        char c;
        cin >> c;
        if (c == 'F') {
            int x;
            cin >> x;
            int resA = 0, resB = 0;
            for(int a = (x-1); a; a-=a&(-a)) resA += fw[a];
            for(int b = x; b; b-=b&(-b)) resB += fw[b];
            if ((resB - resA) == 0) {
                for (; x<=numBits; x+=x&(-x)) fw[x] += 1;
            } else {
                for (; x<=numBits; x+=x&(-x)) fw[x] -= 1;
            }
        } else {
            int a, b;
            cin >> a >> b;
            --a;
            int resA = 0;
            for(; a; a-=a&(-a)) resA += fw[a];
            int resB = 0;
            for(; b; b-=b&(-b)) resB += fw[b];
            cout << resB - resA << endl;
        }
    }
    return 0;
}