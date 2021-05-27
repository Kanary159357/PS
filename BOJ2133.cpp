#include <iostream>

using namespace std;
int main()
{
    int n;
    unsigned long long dp[35];
    cin >> n;
    fill(&dp[0], &dp[0] + 35, 0);
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        dp[i] += (dp[i - 2] * 3);
        int temp = i - 4;
        while (temp >= 2)
        {
            dp[i] += (dp[temp] * 2);
            temp -= 2;
        }
        dp[i] += 2;
    }

    cout << dp[n] << endl;
}