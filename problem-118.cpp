class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			if (numRows == 0) {
				return {};
			} else if (numRows == 1) {
				return {{1}};
			} else {
				vector<vector<int>> result(numRows, vector<int>());
				result[0].push_back(1);
				result[1].push_back(1);
				result[1].push_back(1);
				for (int i = 2; i < numRows; ++i) {
					result[i].push_back(1);

					for (int j = 1; j < i; ++j) {
						int iMinorOne = i - 1;
						result[i].push_back(result[iMinorOne][j - 1] + result[iMinorOne][j]);
					}

					result[i].push_back(1);
				}
				return result;
			}
		}
};
