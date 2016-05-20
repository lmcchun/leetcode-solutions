class Solution {
	public:
		string reverseVowels(string s) {
			vector<char> vowels;
			for (string::iterator iterator = s.begin(), end = s.end(); iterator != end; ++iterator) {
				switch (*iterator) {
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':
					case 'A':
					case 'E':
					case 'I':
					case 'O':
					case 'U':
						vowels.push_back(*iterator);
						break;
					default:
						break;
				}
			}

			string result(s);
			vector<char>::iterator vowel_iterator = vowels.begin();
			for (string::reverse_iterator reverse_iterator = result.rbegin(), rend = result.rend(); reverse_iterator != rend; ++reverse_iterator) {
				switch (*reverse_iterator) {
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':
					case 'A':
					case 'E':
					case 'I':
					case 'O':
					case 'U':
						*reverse_iterator = *vowel_iterator;
						++vowel_iterator;
						break;
					default:
						break;
				}
			}
			return result;
		}
};
