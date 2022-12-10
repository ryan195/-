#include <bits/stdc++.h>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string x;
    int daysCounter = 0;
    while (!cin.eof()) {

        getline(cin, x);
        if (x.length() == 0) {
            break;
        }
        ++daysCounter;
        string action;
        map<string, int> mappingTime;
        map<string, double> mapping;
        while (true) {
            cin >> action;
            if (action == "CLOSE") {
                string extra;
                getline(cin, extra);
                break;
            }
            string name; 
            int time;
            cin >> name;
            cin >> time;
            if (action == "ENTER") {
                mappingTime.insert({name, time});
            } else {
                int spent = time - mappingTime.find(name)->second;
                if (mapping.find(name) == mapping.end()) {
                    mapping.insert({name, spent});
                } else {
                    mapping.find(name)->second += (spent);
                }
                mappingTime.erase(name);
            }
        }
        cout << "Day " << daysCounter << endl;
        for (auto it = mapping.begin(); it != mapping.end(); ++it) {
            cout << it->first << " $" << setprecision(2) << fixed << it->second/10 << endl;
        }
        cout << endl;
    }
    return 0;
}