#include <iostream>
#include <unordered_map>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unordered_map<string, int> mp = {
        {"January",   1},
        {"February",  2},
        {"March",     3},
        {"April",     4},
        {"May",       5},
        {"June",      6},
        {"July",      7},
        {"August",    8},
        {"September", 9},
        {"October",   10},
        {"November",  11},
        {"December",  12}
};
string wd[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int cnt(int d, int m, int y) {
    days[2] = y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 29 : 28;
    while (--m) d += days[m];
    while (--y) d += y % 400 == 0 || y % 4 == 0 && y % 100 != 0 ? 366 : 365;
    return d % 7;
}

int main() {
    int a, c;
    string b;
    while (cin >> a >> b >> c)
        cout << wd[cnt(a, mp[b], c)] << endl;
}
