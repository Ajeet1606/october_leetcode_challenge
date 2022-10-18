// Runtime : 4ms
class Solution {
    public String countAndSay(int n) {
	    String res ="1";
	    if(n==1){
	        return res;
	    }else{
	        for(int i=2;i<=n;i++){
	            String str =countsay(res);
	            res = str;
	        }
            return res;
	    }
    }
    public String countsay(String code){
        StringBuilder sb =new StringBuilder();
        int count=1;
        for(int i=1;i<code.length();i++){
            if(code.charAt(i)==code.charAt(i-1)){
                count++;
            }else{
                sb.append(count);
                sb.append(code.charAt(i-1));
                count=1;
            }
        }
        sb.append(count);
        sb.append(code.charAt(code.length()-1));
        return sb.toString();
    }
}
