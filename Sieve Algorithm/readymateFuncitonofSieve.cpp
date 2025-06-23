#include <bits/stdc++.h>
using namespace std;

const int MaxConstrant = 100;

bool isPrime(int number)
{
    vector<bool> primezone(MaxConstrant + 1, true);
    for (int i = 2; i * i <= MaxConstrant; i++)
    {
        if (primezone[i])
        {
            for (int j = i + i; j <= MaxConstrant; j += i)
            {
                primezone[j] = false;
            }
        }
    }
    return primezone[number];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number;
    cin>>number;
    if(isPrime(number)){
        cout<<"Prime\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}