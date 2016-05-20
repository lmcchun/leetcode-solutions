class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result;
			unordered_map<int, int> map;
			for (vector<int>::size_type i = 0, size = nums.size(); i < size; ++i) {
				unordered_map<int, int>::iterator iterator = map.find(nums[i]);
				if (iterator != map.end()) {
					result.push_back(iterator->second);
					result.push_back(i);
					break;
				}
				map[target - nums[i]] = i;
			}
			return result;
		}
};
