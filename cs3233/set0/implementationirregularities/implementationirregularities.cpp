#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vector<pii> vect;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] != -1) {
            vect.push_back({b[i], a[i]});
        }
    }
    sort(vect.begin(), vect.end());
    int total = 0, com = 1;
    for (int i = 0; i < vect.size(); ++i) {
        total += vect[i].second;
        com = max(com, ((total%vect[i].first == 0) ? (total/vect[i].first) : (total/vect[i].first + 1)));
    }
    cout << com << endl;
    return 0;
}