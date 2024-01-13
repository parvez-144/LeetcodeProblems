class Solution {
public:
    int minSteps(string s, string t) {
        map<int,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:t){
            mp[i]=max(0,--mp[i]);
        }
        int ans=0;
        for(auto i:mp){
            ans+=i.second;
        }
        return ans;
    }
};