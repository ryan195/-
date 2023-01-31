#include <bits/stdc++.h>

#define INF INT_MAX
#define pb push_back
#define ub upper_bound
#define lb lower_bound

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long>>;
using vvll = vector<vector<long long>>;
using mii = map<int, int>;
using pii = pair<int, int>;

int arr[55][55];
int diffArr[100];

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < 55; ++i) {
        for (int j = 0; j < 55; ++j) {
            arr[i][j] = -1;
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <= 99; ++i) {
        for (int j = 0; j <= 99; ++j) {
            int maxPos = 0, curr = 0;
            int visited[55][55];
            memset(visited, 0, sizeof(visited));
            for (int k = 0; k < r; ++k) {
                for (int l = 0; l < c; ++l) {
                    if ((visited[k][l] == 0) && (arr[k][l] <= (i + j)) && (arr[k][l] >= i)) {
                        visited[k][l] = 1;
                        queue<pii> q;
                        q.push({k, l});
                        while (!q.empty()) {
                            ++curr;
                            pii curre = q.front();
                            q.pop();
                            int a = curre.first, b = curre.second;
                            if ((a > 0) && (arr[a - 1][b] <= i + j) && (arr[a - 1][b] >= i) && (visited[a - 1][b] == 0)) {
                                visited[a - 1][b] = 1;
                                q.push({a - 1, b});
                            }
                            if ((b > 0) && (arr[a][b - 1] <= i + j) && (arr[a][b - 1] >= i) && (visited[a][b - 1] == 0)) {
                                visited[a][b - 1] = 1;
                                q.push({a, b - 1});
                            }
                            if ((a < (r - 1)) && (arr[a + 1][b] <= i + j) && (arr[a + 1][b] >= i) && (visited[a + 1][b] == 0))  {
                                visited[a + 1][b] = 1;
                                q.push({a + 1, b});
                            }
                            if ((b < (c - 1)) && (arr[a][b + 1] <= i + j) && (arr[a][b + 1] >= i) && (visited[a][b + 1] == 0)) {
                                visited[a][b + 1] = 1;
                                q.push({a, b + 1});
                            }
                        }
                    }
                    maxPos = max(maxPos, curr);
                    curr = 0;
                }
            }
            diffArr[j] = max(diffArr[j], maxPos);
        }
    }
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        for (int j = 0; j < 100; ++j) {
            if (diffArr[j] >= q) {
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}