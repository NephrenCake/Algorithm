#include <iostream>

using namespace std;

int n, c[25][25];  // ��̬�滮������� c[i][j] ��i������ѡj���������

int dfs(string pre, string post) {
    int sum = 1, cnt = 0;
    pre.erase(pre.begin());  // �����ڵ�ɾȥ
    post.erase(post.end() - 1);
    for (int i = 0, j = 0; i < pre.size();) {  // ˫ָ�롣iΪ�����ĸ���j�������ҵ������ĸ�
        while (pre[i] != post[j]) j++;  // ��ʱ��i~j���ֳ�һ�����䣬��������������������нڵ�
        sum *= dfs(pre.substr(i, j - i + 1), post.substr(i, j - i + 1));  // �ݹ����������Ŀ��������
        cnt++;  // ��ǰ����������+1
        i = ++j;  // ����һ�������Ľڵ�����
    }
    return sum * c[n][cnt];  // ����Ӻ�����Ƹò㽫��cnt�����ӣ�n������ʾ��n��λ�ÿ��Է���Щ����
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
