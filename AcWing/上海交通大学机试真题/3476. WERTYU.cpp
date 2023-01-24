#include <iostream>

using namespace std;

string s, mm = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++)
            if (mm.find(s[i]) != -1)
                s[i] = mm[mm.find(s[i]) - 1];
        cout << s << endl;
    }
}
