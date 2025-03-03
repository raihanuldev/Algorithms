eita hocce ekta process ba technic, eita alogrithm na.. 

recursion + optimizetion => DP.
DP-2 prokar
1) top-down -> jeta recursion use kore kora hoi.
2) bottom up -> jeta loop dhia kore.
   

mememorization dhia code kub smart bhabe optimize kora jai..
``int fibo(int n)
{
    if(n==0 || n==1)
        return n;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n-1)+ fibo(n-2);
    return dp[n];
}``