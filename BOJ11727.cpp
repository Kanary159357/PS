#include <iostream>
#include <algorithm>
using namespace std;
int dp[10010];
int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 2] * 2;
        dp[i] += dp[i - 1];
        dp[i] %= 10007;
    }

    cout << dp[n] << endl;

    return 0;
}