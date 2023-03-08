class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> ans = {1};
        for (int i = 2; i <= N; i++) {
            int l = -1, r = ans.size() - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (compare(ans[mid], i)) l = mid;
                else r = mid - 1;
            }
            ans.push_back(i);
            for (int j = ans.size() - 2; j > r; j--) swap(ans[j], ans[j + 1]);
        }
        return ans;
    }
};
