class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,int> freq;
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
        }

        int cond = n/3;
        for(auto it:freq)
        {
            if(it.second > n/3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};