class Solution {
    //Recursive Approch : We have two  choices either we keep the char as it is either we delete the char:
    public int solveRecursion(int index,char prev ,int currcharfreq,String s,int k){
        if(k<0) return Integer.MAX_VALUE;
        if(index>=s.length()) return 0;
        int res = Integer.MAX_VALUE;
        //Case 1: delete the char and add +1 in index , reduce -1 in k,everything same;
        res =Math.min(res,solveRecursion(index+1,prev,currcharfreq,s,k-1));
        // Case 2: we didn't delete the char:
        /// Case 2.1 --> If prev char is not same with curr one
        /// case 2.2 --> If prev char is same with curr one
        
        /// Case 2.1 --> If both char are not same means we encounter new char 
        /// Now len will increse by 1 ,index+1,and new currcharfreq=1;
        if(s.charAt(index)!=prev){
            res =Math.min(res,1+solveRecursion(index+1,s.charAt(index),1,s,k));
        }
        // Case 2.2 --> when both are equal  :
                          //Case 2.2.1 --> if len=1 , 9 ,99 then len is going to increase by 1
                          //Case 2.2.2 --> else case len is will remain same think 2--> 3or 7-8 or 98-->99
                          //See contraint it will not go beyond three digit
        else{
            //case 2.2.1 :
            if(currcharfreq==1 ||currcharfreq==9 || currcharfreq==99){
                res = Math.min(res,1+solveRecursion(index+1,s.charAt(index),currcharfreq+1,s,k));
            }
            //Case 2.2.2 :
            else{
                res = Math.min(res,solveRecursion(index+1,s.charAt(index),currcharfreq+1,s,k));
            }
        }
        return res;
        
    }
    public Integer dp[][][][];
    public int solveMemo(int index,char prev ,int currcharfreq,String s,int k){
        if(k<0) return Integer.MAX_VALUE;
        if(index>=s.length()) return 0;
        
        int res = Integer.MAX_VALUE;
        if(dp[index][prev-'a'][currcharfreq][k]!=null){
            return dp[index][prev-'a'][currcharfreq][k];
        }else{
            ///Case 1: delete the char and add +1 in index , reduce -1 in k,everything same;
            res= solveMemo(index+1,prev,currcharfreq,s,k-1);
            //Case 2: we didn't delete the char:
            if(s.charAt(index)!=prev){
            res =Math.min(res,1+solveMemo(index+1,s.charAt(index),1,s,k));
            }
            else{
                //case 2.2.1 :
                if(currcharfreq==1 ||currcharfreq==9 || currcharfreq==99){
                res = Math.min(res,1+solveMemo(index+1,s.charAt(index),currcharfreq+1,s,k));
                }
                //Case 2.2.2 :
                else{
                res = Math.min(res,solveMemo(index+1,s.charAt(index),currcharfreq+1,s,k));
                }   
            }
            dp[index][prev-'a'][currcharfreq][k] =res;
            return res;
        }
    }
  
  
    public int getLengthOfOptimalCompression(String s, int k) {
        //return solveRecursion(0,'=',0,s,k);
        int n = s.length();
        dp = new Integer[n][27][n+1][k+1];
        return solveMemo(0,(char)('a'+26),0,s,k);
    }
}
/*
Sol.1
Runtime : ~ Fail
Test Case : 53/136
Sol.2
Runtime : 756 ms
Test Case : All Passed
*/
