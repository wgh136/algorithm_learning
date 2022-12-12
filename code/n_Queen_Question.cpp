#include <bits/stdc++.h>

using namespace std;

class Solution {
    /* n皇后问题 */
    int n;
    int methods = 0;
public:
    void main() {
        cin >> n;
        vector<map<int, bool>> vvi(3);
            /*
                第一个哈希表储存已占用的列
                第二个哈希表储存已占用的右上到左下对角线
                第三个哈希表储存已占用的左上到右下对角线
            */
        solve(1, vvi);
        cout << methods << endl;
    }

    void solve(int row, vector<map<int, bool>> vvi) {
        // DFS
        if (row == n + 1) {
            methods++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            vector<map<int, bool>> temp = vvi;
            try {
                vvi[0].at(i);
                goto m;
            }
            catch (...) {}
            try {
                vvi[1].at(i - row);
                goto m;
            }
            catch (...) {}
            try {
                vvi[2].at(i + row);
                goto m;
            }
            catch (...) {}

            temp[0][i] = true;
            temp[1][i - row] = true;
            temp[2][i + row] = true;
            solve(row + 1, temp);
            m:; //end
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    s.main();
    return 0;
}