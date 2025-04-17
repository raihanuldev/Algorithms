// Brute-Forces Approch 
// time complexity => O(n^2)

#include <bits/stdc++.h>
using namespace std;

bool twoSumPair(int arr[], int n, int target)
{
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] + arr[j] == target)
                return true;
        }
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
