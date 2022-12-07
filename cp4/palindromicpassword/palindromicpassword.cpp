#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numNums;
    cin >> numNums;
    for (int i = 0; i < numNums; i++) {
        int number;
        cin >> number;
        int lower = number, higher = number;
        while (higher < 1000000) {
            string x = to_string(higher);
            if ((x[0] == x[5]) && 
            (x[1] == x[4]) &&
            (x[2] == x[3])) {
                break;
            } else {
                higher++;
            }
        }
        while (lower > 99999) {
            string x = to_string(lower);
            if ((x[0] == x[5]) && 
            (x[1] == x[4]) &&
            (x[2] == x[3])) {
                break;
            } else {
                lower--;
            }
        }
        if (lower > 99999) {
            if (higher >= 1000000) {
                cout << lower << endl;
            } else {
                cout << (((higher - number) < (number - lower)) ? higher : lower) << endl;
            }
        } else {
            cout << higher << endl;
        }
    }
    return 0;
}