#include <bits/stdc++.h>
    
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
        vi arr(20000, 0);
        int needed;
        cin >> needed;
        int numNotes;
        cin >> numNotes;
        vi vectNotes(numNotes);
        for (int j = 0; j < numNotes; ++j) {
            cin >> vectNotes[j];
        }
        sort(vectNotes.begin(), vectNotes.end(), greater<int>());
        int mini = 20000;
        for (int j = 0; j < vectNotes.size(); ++j) {
            int val = vectNotes[j];
            for (int k = 10000; k >= 0; --k) {
                if (arr[k]) {
                    arr[k + val] = ((arr[k + val] == 0) ? (arr[k] + 1) : (min(arr[k] + 1, arr[k + val])));
                    if ((k + val) >= needed) {
                        mini = min(mini, k + val);
                    }
                }
            }
            if (arr[val] == 0) {
                arr[val] = 1;
            }
            if (val >= needed) {
                mini = min(mini, val);
            }
        }
        cout << mini << " " << arr[mini] << endl;
    }
    return 0;
}