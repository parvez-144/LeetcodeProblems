class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        while(k){
            int freq=pq.top().first;
            pq.pop();
            if(k>=freq){
                k-=freq;
            }else{
                k=0;
                return pq.size()+1;
            }
        }
        return pq.size();
    }
};
