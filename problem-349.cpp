class Solution {
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
			unordered_map<int, int> map;
			vector<int> result;

			vector<int>::size_type nums1Size = nums1.size();
			for (vector<int>::size_type i = 0; i < nums1Size; i++) {
				map[nums1[i]]++;
			}

			vector<int>::size_type nums2Size = nums2.size();
			for (vector<int>::size_type i = 0; i < nums2Size; i++) {
				if (map[nums2[i]] > 0) {
					result.push_back(nums2[i]);
					map[nums2[i]] = 0;
				}
			}

			return result;
		}
};
