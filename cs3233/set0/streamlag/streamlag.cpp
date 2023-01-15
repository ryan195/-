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
    vi vect(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vect[b - 1] = a;
    }
    int lag = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + lag + 1) < vect[i]) {
            lag = vect[i] - i - 1;
        }
    }
    cout << lag << endl;
    return 0;
}