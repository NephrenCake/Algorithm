#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/2068/

int main() {
    char ch, last;
    while (cin >> ch) {
        int t = ch - '0';
        if (t < 1 || t > 9) {
            last = ch;
            printf("%c", last);
        } else {
            t--;
            while (t--)
                printf("%c", last);
        }
    }
}
