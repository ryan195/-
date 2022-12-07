#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long x;
    cin >> x;
    long long z = sqrt(x) + 1;
    vector<long long> vect;
    unordered_set<long long> set;
    for (long long i = 1; i < z + 1; i++) {
        if (x % i == 0) {
            if (set.find(i) == set.end()) {
                vect.push_back(i);
                set.insert({i});
            }
            if ((i != (x / i)) && (set.find(x / i) == set.end())) {
                vect.push_back(x / i);
                set.insert({x / i});
            }
        }
    }
    sort(vect.begin(), vect.end());
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}