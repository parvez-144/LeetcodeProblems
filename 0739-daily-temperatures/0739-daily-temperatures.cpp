class Solution {
public:
    vector<int>nextGreater(vector<int>&temp){
        stack<int>st;
        int n=temp.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(!st.empty()&&temp[st.top()]>temp[i]){
                ans[i]=st.top();
                st.push(i);
            }else{
                while(!st.empty()&&temp[st.top()]<=temp[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=i;
                }
                else{
                    ans[i]=st.top();
                }
                st.push(i);
            }
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int>ans;
        vector<int>next=nextGreater(temp);
        for(int i=0;i<n;i++){
            ans.push_back(next[i]-i);
        }
        return ans;
    }
};