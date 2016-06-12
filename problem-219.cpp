class Solution {
	public:
		bool containsNearbyDuplicate(vector<int>& nums, int k) {
			unordered_map<int, vector<int>::size_type> map;
			for (vector<int>::size_type i = 0, size = nums.size(); i < size; ++i) {
				unordered_map<int, vector<int>::size_type>::iterator found = map.find(nums[i]);
				if ((found != map.end()) && ((i - (*found).second) <= k)) {
					return true;
				}
				map[nums[i]] = i;
			}
			return false;
		}
};
