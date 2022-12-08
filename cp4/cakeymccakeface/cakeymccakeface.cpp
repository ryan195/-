#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int entry, exit;
    cin >> entry >> exit;
    vector<long long> vectEntry;
    vector<long long> vectExit;
    for (int i = 0; i < entry; ++i) {
        long long x;
        cin >> x;
        vectEntry.push_back(x);
    }
    for (int i = 0; i < exit; ++i) {
        long long x;
        cin >> x;
        vectExit.push_back(x);
    }
    unordered_map<long long, int> guesses;
    for (int i = 0; i < entry; ++i) {
        for (int j = 0; j < exit; ++j) {
            long long diff = vectExit[j] - vectEntry[i];
            if (diff >= 0) {
                ++guesses[diff];
            }
        }
    }
    long long ans = 0;
    int numGuesses = 0;
    for (auto it = guesses.begin(); it != guesses.end(); ++it) {
        if ((it->second > numGuesses) ||
        ((it->second == numGuesses) && (it->first < ans))) {
            ans = it->first;
            numGuesses = it->second;
        }
    }
    cout << ans << endl;
    return 0;
}