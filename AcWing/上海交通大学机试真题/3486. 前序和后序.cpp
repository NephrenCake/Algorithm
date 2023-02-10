#include <iostream>

using namespace std;

const int N = 25;
int n, c[N][N];  // ��̬�滮������� c[i][j] ��i������ѡj���������
string s1, s2;

int dfs(string pre, string post) {
    int sum = 1, cnt = 0;
    pre.erase(pre.begin());  // �����ڵ�ɾȥ
    post.erase(post.end() - 1);

    for (int i = 0, j = 0; i < pre.size(); j++)  // ˫ָ�롣iΪ�����ĸ���j�������ҵ������ĸ�
        if (pre[i] == post[j])  {  // ��ʱ��i~j���ֳ�һ�����䣬��������������������нڵ�
            // �ݹ����������Ŀ��������
            sum *= dfs(pre.substr(i, j - i + 1), post.substr(i, j - i + 1));
            cnt++;  // ��ǰ����������+1
            i = j + 1;  // ����һ�����ӵĽڵ�����
        }
    return sum * c[n][cnt];  // ����Ӻ�����Ƹò㽫��cnt�����ӣ�n������ʾ��n��λ�ÿ��Է���Щ����
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
