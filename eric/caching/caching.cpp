#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numStorage, numObjs, numAccess, obj;
    cin >> numStorage >> numObjs >> numAccess;
    unordered_map<int, vi> mapping;
    vi vect(numAccess);
    for (int i = 0; i < numAccess; ++i) {
        cin >> obj;
        if (mapping.find(obj) == mapping.end()) {
            mapping[obj] = {};
        }
        mapping[obj].push_back(i);
        vect[i] = obj;
    }
    for (auto it = mapping.begin(); it != mapping.end(); ++it) {
        reverse(it->second.begin(), it->second.end());
        if (it->second.size() > 0) {
            it->second.pop_back();
        }
    }
    int usedStorage = 0, numReads = 0;
    priority_queue<pii> storage;
    unordered_set<int> storage2;
    for (int i = 0; i < numAccess; ++i) {
        int curr = vect[i];
        int nextTime = 0;
        if (mapping[curr].size() > 0) {
            nextTime = mapping[curr][mapping[curr].size() - 1];
            mapping[curr].pop_back();
        } else {
            nextTime = numAccess + 1;
        }
        if (storage2.find(curr) == storage2.end()) {
            ++numReads;
            if (usedStorage < numStorage) {
                ++usedStorage;
            } else {
                pii gon = storage.top();
                storage.pop();
                storage2.erase(gon.second);
            }
        }
        storage.push({nextTime, curr});
        storage2.insert(curr);
    }
    cout << numReads << endl;
    return 0;
}