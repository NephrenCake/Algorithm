#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/description/1549/

string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
string s1, s2, s3, s4;

int main() {
    cin >> s1 >> s2 >> s3 >> s4;

    int i = 0;
    for (; i < min(s1.size(), s2.size()); i++)
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            cout << days[s1[i] - 'A'] << " ";
            break;
        }
    i++;
    for (; i < min(s1.size(), s2.size()); i++)
        if (s1[i] == s2[i] && (s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' && s1[i] <= 'N')) {
            int t = 0;
            if (s1[i] >= '0' && s1[i] <= '9') t += s1[i] - '0';
            else if (s1[i] >= 'A' && s1[i] <= 'N') t += s1[i] - 'A' + 10;
            printf("%02d:", t);
            break;
        }
    for (i = 0; i < min(s3.size(), s4.size()); i++)
        if (s3[i] == s4[i] && (s3[i] >= 'A' && s3[i] <= 'Z' || s3[i] >= 'a' && s3[i] <= 'z')) {
            printf("%02d", i);
            break;
        }
}
