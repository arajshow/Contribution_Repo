class Solution {
public:
    int dp[600][102][102];
    int helper(vector<pair<int,int>> &arr,int idx,int zeroes,int ones){
        if(idx == arr.size()) return 0;
        if(dp[idx][zeroes][ones] != -1) return dp[idx][zeroes][ones];
        auto cur = arr[idx];
        // cout<<cur.first<<" "<<cur.second<<endl;
        if(zeroes >= cur.first and ones >= cur.second){
            int x = 1 + helper(arr,idx+1,zeroes-cur.first,ones - cur.second);
            int y = helper(arr,idx+1,zeroes,ones);
            return dp[idx][zeroes][ones] = max(x,y);
        }
        else{
            return dp[idx][zeroes][ones] = helper(arr,idx+1,zeroes,ones);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> arr;
        memset(dp,-1,sizeof(dp));
        for(auto s:strs){
            int v[2] = {0};
            for(auto x:s){
                v[x-'0']++;
            }
            arr.push_back({v[0],v[1]});
        }
        sort(arr.begin(),arr.end());
        int ans = helper(arr,0,m,n);
        return ans;
    }
};