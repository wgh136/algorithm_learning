# Educational Codeforces Round 140

## C. Count Binary Strings
[题目](https://codeforces.com/contest/1767/problem/C)

给一个整数n，求可能的长度为n的01串数量，限制如下：

对于1<i<j<n，给定$a_{i,j}$:
- 其值为0，区间[i,j]无限制
- 其值为1，区间[i,j]均相同
- 其值为2，区间[i,j]存在不同

**动态规划**

定义$f_{i,j}$表示区间[1,i]中[i,j]相同的构造01串方法数，则答案为$\sum_{i=1}^{n}f_{n,i}$

显然$f_{1,1}=2$. 

转移方程：
- $f_{i+1,j}$ += $f_{i,j}$ 
- $f_{i+1,j+1}$ += $f_{i,j}$ 

在转移前，需要判断$f_{i,j}$是否成立。

- 对于u∈[1,i]，如果$a_{u,i}=1$，则u>=j
- 对于u∈[1,i]，如果$a_{u,i}=2$, 则u<j

违反这两条规则意味着不存在这样的构造方法，将$f_{i,j}$设为0.

```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 998244353;

class Solution{
    int a[101][101];
    ll dp[110][110];
    ll ans = 0;
    int n = 0;
public:
    void main(){

        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                cin >> a[i][j];
            }
        }

        dp[1][1] = 2;
        for (int i = 1; i <= n; i++ )
            for (int j = 1; j <= i; j++ ) {
                bool flag = false;
                for (int k = 1; k <= i; k++ ) {
                    if(a[k][i] == 1 && k < j) flag = true;
                    if(a[k][i] == 2 && k >= j) flag = true;
                }
                if(flag) dp[i][j] = 0;
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                dp[i + 1][i + 1] = (dp[i + 1][i + 1] + dp[i][j]) % MOD;
            }

        for (int i = 1; i <= n; i++ )
            ans = (ans + dp[n][i]) % MOD;
        cout << ans << endl;
    }

};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    s.main();
    return 0;
}
```