#include <iostream>
#include<vector>
using namespace std;
 

int max_loot(vector <int> arr, int n)
{
    // Your code here
    vector <int> dp(n,-1);
    if(n == 1){
        return arr[0];
    }
    if(n == 2){
        return max(arr[1],arr[0]);
    }
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i = 2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }
    return dp[n-1];   
}

// Driver Code
int main()
{
    vector<int> arr = { 5, 5, 10, 100, 10, 5 };
    int N = arr.size();
    cout << max_loot(arr, N) << endl;
    return 0;
}