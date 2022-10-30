class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        //direction array:right, bottom, left,    top
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        //visited array
        bool v[m][n][k+1];
        //fill with false for every state.
        memset(v, false, sizeof(v));
        //make a queue to contain a state.
        queue<vector<int>>q;
        //answer steps.
        int steps = 0;
        //push starting point.
        q.push({0, 0, k});
        
        while(!q.empty()){
            int sz = q.size();
            //for every state.
            while(sz--){
                //get current one 
                vector<int>cur = q.front();
                //pop from the queue
                q.pop();
                //check if it's destination, return answer.
                if(cur[0] == m-1 and cur[1] == n-1) return steps;
                
                //explore every valid directions 
                for(auto d: dir){
                    int i = cur[0] + d[0];  //row
                    int j = cur[1] + d[1];  //col
                    int obs = cur[2];       //obstacle elimination power
                    
                    //traverse through valid cells
                    if(i>=0 and i<m and j>=0 and j<n){
                        //if cell is empty and not visited, visit and add in queue
                        if(grid[i][j] == 0 and !v[i][j][obs]){
                            //insert in queue 
                            q.push({i, j, obs});
                            //mark visited.
                            v[i][j][obs] = true;
                        }   
                        //if it's an obstacle, check if we can eliminate it and it's not visited.
                        else if(grid[i][j] == 1 and obs > 0 and !v[i][j][obs-1]){
                            //insert in queue
                            q.push({i, j, obs-1});
                            //mark visited
                            v[i][j][obs-1] = true;
                        }
                    }
                }
            }
            //update steps.
            ++steps;
        }
        //we didn't reach the destination, return -1.
        return -1;
    }
};