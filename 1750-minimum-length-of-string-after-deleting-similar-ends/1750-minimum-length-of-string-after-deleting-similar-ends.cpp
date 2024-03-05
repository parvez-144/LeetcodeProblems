class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]&&i<j){
                 while(s[i]==s[i+1]){
                i++;
            }
            while(s[j]==s[j-1]&&i<j){
                j--;
            }
                i++;
                j--;
            }
            else{
                return j-i+1;
            }
        }
        return i==j?1:0;
    }
};