class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            if(i && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int low = j + 1, high = n-1;
                while(low < high){
                    int got = nums[i] + nums[j] + nums[low] + nums[high];
                    if(got == target)
                    {
                        ret.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low < high && nums[low] == nums[low+1])
                            low++;
                        while(low < high && nums[high] == nums[high-1])
                            high--;
                        low++;
                        high--;
                    }
                    else if(got > target)
                        high--;
                    else
                        low++;
                }
            }
        }
        return ret;
    }
};