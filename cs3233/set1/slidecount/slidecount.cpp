#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int numElements, numConstant;
    cin >> numElements >> numConstant;
    vi qry(numElements + 1);
    memset(&qry[0], 0, sizeof(qry));
    vi vect(numElements);
    for (int i = 0; i < numElements; ++i) {
        cin >> vect[i];
    }
    int summ = vect[0];
    int s = 0, e = 0;
    while (s < numElements) {
        ++qry[s];
        --qry[e + 1];
        if ((e + 1) == numElements) {
            summ -= vect[s];
            ++s;
        } else if ((summ + vect[e + 1]) > numConstant) {
            summ -= vect[s];
            ++s;
        } else {
            summ += vect[e + 1];
            ++e;
        }
    }
    cout << qry[0] << endl;
    for (int i = 1; i < numElements; ++i) {
        qry[i] += qry[i - 1];
        cout << qry[i] << endl;
    }
    return 0;
}