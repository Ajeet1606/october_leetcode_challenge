class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a1 = INT_MAX, a2 = INT_MAX;
        for(int i: nums){
            if(i <= a1) a1 = i;
            else if(i <= a2) a2 = i;
            else return true;
        }
        return false;
    }
};