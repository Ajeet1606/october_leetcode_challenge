//Before middle point of string, we try to make non 'a' chars to 'a', if not possible, make the last one to 'b'.



class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n == 1) return "";
        int l = 0, r = n-1;
        bool done = false;
        while(l < r and !done){
            if(palindrome[l] != 'a'){
                palindrome[l] = 'a';
                done = true;
            }
            l++;
            r--;
        }
        if(!done){
            palindrome[n-1] = 'b';
        }

        return palindrome;
    }
};



<<<<<<<<<<<<<<<<<-----------Better way----------------->>>>>>>>>>>>>>>>>>>>>>>>

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();

        int i=0;
        while(i < n/2){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
            i++;
        }

        palindrome[n-1] = 'b';
        return n<2? "": palindrome;
    }
};
