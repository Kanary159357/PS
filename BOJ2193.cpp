#include <iostream>

using namespace std;
int main()
{
    int n;
    unsigned long long dp[100][2];
    cin >> n;
    dp[1][1] = 1;
    dp[1][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1] << endl;
}