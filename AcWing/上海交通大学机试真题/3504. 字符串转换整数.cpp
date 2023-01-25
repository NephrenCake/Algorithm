#include <iostream>

using namespace std;

int ans;
string str;
bool start;

int main() {
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        if (str[i] >= '0' && str[i] <= '9') {
            if (!start)
                start = true;
            if (ans <= (INT32_MAX - (str[i] - '0')) / 10)
                ans = ans * 10 + (str[i] - '0');
            else {
                cout << "-1";
                return 0;
            }
        } else if (start)
            break;
    if (!start)
        cout << "-1";
    else
        cout << ans;
    return 0;
}
