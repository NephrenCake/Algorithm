#include <bits/stdc++.h>

using namespace std;

// https://www.acwing.com/problem/content/1495/

const int N = 1e4 + 10;

struct P {
    int arrive;
    int service;

    bool operator<(const P &p) const {
        return arrive < p.arrive;
    }
} persons[N];

int n, k, tot, tot_p;
priority_queue<int, vector<int>, greater<>> windows;

int main() {
    cin >> n >> k;
    int hh, mm, ss, p;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &p);
        p = min(p, 60);
        persons[i] = {(hh * 60 + mm) * 60 + ss, p * 60};
    }
    sort(persons, persons + n);
    for (int i = 0; i < k; i++)
        windows.push(8 * 3600);

    for (int i = 0; i < n; i++) {  // 注意，普通数组不要用增强for！
        auto &person = persons[i];
        if (person.arrive > 17 * 3600)
            break;

        int start = max(windows.top(), person.arrive);
        windows.pop();
        windows.push(start + person.service);
        tot += start - person.arrive;
        tot_p++;
    }
    printf("%.1lf", (double) tot / tot_p / 60);
}
