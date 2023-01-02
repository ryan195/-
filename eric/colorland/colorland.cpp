#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numColors;
    cin >> numColors;
    vi numMoves = {200001, 200001, 200001, 200001, 200001, 200001};
    vi vect;
    for (int i = 0; i < numColors; ++i) {
        string color;
        cin >> color;
        if (color[0] == 'B') {
            vect.push_back(0);
        } else if (color[0] == 'O') {
            vect.push_back(1);
        } else if (color[0] == 'P') {
            vect.push_back(2);
        } else if (color[0] == 'G') {
            vect.push_back(3);
        } else if (color[0] == 'R') {
            vect.push_back(4);
        } else {
            vect.push_back(5);
        }
    }
    reverse(vect.begin(), vect.end());
    for (int i = 0; i < vect.size(); ++i) {
        int col = vect[i];
        int mini = 200001;
        bool hasGiven = false;
        for (int j = 0; j < 6; ++j) {
            if (numMoves[j] < mini) {
                mini = numMoves[j];
                hasGiven = true;
            }
        }
        if (hasGiven) {
            numMoves[col] = (mini + 1); 
        } else {
            numMoves[col] = 1;
        }
    }
    int fin = 200001;
    for (int i = 0; i < 6; ++i) {
        if (numMoves[i] < fin) {
            fin = numMoves[i];
        }
    }
    cout << fin << endl;
    return 0;
}