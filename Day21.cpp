-----------------------Approach 1--------------------------------------

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_map<int, int>m;
        for(int i=0; i<arr.size(); i++){
            if(m.find(arr[i]) != m.end()){
                if(abs(m[arr[i]] - i) <= k) return true;
            }
            m[arr[i]] = i;
        }

        return false;
    }
};


--------------------------Approach 2--------------------------------------


class Solution {
public: //we maintain a set of size k.
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_set<int>s;
        if(k >= arr.size()) k = arr.size()-1;

        for(int i=0; i<arr.size(); i++){
            if(i > k) s.erase(arr[i - k -1]);
            if(s.count(arr[i]) != 0) return true;
            s.insert(arr[i]);
        }

        return false;
    }
};