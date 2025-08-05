class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size();
        int unplaced = 0;
        bool flag = false;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(baskets[j] >= fruits[i])
                {
                    baskets[j] = 0;
                    flag = true;
                    break;
                }
            }
            if(flag == false) unplaced++;
            else flag=false;
        }
        return unplaced;
    }
};