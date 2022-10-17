/*
Sol:01
*/
class Solution {
    public boolean checkIfPangram(String s) {
        Set<Character> set = new HashSet<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)-'a' >=0 && s.charAt(i)-'a'<26){
                set.add(s.charAt(i));
            }else{
                return false;
            }
        }
        return (set.size()==26)?true:false;
    }
}
//Runtime : 3ms 


