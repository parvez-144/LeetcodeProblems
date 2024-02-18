class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        set<int>st;       
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            st.insert(i);
        }
            sort(begin(meetings),end(meetings));
            for(int i=0;i<meetings.size();i++){
                long long start=meetings[i][0],end=meetings[i][1];
                while(pq.size()>0&&pq.top().first<=start){
                    st.insert(pq.top().second);
                    pq.pop();
                }
                if(st.size()==0){
                    pair<long long,long long>p=pq.top();
                    pq.pop();
                    long long diff=end-start;
                    start=p.first;
                    end=start+diff;
                    st.insert(p.second);
                }
                auto it=st.begin();
                ans[*it]++;
                pq.push({end,*it});
                st.erase(*it);
            }
        long long maxi=0,toret=0;
        for(int i=0;i<n;i++){
            if(maxi<ans[i]){
                maxi=ans[i];
                toret=i;
            }
        }
        return toret;
        
    }
};