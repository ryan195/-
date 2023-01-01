#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vi vect1, vect2;
    string a;
    cin >> a;
    if (a[0] == 'S') {
        vect1.push_back(0);
        vect2.push_back(1);
    } else if (a[0] == 'N') {
        vect1.push_back(1);
        vect2.push_back(1);
    } else {
        vect1.push_back(1);
        vect2.push_back(2);
    }
    for (int i = 0; i < a.length() - 1; ++i) {
        char c = a[i + 1];
        vect1.push_back(min(vect1[i], vect2[i] + 1));
        vect2.push_back(min(vect1[i] + 1, vect2[i]));
        if (c == 'S') {
            ++vect2[i + 1];
        } else if (c == 'N') {
            ++vect1[i + 1];
        } else {
            ++vect1[i + 1];
            ++vect2[i + 1];
        }
        vect1[i + 1] = min(vect1[i + 1], vect2[i + 1] + 1);
        vect2[i + 1] = min(vect1[i + 1] + 1, vect2[i + 1]);
    }
    cout << min(vect1[a.length() - 1], vect2[a.length() - 1] + 1) << endl;
    return 0;
}