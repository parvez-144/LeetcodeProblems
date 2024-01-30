class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,long>mp;
        int n=nums.size(),ans=1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
            if(mp[1]%2){
                ans=mp[1];
            }
            else{
                ans=mp[1]-1;
            }
        for(int i=0;i<n;i++){
            long long k=1,cnt=0;
            while(k<30&&nums[i]!=1){
                long long num=pow((long long)nums[i],k);
                if(num>1e9){
                    break;
                }
                if(mp[num]>=2){
                    k=k*2;
                    cnt++;
                }else{
                    break;
                }
            }
            if(mp[pow(nums[i],k)]>=1){
                if(cnt*2+1>ans){
                    ans=cnt*2+1;
                }
            }
            k/=2;
            if(mp[pow(nums[i],k)]>=1){
                 if((cnt-1)*2+1>ans){
                    ans=(cnt-1)*2+1;
                }
            }
           
        }
        return ans;
    }
};