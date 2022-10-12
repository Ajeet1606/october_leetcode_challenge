class Solution {
    public int largestPerimeter(int[] nums) {
        Arrays.sort(nums); 
        
        for(int i=nums.length-1;i>=2;i--){
            
            if(nums[i] < nums[i-1]+nums[i-2])
                return nums[i]+nums[i-1]+nums[i-2]; // if sum of two sides is less then cuurent side then it is a valid triangle
        }
        return 0;
    }
}
