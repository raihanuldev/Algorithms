#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1005];

int fibo(int n)
{
    for(int i =2; i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    cout<<fibo(n);
    return 0;
}