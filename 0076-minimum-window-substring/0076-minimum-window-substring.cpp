class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length(),mini=1e9;
        string ans="";
        unordered_map<char,int>mp1,mp2;
        for(auto it:t){
            mp1[it]++;
        }
        int i=0,j=0;
        while(j<n){
            mp2[s[j]]++;
              bool flag=0;
              for(auto it:mp1){
                  if(mp1[it.first]>mp2[it.first]){
                      flag=1;
                      break;
                  }
              }
              if(!flag){
                  while(mp2[s[i]]>mp1[s[i]]){
                      mp2[s[i]]--;
                      i++;
                  }
                  if(mini>j-i+1){
                      mini=min(mini,j-i+1);
                      ans=s.substr(i,j-i+1);
                  }
              }
              j++;

        }
        return ans;
    }
};