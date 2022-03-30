#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// https://www.acwing.com/problem/content/118/

/**
 *      -+--
 *      ----
 *      ----
 *      -+--
 * 目标：全部变成-
 * 类型：开关问题
 * 1. 只按一次
 * 2. 顺序无关
 * 做法：
 * 1. 枚举所有方案 16位的二进制数 为1处表示按
 * 2. 按照该方案操作所有灯泡
 * 3. 判断，如果全亮就记录方案
 * 细节
 * 1. 时间复杂度：2^(4*4)种方案 * (16*7按开关 + 16判 + 16记录)= 65536 * 16 * 9 = 1kw 可以支持暴搜
 * 2. 步数最小
 * 3. 字典序最小
 */

/**
 * 解2 用string 问题在于使用string不能用memcpy()，地址并不连续。要for循环cp
 */


#define x first
#define y second
#define PII pair<int, int>  // 技巧 减少代码量

const int N = 4;

string g[N + 1], backup[N + 1];

inline int is_turned(int op, int i, int j) {
    // 检查在op操作下，第(i, j)位是否要按，位数按 [[1, 2, 3, 4], [5, ...], ...] 排列
    return op >> (4 * i + j) & 1;
}

void turn_one(int x, int y) {
    if (g[x][y] == '+') g[x][y] = '-';
    else g[x][y] = '+';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i++) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

void str_cp(string a[], string b[]) {
    // 不需要加&，str[]本身就是指针 basic_string<char> *b
    for (int i = 0; i < N; i++) {
        a[i] = b[i];
    }
}

int main() {
    // 写法一 不行
    // for (auto& i : g)
    //     for (char& j : i)
    //         cin >> j;
    // 写法二 不行
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         cin >> g[i][j];
    // 写法三 不行
    // for (auto& i : g)
    //     cin >> i;
    // 写法四
    for (int i = 0; i < N; i++)
        cin >> g[i];

    // test
    // for (int i = 0; i < N; i++)
    //     cout << g[i] << endl;

    vector<PII > ans;
    for (int op = 0; op < 1 << 16; op++) {
        // 枚举每一种开关策略
        // 注意 是1左移16位，而不是2左移16位
        vector<PII > temp;
        str_cp(backup, g);

        // 1. 进行操作
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (is_turned(op, i, j)) {
                    temp.push_back({i, j});  // 记录路径
                    turn_all(i, j);
                }

        // 2. 判断
        bool has_closed = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (g[i][j] == '+')
                    has_closed = true;
        if (!has_closed)
            if (ans.empty() || ans.size() > temp.size())
                ans = temp;

        str_cp(g, backup);
    }

    cout << ans.size() << endl;
    for (auto& an : ans)
        cout << an.x + 1 << ' ' << an.y + 1 << endl;  // 注意 下标+1
}


/**
 * 解1 用char[]
 */

/*
#define x first
#define y second
typedef pair<int, int> PII;  // 等价

const int N = 4;
char g[N][N], backup[N][N];

inline int is_turned(int op, int i, int j) {
    // 检查在op操作下，第(i, j)位是否要按，位数按 [[1, 2, 3, 4], [5, ...], ...] 排列
    return op >> (4 * i + j) & 1;
}

void turn_one(int x, int y) {
    if (g[x][y] == '+')
        g[x][y] = '-';
    else
        g[x][y] = '+';
}

void turn_all(int x, int y) {
    for (int i = 0; i < 4; i++) {
        turn_one(x, i);
        turn_one(i, y);
    }
    turn_one(x, y);
}

int main() {
    // 写法一
    // for (auto& i : g)
    //     for (char& j : i)
    //         cin >> j;
    // 写法二
    // for (int i = 0; i < N; i++)
    //     for (int j = 0; j < N; j++)
    //         cin >> g[i][j];
    // 写法三
    for (auto& i : g)
        cin >> i;
    // 写法四
    // for (int i = 0; i < N; i++)
    //     cin >> g[i];

    // test
    // for (int i = 0; i < N; i++)
    //     cout << g[i] << endl;

    vector<PII > ans;
    for (int op = 0; op < 1 << 16; op++) {
        // 枚举每一种开关策略
        // 注意 是1左移16位，而不是2左移16位
        vector<PII > temp;
        memcpy(backup, g, sizeof g);

        // 1. 进行操作
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (is_turned(op, i, j)) {
                    temp.push_back({i, j});  // 记录路径
                    turn_all(i, j);
                }

        // 2. 判断
        bool has_closed = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (g[i][j] == '+')
                    has_closed = true;

        if (!has_closed)
            if (ans.empty() || ans.size() > temp.size())
                ans = temp;

        memcpy(g, backup, sizeof backup);
    }

    cout << ans.size() << endl;
    for (auto& an : ans)
        cout << an.x + 1 << ' ' << an.y + 1 << endl;  // 注意 下标+1
}

*/