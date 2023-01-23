#include <bits/stdc++.h>
#include <unordered_set>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unordered_set<int> sett;
    int numStamps, numQueries;
    cin >> numStamps >> numQueries;
    vi vect(numStamps);
    for (int i = 0; i < numStamps; ++i) {
        cin >> vect[i];
    }
    int summ = 0;
    for (int j = 0; j < numStamps; ++j) {
        summ += vect[j];
        sett.insert({summ});
    }
    int maxi = summ;
    int query;
    for (int k = 0; k < numQueries; ++k) {
        cin >> query;
        if (query == 0) {
            cout << "Yes" << endl;
            continue;
        }
        if (query > summ) {
            cout << "No" << endl;
            continue;
        }
        int newSumm = 0;
        if (sett.find(query) != sett.end()) {
            cout << "Yes" << endl;
            continue;
        }
        for (int j = numStamps - 1; j >= 0; --j) {
            newSumm += vect[j];
            if (query < newSumm) {
                cout << "No" << endl;
                break;
            }
            if (query == newSumm) {
                cout << "Yes" << endl;
                break;
            }
            if (sett.find(query - newSumm) != sett.end()) {
                cout << "Yes" << endl;
                break;
            }
        }
    }
    return 0;
}