#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numStacks;
    cin >> numStacks;
    vector<pii> vectFin;
    vector<pii> vect;
    int x;
    int summ = 0, maxi = 0;
    for (int i = 0; i < numStacks; ++i) {
        cin >> x;
        vect.push_back({x, i + 1});
        summ += x;
        maxi = max(x, maxi);
    }
    if (summ % 2 == 1) {
        cout << "no" << endl;
        return 0;
    }
    if (maxi > (summ / 2)) {
        cout << "no" << endl;
        return 0;
    }
    pii a, b;
    sort(vect.begin(), vect.end());
    while (vect[numStacks - 1].first > 0) {
        vectFin.push_back({vect[numStacks - 1].second, vect[numStacks - 2].second});
        --vect[numStacks - 1].first;
        --vect[numStacks - 2].first;
        sort(vect.begin(), vect.end());
    }
    cout << "yes" << endl;
    for (int i = 0; i < vectFin.size(); ++i) {
        cout << vectFin[i].first << " " << vectFin[i].second << "\n";
    }
    return 0;
}