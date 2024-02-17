class Solution {
public:

    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
       priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<h.size();i++){
            if(h[i]<=h[i-1]){
                continue;
            }else{
                pq.push(h[i]-h[i-1]);
                if(pq.size()>ladders&&bricks>=pq.top()){
                    bricks-=pq.top();
                    pq.pop();
                }
                else if(pq.size()>ladders&&bricks<pq.top()){
                    return i-1;
                }

            }
            
        }
        return h.size()-1;
    }
};