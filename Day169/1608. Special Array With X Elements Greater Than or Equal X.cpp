class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        auto find_number_of_nums = [&](int cur_num) -> int {
            int left = 0, right = n - 1;
            int first_index = n;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (nums[mid] >= cur_num) {
                    first_index = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return n - first_index;
        };

        for (int candidate_number = 1; candidate_number <= n; ++candidate_number) {
            if (candidate_number == find_number_of_nums(candidate_number)) {
                return candidate_number;
            }
        }

        return -1;
    }
};