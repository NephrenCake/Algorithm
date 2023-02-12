#include <iostream>

using namespace std;

int a, b;

int invert(int x) {
    int res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
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
// string a, b;
//
// string invert(string x) {
//     for (int i = 0, j = x.size() - 1; i < x.size() / 2; i++, j--)
//         swap(x[i], x[j]);
//     return x;
// }
//
// int main() {
//     while (cin >> a >> b) {
//         int x = stoi(invert(a)) + stoi(invert(b));
//         int y = stoi(invert(to_string(stoi(a) + stoi(b))));
//         if (x == y) cout << stoi(a) + stoi(b) << endl;
//         else cout << "NO" << endl;
//     }
// }
