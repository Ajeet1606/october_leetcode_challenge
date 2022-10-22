class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(m < n) return "";
        
        unordered_map<char, int>map;
        for(auto a: t){
            map[a]++;
        }
        //unique characters required to make this window desirable.
        int required = map.size();
        int l = 0, r = 0;
        
        int formed = 0;
        unordered_map<char, int>cur_window;
        
        int arr[2] = {-1, 0};
        while(r < m){
            char cur = s[r];
            cur_window[cur]++;
            
            if(map[cur] == cur_window[cur]) formed++;
            
            while(l <= r and formed == required){
                cur = s[l];
                if(arr[0] == -1 or r-l+1 < arr[0]){
                    arr[0] = r-l+1;
                    arr[1] = l;
                }
                
                cur_window[cur]--;
                if(map[cur] > 0 and cur_window[cur] < map[cur]){
                    formed--;
                }
                l++;
            }
            r++;
        }
        
        return arr[0] == -1? "": s.substr(arr[1], arr[0]);
    }
};



