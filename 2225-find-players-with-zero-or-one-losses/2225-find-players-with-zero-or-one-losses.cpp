class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,vector<int>>adj;
        map<int,int>mp;
        for(auto it:matches){
            adj[it[1]].push_back(it[0]);
            mp[it[0]]++;
        }
        vector<vector<int>>ans(2);
        for(auto it:adj){
            if(it.second.size()==1){
                ans[1].push_back(it.first);
                mp[it.first]=0;
            }
        }
        for(auto it:mp){
            if(it.second&&adj[it.first].size()==0){
                ans[0].push_back(it.first);
            }
        }
        return ans;
    }
};