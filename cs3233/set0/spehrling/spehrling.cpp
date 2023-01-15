#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < min(a.length(), b.length()); ++i) {
        if (a[i] != b[i]) {
            cout << a.length() + b.length() - (2 * i) << endl;
            return 0;
        }
    }
    cout << max(a.length(), b.length()) - min(a.length(), b.length()) << endl;
    return 0;
}