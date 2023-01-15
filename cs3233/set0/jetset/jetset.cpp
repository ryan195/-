#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numPoints;
    cin >> numPoints;
    bool hasCircum = false;
    vi points(720);
    memset(&points[0], 0, sizeof(points));
    int a, b, prevB, firstPath, secondPath, storeB;
    cin >> a >> storeB;
    prevB = storeB;
    for (int i = 1; i < numPoints; ++i) {
        cin >> a >> b;
        firstPath = abs(b - prevB);
        secondPath = 360 - firstPath;
        int c, d;
        c = (min(b, prevB) + 180) * 2;
        d = (max(b, prevB) + 180) * 2;
        if (d - c == 360) {
            hasCircum = true;
        }
        if (firstPath > secondPath) {
            for (int j = 0; j <= c; ++j) {
                points[j] = 1;
            }
            for (int j = d; j < 720; ++j) {
                points[j] = 1;
            }
        } else {
            for (int j = c; j <= d; ++j) {
                points[j] = 1;
            }
        }
        prevB = b;
    }
    int e, f;
    e = (min(storeB, prevB) + 180) * 2;
    f = (max(storeB, prevB) + 180) * 2;
    firstPath = abs(storeB - prevB);
    secondPath = 360 - firstPath;
    if (f - e == 360) {
        hasCircum = true;
    }
    if (firstPath > secondPath) {
        for (int j = 0; j <= e; ++j) {
            points[j] = 1;
        }
        for (int j = f; j < 720; ++j) {
            points[j] = 1;
        }
    } else {
        for (int j = e; j <= f; ++j) {
            points[j] = 1;
        }
    }
    if (hasCircum) {
        cout << "yes" << endl;
    } else {
        vi vectNotIn;
        for (int i = 0; i < 720; i++) {
            if (points[i] == 0) {
                vectNotIn.push_back(i);
            }
        }
        if (vectNotIn.size() == 0) {
            cout << "yes" << endl;
        } else {
            cout << "no " << (double)vectNotIn[vectNotIn.size() - 1]/2 - 180 << endl;
        }
    }
    return 0;
}