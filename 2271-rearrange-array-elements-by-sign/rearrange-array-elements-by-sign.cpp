class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> pos,neg;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= 0)
            pos.push_back(nums[i]);
            else
            neg.push_back(nums[i]);
        }
        int n = nums.size();
        nums.clear();
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            nums.push_back(pos[i/2]);
            else
            nums.push_back(neg[i/2]);
        }
        return nums;
    }
};