#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int binarySearch(vi v, int To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (v[mid] <= To_Find) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if (v[lo] > To_Find) {
        return lo;
    }
    else if (v[hi] > To_Find) {
        return hi;
    }
    else {
        return -1;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<pii> vect;
    vi vect2;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        vect.push_back({x, i});
        vect2.push_back(x);
    }
    sort(vect.begin(), vect.end());
    for (int i = 0; i < n; i++) {
        vect2[vect[i].second] = i / k;
    }
    vi order;
    order.push_back(vect2[0]);
    for (int i = 1; i < n; i++) {
        int x = binarySearch(order, vect2[i]);
        if (x != -1) {
            order[x] = vect2[i];
        } else {
            order.push_back(vect2[i]);
        }
    }
    cout << n - order.size() << endl;
    return 0;
}