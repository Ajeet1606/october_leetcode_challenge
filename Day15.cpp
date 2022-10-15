class Solution {
public:
    
    int solve(int idx, char prev, int curr_char_freq_cnt, string &s, int k){
        if(k < 0) return 1e9;
        if(idx >= s.size()) return 0;
        
        int res = 1e9;
        
        //we've k>0, we delete curr char from string, idx moves, k reduces by 1, everything remains same.        
        res = min(res, solve(idx+1, prev, curr_char_freq_cnt, s, k-1));
        
        //if we didn't delete,
        //and current char doesn't match the previous one, it'll be a new char, next res will increase by 1, idx+1, freq becomes 1, string & k remain same.
        if(s[idx] != prev){
            res = min(res, 1 + solve(idx+1, s[idx], 1, s, k));
        }
        //now, if curr matched prev, we join it with them,
        else{   //if freq was, 1/9/99, it'll increase to 2/10/100 so, res increase by 1, and freq also.
            if(curr_char_freq_cnt == 1 or curr_char_freq_cnt == 9 or curr_char_freq_cnt == 99){
                res = min(res, 1 + solve(idx+1, s[idx], curr_char_freq_cnt+1, s, k));
            }else{  //if freq wasn't as above, only freq increases, result remains same. i.e. for 4 -> 5
                res = min(res, solve(idx+1, s[idx], curr_char_freq_cnt+1, s, k));
            }
        }
        
        return res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        return solve(0, '#', 0, s, k);
    }
};


//--------------------------------------Memoization-------------------------------------


class Solution {
    int n;
public:
    
    int solve(int idx, char prev, int curr_char_freq_cnt, string &s, int k, int dp[][27][11][101]){
        if(k < 0) return 1e9;
        if(idx >= s.size()) return 0;
        
        //when freq >= 10, make it 10, as it's effect in res is still 2.
        if(curr_char_freq_cnt >= 10)
            curr_char_freq_cnt = 10;
        
        if(dp[idx][prev-'a'][curr_char_freq_cnt][k] != -1)
            return dp[idx][prev-'a'][curr_char_freq_cnt][k];
        
        int res = 1e9;
        
        //we've k>0, we delete curr char from string, idx moves, k reduces by 1, everything remains same.        
        res = min(res, solve(idx+1, prev, curr_char_freq_cnt, s, k-1, dp));
        
        //if we didn't delete,
        //and current char doesn't match the previous one, it'll be a new char, next res will increase by 1, idx+1, freq becomes 1, string & k remain same.
        if(s[idx] != prev){
            res = min(res, 1 + solve(idx+1, s[idx], 1, s, k, dp));
        }
        //now, if curr matched prev, we join it with them,
        else{   //if freq was, 1/9/99, it'll increase to 2/10/100 so, res increase by 1, and freq also.
            if(curr_char_freq_cnt == 1 or curr_char_freq_cnt == 9 or curr_char_freq_cnt == 99){
                res = min(res, 1 + solve(idx+1, s[idx], curr_char_freq_cnt+1, s, k, dp));
            }else{  //if freq wasn't as above, only freq increases, result remains same. i.e. for 4 -> 5
                res = min(res, solve(idx+1, s[idx], curr_char_freq_cnt+1, s, k, dp));
            }
        }
        
        return dp[idx][prev-'a'][curr_char_freq_cnt][k] = res;
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        
        if(n == 100){
            bool all_same = true;
            for(int i=1; i<n; i++){
                if(s[i] != s[i-1]){
                    all_same = false;
                    break;
                }
            }
            if(all_same) return 4;
        }
        
        //n+1, as string size is n
        //27, as we can have 26 different chars
        //11, as if freq goes above 10, it's contibution in result will still be 2, so make them 10 when it cross.
        //101, value of k.
        int dp[n+1][27][11][101];
        memset(dp, -1, sizeof(dp));
        
        return solve(0, 'z'+1, 0, s, k, dp);
    }
};