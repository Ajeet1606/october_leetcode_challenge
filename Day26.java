class Solution {
    /*
    Brute Force --> TLE
     public boolean checkSubarraySum(int[] nums, int k) {
        for (int i = 0; i < nums.length; ++i) {
            int sum = nums[i];
            for (int j = i + 1; j < nums.length; ++j) {
                sum += nums[j];
                if (sum % k == 0) return true;
            }
        }

        return false;
    }
    */

    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int sum =0;
        for(int i=0;i<nums.length;i++){
            sum +=nums[i];
            sum %=k;
            //Case 1: if sum ==0 and i>0(means sum of atleast 2 ele)
            if(sum==0 && i>0) return true;
            
            //Case 2: if sum is already in map(means the elem betn them must be %k=0 and diff betn ind>1)
            if(map.containsKey(sum) && i-map.get(sum)>1) return true;
            
            //Case if map does not contains sum add in map with its index;
            map.putIfAbsent(sum,i);
        }
        return false;
    } 
