class Solution {
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			unordered_map<int, int> map;
			for (vector<int>::const_iterator iter = nums2.cbegin(), end = nums2.cend(); iter != end; ++iter) {
				++map[*iter];
			}

			vector<int> result;
			for (vector<int>::const_iterator iter = nums1.cbegin(), end = nums1.cend(); iter != end; ++iter) {
				unordered_map<int, int>::iterator got = map.find(*iter);
				if ((got != map.end()) && (got->second > 0)) {
					result.push_back(*iter);
					--(got->second);
				}
			}
			return result;
		}
};
