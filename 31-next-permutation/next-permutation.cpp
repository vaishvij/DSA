class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int pt=-1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                pt = i;
                break;
            }
        }
        if(pt == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1; i>pt; i--)
        {
            if(nums[i] > nums[pt])
            {
                swap(nums[i], nums[pt]);
                break;
            }
        }
        reverse(nums.begin()+pt+1, nums.end());
    }
};