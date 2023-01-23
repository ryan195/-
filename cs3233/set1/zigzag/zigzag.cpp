#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int num;
    cin >> num;
    string s = "a";
    int numChars = (num % 25 == 0) ? (num / 25) : ((num / 25) + 1);
    vi vect(numChars);
    if (numChars > 2) {
        for (int i = 2; i < numChars - 1; ++i) {
            vect[i] = 25;
            num -= 25;
        }
        for (int i = 1; i < 26; i++) {
            if ((num - (i * 2)) <= 25) {
                vect[0] = i;
                vect[1] = i;
                vect[numChars - 1] = num - (i * 2);
                break;
            }
        }
        bool right = true;
        int curr = 0;
        for (int i = 0; i < numChars; ++i) {
            if (right) {
                s += (97 + curr + vect[i]);
                curr += vect[i];
            } else {
                s += (97 + curr - vect[i]);
                curr -= vect[i];
            }
            right = !right;
        }
    } else if (numChars == 1) {
        s += (char)(num + 97);
    } else {
        int sec = (num % 2 == 0) ? (num / 2) : ((num / 2) + 1);
        s += (char)(sec + 97);
        s += (char)(sec + 97 - (num - sec));
    }
    cout << s << endl;
    return 0;
}
