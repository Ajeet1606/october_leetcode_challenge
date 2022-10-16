//---------------------------------Recursion----------------------------------


class Solution {
public:
    int n;
    int solve(int i, int days, vector<int>&jobD){
      
        if(days == 1){
            return *max_element(jobD.begin()+i, jobD.end());
        }
        
        int res = INT_MAX;
        int curr = INT_MIN;
        
        for(int j=i; j<=n-days; j++){
            curr = max(curr, jobD[j]);
            res = min(res, curr + solve(j+1, days-1, jobD));
        }
        
        return res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n < d) return -1;
        return solve(0, d, jobDifficulty);
    }
};


//------------------------------Memoization-------------------------------------


class Solution {
public:
    int n;
    int dp[301][11];
    int solve(int i, int days, vector<int>&jobD){
      
        if(days == 1){
            return *max_element(jobD.begin()+i, jobD.end());
        }
        
        if(dp[i][days] != -1) return dp[i][days];
        
        int res = INT_MAX;
        int curr = INT_MIN;
        
        for(int j=i; j<=n-days; j++){
            curr = max(curr, jobD[j]);
            res = min(res, curr + solve(j+1, days-1, jobD));
        }
        
        return dp[i][days] = res;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(n < d) return -1;
        
        memset(dp, -1, sizeof(dp));
        return solve(0, d, jobDifficulty);
    }
};