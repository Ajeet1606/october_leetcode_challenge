class Solution {
public:
    
    int shiftAndCount(int xShift, int yShift, vector<vector<int>>& M, vector<vector<int>>& R){
        int leftShiftCount = 0, rightShiftCount = 0;
        int rRow = 0;
        
        for(int mRow = yShift; mRow < M.size(); ++mRow){
            int rCol = 0;
            for(int mCol = xShift; mCol < M.size(); ++mCol){
                if(M[mRow][mCol] == 1 and M[mRow][mCol] == R[rRow][rCol])
                    leftShiftCount += 1;
                if(M[mRow][rCol] == 1 and M[mRow][rCol] == R[rRow][mCol])
                    rightShiftCount += 1;
                rCol++;
            }
            rRow++;
        }
        
        return max(leftShiftCount, rightShiftCount);
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maxOverlaps = 0;
        
        for(int yShift = 0; yShift < A.size(); ++yShift){
            for(int xShift = 0; xShift < A.size(); ++xShift){
                maxOverlaps = max(maxOverlaps, shiftAndCount(xShift, yShift, A, B));
                
                maxOverlaps = max(maxOverlaps, shiftAndCount(xShift, yShift, B, A));
            }
        }
        
        return maxOverlaps;
    }
};