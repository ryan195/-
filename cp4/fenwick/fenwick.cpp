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

ll fw[5000005];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);

    int lenArr, numOps;
    cin >> lenArr >> numOps;
    ++lenArr;

    for (int i = 0; i < numOps; ++i) {
        char c;
        cin >> c;
        if (c == '+') {
            //Update
            int x;
            ll v;
            cin >> x >> v;
            ++x;
            for (; x<(lenArr); x+=x&(-x)) fw[x] += v; 
        } else {
            //Query
            int x;
            cin >> x;
            if (x == 0) {
                cout << "0\n";
            } else {
                ll res = 0;
                for(; x; x-=x&(-x)) res += fw[x];
                cout << res << "\n";
            }
        }
    }

    return 0;
}