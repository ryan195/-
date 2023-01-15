#include <bits/stdc++.h>
#include <unordered_map>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    unordered_map<int, int> count;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (count.find(x + 1) == count.end()) {
            count[x + 1] = 0;
        }
        ++count[x + 1];
    }
    long long result = 0;
    for (auto it = count.begin(); it != count.end(); ++it) {
        result += ((it->second / it->first) * it->first);
        result += (((it->second % it->first) == 0) ? 0 : it->first);
    }
    cout << result << endl;
    return 0;
}