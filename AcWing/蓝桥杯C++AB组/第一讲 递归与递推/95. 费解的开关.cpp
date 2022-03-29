#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/97/

/**
 * 宏观考虑
 * 1. 顺序可以任意，一个格子只与其受影响次数有关
 * 2. 每个格子最多只按一次，因为按两次等于没按
 * 3. 每一行开关的操作完全被前一行的亮灭状态所唯一确定
 * 细节考虑
 * 1. 如何枚举第一行的操作（位运算，将二进制做成十进制）
 * 2. turn(x, y) 方向数组
 * 3. 时间复杂度：第一行32 * 25个开关 * 影响5个格子 * 500测试数据 = 200 0000
 */

const int N = 6;  // 字符串末尾有\0做结束符，因此一行（第二维）需要6的长度。当然第一维仅给5的长度是可以的
const int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};  // 方向数组

char g[N][N], backup[N][N];
int res = 10;

void turn(int x, int y) {
    // 改变五个格子的值
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
            continue;
        g[nx][ny] ^= 1;  // 异或1，即最低位取反；48->49、49->48
    }
}

void forward(int op) {
    memcpy(backup, g, sizeof g);  // 保存备份
    int step = 0;
    for (int i = 0; i < 5; i++)  // 指定第一行的变化
        if (op >> i & 1) {  // 如果第i位为1，则代表要按下开关
            step++;
            turn(0, i);
        }

    for (int i = 0; i < 4; i++)  // 查看0~4行
        for (int j = 0; j < 5; j++)  // 查看每一行的所有灯
            if (g[i][j] == '0') {
                step++;
                turn(i + 1, j);
            }  // 推演后续按灯，每一层的亮灭状态决定了下一层的按灯策略

    bool dark = false;
    for (int i = 0; i < 5; i++)
        if (g[4][i] == '0') {
            dark = true;
            break;
        }  // 检查最后一行是否全部灭灯

    if (!dark)
        res = min(res, step);  // 没有灭的灯，即成功，取最小值
    memcpy(g, backup, sizeof backup);  // 用备份还原现场
}

int main() {
    int n;
    cin >> n;
    while (n--) {  // 有n个待解决的情况
        for (int i = 0; i < 5; i++)
            cin >> g[i];  // 读入的是一个字符串

        res = 10;  // 较大的数，比6大就行
        for (int op = 0; op < 32; op++)
            forward(op);  // 仅是枚举第一行的操作可能，后续只是接下去推演而已

        if (res > 6)
            res = -1;  // 总次数超过6则视为无解
        cout << res << endl;
    }
}
