class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) 
    {
        map <int,int> hashmap;
        for(int i=0; i<nums.size(); i++)
        {
            int other = target - nums[i];
            if(hashmap.find(other) != hashmap.end())
            {
                return {hashmap[other],i};
            }
            hashmap[nums[i]]=i;
        }
        return {-1,-1};
    }
};