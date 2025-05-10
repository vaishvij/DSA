class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int cur_max=0;
        int last_max=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                cur_max++;
            }
            if(nums[i] == 0)
            {
                if(last_max <= cur_max)
                {
                    last_max = cur_max;
                }
                cur_max=0;
            }
            if(i==(nums.size()-1) && nums[i]==1)
            {
                if(cur_max >= last_max)
                {
                    last_max = cur_max;
                }
            }
        }
        return last_max;
    }
};