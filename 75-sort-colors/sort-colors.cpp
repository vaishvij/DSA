class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int c0=0,c1=0,c2=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0) c0++;
            if(nums[i]==1) c1++;
            if(nums[i]==2) c2++;
        }
        int n=nums.size();
        nums.clear();
        while(c0)
        {
            nums.push_back(0);
            c0--;
        }
        while(c1)
        {
            nums.push_back(1);
            c1--;
        }
        while(c2)
        {
            nums.push_back(2);
            c2--;
        }
    }
};