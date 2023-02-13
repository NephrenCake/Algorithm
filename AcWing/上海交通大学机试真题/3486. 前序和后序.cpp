#include <iostream>

using namespace std;

int n, c[25][25];  // 动态规划求组合数 c[i][j] 从i个里面选j个的组合数

int dfs(string pre, string post) {
    int sum = 1, cnt = 0;
    pre.erase(pre.begin());  // 将根节点删去
    post.erase(post.end() - 1);
    for (int i = 0, j = 0; i < pre.size();) {  // 双指针。i为子树的根，j将遍历找到子树的根
        while (pre[i] != post[j]) j++;  // 此时，i~j划分出一个区间，该区间包含该子树的所有节点
        sum *= dfs(pre.substr(i, j - i + 1), post.substr(i, j - i + 1));  // 递归计算该子树的可能组合数
        cnt++;  // 当前层子树个数+1
        i = ++j;  // 找下一个子树的节点区间
    }
    return sum * c[n][cnt];  // 先序加后序可推该层将有cnt个孩子，n叉树表示有n个位置可以放这些子树
}

int main() {
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];

    string pre, post;
    while (cin >> n >> pre >> post)
        cout << dfs(pre, post) << endl;
}
