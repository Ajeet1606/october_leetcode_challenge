class Solution {
public:
    string intToRoman(int num) {
        string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans;
        int i = 0;
        while(num!=0){
            while(num >= val[i]){
                num -= val[i];
                ans += rom[i];
            }
            i++;
        }
        return ans;
    }
};