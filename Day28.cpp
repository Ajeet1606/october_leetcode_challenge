---------------------------------Approach 1----------------------------------------


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        unordered_map<string, vector<string>>m;
        for(int i=0; i<n; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
       
        
        vector<vector<string>>ans;
        for(auto [key, value]: m){
            ans.push_back(value);
        }
        
        return ans;
    }
};


---------------------------Approach 2--------------------------------------------

class Solution {
        //counting sort: O(n)
private:
    
    string mySort(string str){
        int arr[26] = {0};
        for(auto s: str){
            arr[s - 'a']++;
        }
        
        string ans;
        for(int i=0; i<26; i++){
            ans += string(arr[i], i + 'a');
        }
        
        return ans;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        
        unordered_map<string, vector<string>>m;
        for(int i=0; i<n; i++){
            m[mySort(strs[i])].push_back(strs[i]);
        }
       
        
        vector<vector<string>>ans;
        for(auto [key, value]: m){
            ans.push_back(value);
        }
        
        return ans;
    }
};