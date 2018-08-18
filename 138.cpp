class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        vector<int> res;
        if(len == 0) return res;
        for(int i = 0; i < len; i++) {
            sum = nums[i];
            if(sum == 0) {
                res.push_back(i);
                res.push_back(i);
                return res;
            }
            for(int j = i + 1; j < len; j++) {
                sum += nums[j];
                if(sum == 0) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};