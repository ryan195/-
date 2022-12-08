#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numDigits, median;
    cin >> numDigits >> median;
    vi vect;
    int arr[100000];
    int index = -1;
    for (int i = 0; i < numDigits; i++) {
        int x;
        cin >> x;
        if (x == median) {
            index = i;
        }
        vect.push_back(x);
    }
    int diff = 0;
    for (int i = index - 1; i >= 0; i--) {
        if (vect[i] < median) {
            --diff;
        } else {
            ++diff;
        }
        arr[i] = diff;
    }
    diff = 0;
    for (int i = index + 1; i < numDigits; i++) {
        if (vect[i] < median) {
            --diff;
        } else {
            ++diff;
        }
        arr[i] = diff;
    }
    unordered_map<int, int> map;
    long ans = 0;
    for (int i = 0; i < index; i++) {
        if (arr[i] == 0) {
            ++ans;
        }
        if (map.find(arr[i]) == map.end()) {
            map.insert({arr[i], 1});
        } else {
            ++map.find(arr[i])->second;
        }
    }
    for (int i = index + 1; i < numDigits; i++) {
        if (arr[i] == 0) {
            ++ans;
        }
        int x = (arr[i] * -1);
        if (map.find(x) != map.end()) {
            ans += map.find(x)->second;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}