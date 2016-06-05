class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			vector<int>::iterator iter1 = nums.begin();
			vector<int>::iterator end = nums.end();
			if (iter1 == end) {
				return 0;
			}
			for (vector<int>::iterator iter = iter1 + 1; iter != end; ++iter) {
				if (*iter != *iter1) {
					++iter1;
					if (iter1 != iter) {
						*iter1 = *iter;
					}
				}
			}
			++iter1;
			return iter1 - nums.begin();
		}
};
