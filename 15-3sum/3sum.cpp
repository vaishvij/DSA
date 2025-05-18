class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set <vector<int>> s;

        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low = i+1;
            int high = n-1;
            while(low < high)
            {
                if(nums[i]+nums[low]+nums[high] == 0)
                {
                    vector<int> temp = {nums[i],nums[low],nums[high]};
                    s.insert(temp);
                    low++;
                    high--;
                }
                else if(nums[i]+nums[low]+nums[high] < 0)  low++;
                else  high--;
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};