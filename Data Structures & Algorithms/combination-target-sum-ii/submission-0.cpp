class Solution {
public:

    vector<vector<int>> res;
    vector<int> subset;
    void dfs(vector<int>& nums, int index, int target)
    {

        if(target<0)
        return;

        if(target == 0)
        {
            res.push_back(subset);
            return;
        }

        for(int i = index; i<nums.size(); i++)
        {
            if(i>index && nums[i]==nums[i-1])
            continue;

            subset.push_back(nums[i]);

            dfs(nums, i+1, target-nums[i]);

            subset.pop_back();

        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};
