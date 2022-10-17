class Solution {
    //Recursion: because here we need to check all possiblities and We need to opt mini for all ways
    // IBH method implemented:Induction,Base Case Hypothesis..
    public static int solveR(int indx ,int[] jd,int d){
        //Base Case :
        if(d==1) return max(jd,indx);
        else{
            int val =Integer.MIN_VALUE;
            int res =Integer.MAX_VALUE;
            // Cutting at diff length till len-d+1 to get min:
            for(int i=indx;i<jd.length-d+1;i++){
                val = Math.max(val,jd[i]);
                res =Math.min(res,val+solveR(i+1,jd,d-1));
            }
            return res;
        }
    }
    public static int max(int[] arr,int idx){
        int res =0;
        for(int i=idx;i<arr.length;i++){
            res = Math.max(res,arr[i]);
        }
        return res;
    }
    //Memoization ~ Recursion + Memory
    public static int solveMemo(int indx,int[] jd,int d,int dp[][]){
        if(d==1) return max(jd,indx);
        if(dp[indx][d]!=-1) return dp[indx][d];
        else{
            int val =Integer.MIN_VALUE;
            int res =Integer.MAX_VALUE;
            for(int i=indx;i<jd.length-d+1;i++){
                val = Math.max(val,jd[i]);
                res =Math.min(res,val+solveMemo(i+1,jd,d-1,dp));
            }
            return dp[indx][d]=res;
        }
    }
    public int minDifficulty(int[] jobDifficulty, int d) {
        if(d>jobDifficulty.length) return -1;
        //return solveR(0,jobDifficulty,d);
        int dp[][] =new int[jobDifficulty.length+1][d+1];
        Arrays.stream(dp).forEach(a->Arrays.fill(a,-1));
        return solveMemo(0,jobDifficulty,d,dp);
    }
}
