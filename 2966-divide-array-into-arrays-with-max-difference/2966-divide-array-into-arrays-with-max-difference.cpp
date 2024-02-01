class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
         int n=nums.size();
        if(n%3)return {};
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(temp.size()==0||nums[i]-temp[0]<=k){
               temp.push_back(nums[i]);
           }
           if(temp.size()==3){
               ans.push_back(temp);
               temp.clear();
           }
           if(nums[i]-temp[0]>k)return {};
        }
        return ans;
    }
};