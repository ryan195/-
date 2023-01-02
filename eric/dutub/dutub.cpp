#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numVids;
    int total = 0;
    int arr[1024];
    memset(arr, -1, sizeof(arr));
    arr[0] = 0;
    cin >> numVids;
    for (int i = 0; i < numVids; ++i) {
        int a;
        int val = 0;
        string b;
        cin >> a;
        cin >> b;
        for (int j = 0; j < b.length(); ++j) {
            char c = b[j];
            if (c == 'a') {
                val += 1;
            } else if (c == 'b') {
                val += 2;
            } else if (c == 'b') {
                val += 2;
            } else if (c == 'c') {
                val += 4;
            } else if (c == 'd') {
                val += 8;
            } else if (c == 'e') {
                val += 16;
            } else if (c == 'f') {
                val += 32;
            } else if (c == 'g') {
                val += 64;
            } else if (c == 'h') {
                val += 128;
            } else if (c == 'i') {
                val += 256;
            } else {
                val += 512;
            }
        }
        total |= val;
        for (int j = 1023; j >= 0; --j) {
            if (arr[j] != -1) {
                int ifAdd = (j | val);
                arr[ifAdd] = ((arr[ifAdd] == -1) ? (arr[j] + a) : (min(arr[j] + a, arr[ifAdd])));
            }
        }
    }
    cout << arr[total] << endl;
    return 0;
}