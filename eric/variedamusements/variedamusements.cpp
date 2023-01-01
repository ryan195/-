#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vi vect1, vect2, vect3;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mod = 1000000007;
    vect1.push_back(1);
    vect2.push_back(1);
    vect3.push_back(1);
    for (int i = 0; i < a - 1; ++i) {
        int newA = (((long long)vect2[i] * c) % mod);
        newA += (((long long)vect3[i] * d) % mod);
        vect1.push_back(newA);
        int newB = (((long long)vect1[i] * b) % mod);
        newB += (((long long)vect3[i] * d) % mod);
        vect2.push_back(newB);
        int newC = (((long long)vect2[i] * c) % mod);
        newC += (((long long)vect1[i] * b) % mod);
        vect3.push_back(newC);
    }
    int finA = (((long long)vect1[a - 1] * b) % mod);
    int finB = (((long long)vect2[a - 1] * c) % mod);
    int finC = (((long long)vect3[a - 1] * d) % mod);
    cout << ((long long)finA + finB + finC) % mod << endl;
    return 0;
}