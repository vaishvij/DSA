class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int cur = 0;
        int maxim = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                cur++;
                maxim = max(cur,maxim);
            }
            else
            {
                cur=0;
            }
        }
        return maxim;
    }
};