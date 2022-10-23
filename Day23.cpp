--------------------------------------Approach 1---------------------------------------

class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        int dup = -1, missing = -1;
        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(arr[j] == i){
                    cnt++;
                }
            }
            if(cnt == 2){
                dup = i;
            }
            else if(cnt == 0){
                missing = i;
            }
            
            if(dup != -1 and missing != -1) break;
        }
        
        return {dup, missing};
    }
};


---------------------------------------Approach 2---------------------------------------

class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int dup = -1, missing = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                dup = arr[i];
            }
            else if(arr[i] > arr[i-1]+1){
                missing = arr[i-1]+1;
            }
        }
        
        if(arr[n-1] != n)
            missing = n;
        return {dup, missing};
    }
};



---------------------------------------Approach 3--------------------------------------

class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int>m;
        for(int i=1; i<=n; i++){
            m[i] = 0;
        }
        for(auto a: arr){
            m[a]++;
        }
        
        int dup = -1, missing = 1;
        
        for(auto [key, val]: m){
            if(val == 2){
                dup = key;
            }
            if(val == 0){
                missing = key;
            }
        }
        
        return {dup, missing};
    }
};



-------------------------------------Approach 4------------------------------------------

class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        int dup = -1, missing = 1;
        
        for(auto a: arr){
            if(arr[abs(a) - 1] < 0)
                dup = abs(a);
            else
                arr[abs(a) - 1] *= -1;
        }
        
        for(int i=1; i<n; i++){
            if(arr[i] > 0){
                missing = i+1;
            }
        }
        
        return {dup, missing};
    }
};



---------------------------------------Approach 5---------------------------------------

class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        
        int actual_sum = n*(n+1)/2;
        int curr_sum = accumulate(arr.begin(), arr.end(), 0);
        int duplicate;
        unordered_set<int>s;
        for(auto a: arr){
            if(s.count(a) != 0){
                duplicate = a;
                break;
            }
            else
                s.insert(a);
        }
        
        return {duplicate, actual_sum - curr_sum + duplicate};
    }
};