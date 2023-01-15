#include <bits/stdc++.h>
#include <unordered_map>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numCases;
    cin >> numCases;
    for (int i = 0; i < numCases; ++i) {
        unordered_map<long long, int> mapping;
        mapping[0] = 1;
        int numBers;
        long long prefix = 0, numCount = 0;
        cin >> numBers;
        for (int j = 0; j < numBers; ++j) {
            int x;
            cin >> x;
            prefix += x;
            ++mapping[prefix];
            numCount += mapping[prefix - 47];
        }
        cout << numCount << endl;
    }
    return 0;
}