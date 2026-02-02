class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        for(int bitInd=0; bitInd<32; bitInd++)
        {
            int count=0;
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] & (1<<bitInd))
                count++;
            }
            if(count%3 != 0)
            {
                ans = ans | (1<<bitInd);
            }
        }
        return ans;
    }
};