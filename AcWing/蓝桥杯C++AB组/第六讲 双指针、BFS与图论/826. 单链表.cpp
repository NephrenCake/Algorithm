#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/828/

const int N = 100010;

int n;
int h[N], e[N], ne[N], head, idx;

// 对链表进行初始化
void init() {
    head = -1;  // 相当于保护节点，性质与 ne[N] 相同。指向 -1 时，表示链表里没有内容
    idx = 0;  // 指向下一个待分配的空间下标，同时表示已经插入了几个元素（不包含删除）
}

// 将 x 插入到头节点上
void insert_to_head(int x) {
    e[idx] = x;  // 先在待分配的空间中保存值
    ne[idx] = head;  // 指明新节点的 next 域
    head = idx;  //  head 保护节点现在指向第一个元素
    idx++;  // 待分配空间指针向下移一位，为下一次插入元素做准备。
}

// 将 x 插入到下标为 k-1 的点的后面
void add(int k, int x) {
    e[idx] = x;  // 先在待分配的空间中保存值
    ne[idx] = ne[k - 1];  // 指明新节点（[idx]）的 next 域为节点（[k - 1]）的 next 域
    ne[k - 1] = idx;  // 更新前一个（第 k 个插入的）节点的 next 域为新节点
    idx++;  // 待分配空间指针向下移一位
}

// 将下标是 k-1（第 k 个插入）的点后面的点个删掉
void remove(int k) {
    if (k == 0)
        head = ne[head];  // 删除头节点
    else
        ne[k - 1] = ne[ne[k - 1]];//让k的指针指向，k下一个人的下一个人，那中间的那位就被挤掉了。
}

int main() {
    cin >> n;
    init();
    for (int i = 0; i < n; i++) {
        char s;
        cin >> s;
        if (s == 'H') {
            int x;
            cin >> x;
            insert_to_head(x);
        } else if (s == 'D') {
            int k;
            cin >> k;
            remove(k);
        } else if (s == 'I') {
            int k, x;
            cin >> k >> x;
            add(k, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
}
