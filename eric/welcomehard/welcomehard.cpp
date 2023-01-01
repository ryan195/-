#include <bits/stdc++.h>
#include <unordered_map>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<int, char> mapChar;
    unordered_map<int, int> mapCount;
    string s = "welcome to code jam";
    mapCount[-1] = 1;
    for (int i = 0; i < s.length(); ++i) {
        mapChar[i] = s[i];
        mapCount[i] = 0;
    }
    int numCases;
    cin >> numCases;
    string a;
    getline(cin, a);
    for (int i = 1; i < numCases + 1; ++i) {
        getline(cin, a);
        for (int j = 0; j < a.length(); ++j) {
            char c = a[j];
            for (int k = 0; k < 19; ++k) {
                 if (mapChar[k] == c) {
                    mapCount[k] += mapCount[k - 1];
                    mapCount[k] %= 10000;
                 }
            }
        }
        string fin = "0000" + to_string(mapCount[18]);
        cout << "Case #" << i << ": " << fin.substr(fin.length() - 4) << endl;
        for (int j = 0; j < 19; ++j) {
            mapCount[j] = 0;
        }
    }
    return 0;
}