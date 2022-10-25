class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first, second;
        
        for(auto word: word1){
            first += word;
        }
        
        for(auto word: word2){
            second += word;
        }
        
        
        return first == second;
    }
};


--------------------------------------------------------------------------------


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        //find length of arrays
        int arr1_len = word1.size(), arr2_len = word2.size();

        //these pointer will run on individual strings.
        int st1 = 0, st2 = 0;

        //these pointer will run characters of current string
        int i = 0, j = 0;

        //if we've more strings to check in BOTH arrays.
        while(st1 < arr1_len and st2 < arr2_len){

            //find lenght of curr strings
            int curr_len1 = word1[st1].length(), curr_len2 = word2[st2].length();

            //traverse and compare current strings
            while(i < curr_len1 and j < curr_len2){

                //if corresponding chars mismatch, return false.
                if(word1[st1][i] != word2[st2][j]) return false;
                i++; j++;
            }

            //if first string was smaller, restart its char pointer and increase string pointer.
            if(i == curr_len1){
                i = 0;
                st1++;
            }

            if(j == curr_len2){   //do the same with 2nd string
                j = 0;
                st2++;
            }
        }

        //coming here, if both arrays are of same length, it must be equal as we've compared everything.
        //if they're not equal, obviously they'll not be equivalent.
        return (st1 == arr1_len and st2 == arr2_len);
    }
};