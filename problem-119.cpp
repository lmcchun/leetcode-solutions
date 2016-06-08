class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			if (rowIndex == 0) {
				return {1};
			} else {
				vector<int> result = {1, 1};
				for (int i = 1; i < rowIndex; ++i) {
					result.push_back(1);
					for (int j = i; j > 0; --j) {
						result[j] += result[j - 1];
					}
				}
				return result;
			}
		}
};
