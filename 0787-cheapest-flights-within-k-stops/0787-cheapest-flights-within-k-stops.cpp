class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            int steps=ele.first;
            int node=ele.second.first;
            int weight=ele.second.second;
            if(steps>k)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(weight+edw<dist[adjnode]&&steps<=k){
                    dist[adjnode]=weight+edw;
                    q.push({steps+1,{adjnode,weight+edw}});
                }
            }
        }
        if(dist[dst]!=1e9)return dist[dst];
         return -1;
    }
};