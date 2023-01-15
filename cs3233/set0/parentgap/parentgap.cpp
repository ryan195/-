#include <bits/stdc++.h>
    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    vi monthDays = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vi years(1001);
    memset(&years[0], 0, sizeof(years));
    int currYear = 0, currMonth = 0, currDate = 1, currDay = 6;
    while (currYear < 1001) {
        ++currDay;
        currDay = (currDay < 7) ? currDay : 0;
        ++currDate;
        if (currDate > monthDays[currMonth]) {
            currDate = 1;
            ++currMonth;
            if (currMonth > 11) {
                currMonth = 0;
                ++currYear;
                if (isLeapYear(currYear)) {
                    monthDays[1] = 29;
                } else {
                    monthDays[1] = 28;
                }
            }
        }
        if ((currMonth == 4) && (currDay == 0) && (years[currYear] == 0)) {
            years[currYear] = (currDate < 4) ? 6 : 5;
        }
    }
    int y;
    cin >> y;
    cout << years[y - 2000] << " weeks" << endl;
    return 0;
}