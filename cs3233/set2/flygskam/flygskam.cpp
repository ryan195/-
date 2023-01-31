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

double degree_to_radian(double deg) {
    return deg * M_PI / 180;
}

double calculate_dist(pair<double, double> a, pair<double,double> b) {
    return -1 * ((6381 * acos((cos(a.first)*cos(b.first)*cos(a.second-b.second)) + (sin(a.first)*sin(b.first)))) + 100);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0)->sync_with_stdio(0);
    int numAirports, numRoutes;
    cin >> numAirports >> numRoutes;
    string current, target;
    cin >> current >> target;
    map<string, pair<double, double>> mapp;
    map<string, int> visited;
    string s;
    double x, y;
    for (int i = 0; i < numAirports; ++i) {
        cin >> s >> x >> y;
        visited[s] = 0;
        mapp[s] = {degree_to_radian(x), degree_to_radian(y)};
    }
    string a, b;
    map<string, vector<pair<double, pair<string, string>>>> adjList;
    for (int i = 0; i < numRoutes; ++i) {
        cin >> a >> b;
        //Do some magic get adjlist
        double d = calculate_dist(mapp[a], mapp[b]);
        if (adjList.find(a) == adjList.end()) {
            adjList[a] = {};
        }
        if (adjList.find(b) == adjList.end()) {
            adjList[b] = {};
        }
        adjList[a].push_back({d, {b, a}});
        adjList[b].push_back({d, {a, b}});
    }
    priority_queue<pair<double, pair<string, string>>> pq;
    for (int i = 0; i < adjList[current].size(); ++i) {
        pq.push(adjList[current][i]);
    }
    visited[current] = 1;
    map<string, double> shortest;
    while ((visited[target] == 0) && (pq.size() > 0)) {
        pair<double, pair<string, string>> currPair = pq.top();
        pq.pop();
        if (visited[currPair.second.first] == 1) {
            continue;
        }
        for (int i = 0; i < adjList[currPair.second.first].size(); ++i) {
            pq.push(adjList[currPair.second.first][i]);
        }
        visited[currPair.second.first] = 1;
        shortest[currPair.second.first] = shortest[currPair.second.second] + currPair.first;
    } 
    if (visited[target] == 1) {
        cout << -1 * shortest[target] << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}