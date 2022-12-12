#include <bits/stdc++.h>

using namespace std;

class Solution {
    /* n皇后问题 */
    int n;
    int methods = 0;
public:
    void main() {
        cin >> n;
        vector<bool> temp(n*2+1,true);
        vector<vector<bool>> vvi(3,temp);
        /*
         * 建立3个数组
         * 第一个表示竖行的占用情况
         * 第二个用x-y+n表示左下到右上的占用情况
         * 第三个用x+y表示左上到右下的占用情况
         */
        solve(1, vvi);
        cout << methods << endl;
    }

    void solve(int y, vector<vector<bool>> vvi) {
        //dfs
        if (y == n + 1) {
            methods++;
            return;
        }
        for (int x = 1; x <= n; x++) {
            if(vvi[0][x]&&vvi[1][x-y+n]&&vvi[2][x+y]){
                vector<vector<bool>> temp = vvi;
                temp[0][x] = temp[1][x-y+n] = temp[2][x+y] = false;
                solve(y+1,temp);
            }
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
