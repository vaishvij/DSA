class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int number=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != number)
            {
                return number;
                break;
            }
            number++;
        }
        return number;
    }
};