// Brute-Forces Approch 
// time complexity => O(n^2)

#include <bits/stdc++.h>
using namespace std;

bool twoSumPair(int arr[], int n, int target)
{
    int i = 0, j = n-1;
    while(i<j)
    {
        if(arr[i] + arr[j]==target){
            return true;
        }
        else if (arr[i]+arr[j] < target)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {1, 2, 3, 4, 5};
    int target = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (twoSumPair(arr, n, target)) 
        cout << "Yes, pair exists\n";
    else 
        cout << "No pair found\n";

    return 0;
}
