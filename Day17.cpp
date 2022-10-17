
Approach 1: Vector int
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = {0};

        for(auto c: sentence){
            arr[c - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(arr[i] == 0)
            return false;
        }

        return true;
    }
};


Approach 2: Vector bool

class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26] = {false};

        for(auto c: sentence){
            arr[c - 'a'] = true;
        }

        for(int i=0; i<26; i++){
            if(arr[i] == false)
            return false;
        }

        return true;
    }
};


Approach 3: Unordered set

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>set;
        for(auto s: sentence)
            set.insert(s);

        return set.size() == 26;
    }
};

Approach 3: One liner

class Solution {
public:
    bool checkIfPangram(string s) {
        return unordered_set<char>(s.begin(), s.end()).size() == 26;
    }
};

Approach 4: Bit Manipulationn

class Solution {
public: //Bit manipulation
    bool checkIfPangram(string sentence) {
        //start from 0
        int num = 0;

        for(auto c: sentence){
            //get position of current character
            int a = c - 'a';
            //left shift 1 by a times and do bitwise or with num.  
            // num = 0, we got b
            // 1<<1 = 10
            // num = num | 1<<1 = (0 | 10) = 10
            num = num | (1<<a);
        }
        // 1<<26 = 100000000000000000000000000
        // 1<<26 - 1 = 11111111111111111111111111
        // which represents that every char is present there.
        return num == ((1<<26) -1);
    }
};