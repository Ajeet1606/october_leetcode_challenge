class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        //make pair of grow time and plant time, so we can plant trees which take max time of growing, first.
        vector<pair<int, int>>p;
        for(int i=0; i<n; i++){
            p.push_back({growTime[i], plantTime[i]});
        }
        
        sort(p.rbegin(), p.rend());
        
        int total = 0, planting = 0;
        for(int i=0; i<n; i++){
            planting += p[i].second;
            //planting is the day when a new planting or growing starts
            total = max(total, planting + p[i].first);
            //total is the day when a flower blooms.
        }
        
        return total;
    }
};