class Solution {
	public:
		vector<int> countBits(int num) {
			vector<int> result = {0};
			int counter;
			while ((counter = result.size()) <= num) {
				for (int i = 0; (i < counter) && ((i + counter) <= num); ++i) {
					result.push_back(result[i] + 1);
				}
			}
			return result;
		}
};
