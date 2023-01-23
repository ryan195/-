#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while (true) {
        int numInstructions;
        cin >> numInstructions;
        if (numInstructions == -1) {
            break;
        }
        vector<vi> v;
        for (int i = 0; i < 115; ++i) {
            vi vect;
            v.push_back(vect);
            for (int j = 0; j < 115; ++j) {
                v[i].push_back(0);
            }
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 1; j <= 5; ++j) {
                int x = (i*5) + j;
                v[55 + i][55 + j - 1] = x;
            }
        }
        for (int i = 0; i < numInstructions; ++i) {
            char c;
            string s;
            cin >> c >> s;
            int x = (int)c - 64;
            bool found = false;
            for (int j = 0; j < 115; ++j) {
                for (int k = 0; k < 115; ++k) {
                    if (v[j][k] == x) {
                        found = true;
                        int prev = x;
                        int temp = x;
                        v[j][k] = 0;
                        if (s == "up") {
                            while (v[j - 1][k] != 0) {
                                temp = prev;
                                prev = v[j - 1][k];
                                v[j - 1][k] = temp;
                                --j;
                            }
                            v[j - 1][k] = prev;
                        } else if (s == "right") {
                            while (v[j][k + 1] != 0) {
                                temp = prev;
                                prev = v[j][k + 1];
                                v[j][k + 1] = temp;
                                ++k;
                            }
                            v[j][k + 1] = prev;
                        } else if (s == "left") {
                            while (v[j][k - 1] != 0) {
                                temp = prev;
                                prev = v[j][k - 1];
                                v[j][k - 1] = temp;
                                --k;
                            }
                            v[j][k - 1] = prev;
                        } else {
                            while (v[j + 1][k] != 0) {
                                temp = prev;
                                prev = v[j + 1][k];
                                v[j + 1][k] = temp;
                                ++j;
                            }
                            v[j + 1][k] = prev;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
        }
        int firstRow = 115, firstCol = 115, lastRow = 0, lastCol = 0;
        for (int j = 0; j < 115; ++j) {
            for (int k = 0; k < 115; ++k) {
                if (v[j][k] != 0) {
                    firstRow = min(firstRow, j);
                    firstCol = min(firstCol, k);
                    lastRow = max(lastRow, j);
                    lastCol = max(lastCol, k);
                }
            }
        }
        vi rowDist(lastRow - firstRow + 1);
        for (int i = firstRow; i <= lastRow; ++i) {
            for (int j = firstCol; j <= lastCol; ++j) {
                if (v[i][j] != 0) {
                    rowDist[i - firstRow] = j - firstCol + 1;
                }
            }
        }
        for (int i = firstRow; i <= lastRow; ++i) {
            string s = "";
            for (int j = firstCol; j < firstCol + rowDist[i - firstRow]; ++j) {
                if (v[i][j] == 0) {
                    s += " ";
                } else {
                    s += (char)(64 + v[i][j]);
                }
            }
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}