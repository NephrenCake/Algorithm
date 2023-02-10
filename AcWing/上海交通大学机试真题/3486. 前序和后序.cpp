#include <iostream>

using namespace std;

const int N = 25;
int n, c[N][N];  // 动态规划求组合数 c[i][j] 从i个里面选j个的组合数
string s1, s2;

int dfs(string pre, string post) {
    int sum = 1, cnt = 0;
    pre.erase(pre.begin());  // 将根节点删去
    post.erase(post.end() - 1);

    for (int i = 0, j = 0; i < pre.size(); j++)  // 双指针。i为子树的根，j将遍历找到字数的根
        if (pre[i] == post[j])  {  // 此时，i~j划分出一个区间，该区间包含该子树的所有节点
            // 递归计算该子树的可能组合数
            sum *= dfs(pre.substr(i, j - i + 1), post.substr(i, j - i + 1));
            cnt++;  // 当前层子树个数+1
            i = j + 1;  // 找下一个孩子的节点区间
        }
    return sum * c[n][cnt];  // 先序加后序可推该层将有cnt个孩子，n叉树表示有n个位置可以放这些子树
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];

    while (cin >> n) {
        cin >> s1 >> s2;
        cout << dfs(s1, s2) << endl;
    }
}
