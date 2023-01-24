#include <iostream>

using namespace std;

int a, b;

int invert(int n) {
    int res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    while (cin >> a >> b)
        if (invert(a) + invert(b) == invert(a + b))
            cout << a + b << endl;
        else
            cout << "NO" << endl;
}

// #include <iostream>
//
// using namespace std;
//
// int a, b;
//
// string invert(string str) {
//     unsigned int len = str.size();
//     for (int i = 0; i < len / 2; i++) {
//         char t = str[len - 1 - i];
//         str[len - 1 - i] = str[i];
//         str[i] = t;
//     }
//     return str;
// }
//
// void sol() {
//     int c = stoi(invert(to_string(a + b)));
//     int d = stoi(invert(to_string(a))) + stoi(invert(to_string(b)));
//     if (c == d) cout << a + b << endl;
//     else cout << "NO" << endl;
// }
//
// int main() {
//     while (cin >> a >> b)
//         sol();
// }
