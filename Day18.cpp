//-----------------------Recursion--------------------------------

class Solution {
public:
    string countAndSay(int n) {
        //base case
        if(n == 1) return "1";
        //get the previous, which will help us in finding current.
        string prev = countAndSay(n-1);
        //current answer
        string ans;
        //conversion process starts.
        int len = prev.length();
        //traverse the string
        for(int i=0; i<len;){
            //count frequency 
            int j=i, cnt = 0;
            while(j< len){
                if(prev[i] == prev[j]){
                    cnt++;
                    j++;
                }else{
                    break;
                }
            }
            //add it in answer
            ans.push_back(cnt + '0');
            ans.push_back(prev[i]);
            i = j;
        }
        return ans;
    }
};


//--------------------------Tabulation--------------------------------

class Solution {
public:
    string countAndSay(int n) {
        vector<string>arr(n);
        arr[0] = "1";

        for(int i=1; i<n; i++){
            string prev = arr[i-1], curr;
            int st = 0, cnt = 1;
            for(int j = 1; j<prev.length(); j++){
                if(prev[j] == prev[st]) cnt++;
                else{
                    curr.push_back(cnt+ '0');
                    curr.push_back(prev[st]);
                    cnt = 1; st = j;
                }
            }
            curr.push_back(cnt+ '0');
            curr.push_back(prev[st]);

            arr[i] = curr;
        }

        return arr[n-1];
    }
};


//------------------------Space Optimized------------------------------


class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";

        for(int i=2; i<=n; i++){
            string curr;
            int st = 0, cnt = 1;
            for(int j = 1; j<prev.length(); j++){
                if(prev[j] == prev[st]) cnt++;
                else{
                    curr.push_back(cnt+ '0');
                    curr.push_back(prev[st]);
                    cnt = 1; st = j;
                }
            }
            curr.push_back(cnt+ '0');
            curr.push_back(prev[st]);

            prev = curr;
        }

        return prev;
    }
};