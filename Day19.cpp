//  O(n^2)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>frequency;

        for(auto word: words){
            frequency[word]++;
        }

        vector<string>ans;
        while(k--){
            int mx = 0;
            string str;
            for(auto [key, val]: frequency){
                if(val > mx){
                    mx = val;
                    str = key;
                }else if(val == mx){
                    if(str > key)
                        str = key;
                }
            }
            ans.push_back(str);
            frequency[str] = -1;
            cout<<str<<' '<<frequency[str];
        }

        return ans;
    }
};


-----------------------------------------------------------------------------------

//  O(nlogk)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>frequency;

        for(auto word: words){
            frequency[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp>pq;

        for(auto [key, val]: frequency){
            pq.push(make_pair(val, key));
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<string>res;
        while(!pq.empty()){
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }

private:
    struct MyComp{
        bool operator() (const pair<int, string>&a, const pair<int, string> &b){
            if(a.first != b.first){
                return a.first > b.first;
            }else{
                return a.second < b.second;
            }
        }
    };


};