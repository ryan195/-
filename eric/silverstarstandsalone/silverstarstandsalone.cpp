#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vi primeVect = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,
    61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,
    151,157,163,167,173,179,181,191,193,197,199,211,223};
    vector<long long> numWays = {1};
    int a;
    cin >> a;
    if (a == 2) {
        cout << 1 << endl;
    }
    for (int i = 1; i < primeVect.size(); ++i) {
        long long num = 0;
        for (int j = i - 1; j >= 0; --j) {
            if ((primeVect[j] + 14) < primeVect[i]) {
                break;
            } else {
                num += numWays[j];
            }
        }
        if (a == primeVect[i]) {
            cout << num << endl;
            return 0;
        } else {
            numWays.push_back(num);
        }
    }
    return 0;
}