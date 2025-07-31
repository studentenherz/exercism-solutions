#include "anagram.h"

#include <algorithm>

namespace anagram {

anagram::anagram(const std::string& s): _word{to_lower(s)}, _count(27, 0) {
		for (char c : _word){
				if (std::isalpha(c)){
				_count[c - 'a']++;
				}
		}
}

std::vector<std::string> anagram::matches(const std::vector<std::string>& words) const {
		std::vector<std::string> ans;
		for (const auto& word: words){
				if (is_anagram(word)){
						ans.push_back(word);
				}
		}
		return ans;
}

bool anagram::is_anagram(const std::string& w) const {
		std::string word = to_lower(w);
		if (word == _word) return false;
		size_t n = 0;
		auto count{_count};
		for (char c: word){
				if (std::isalpha(c) && --count[c - 'a'] < 0) return false;
				n++;
		}
		return n == _word.size();
}

std::string anagram::to_lower(const std::string& s) {
		std::string ans;
		std::for_each(s.begin(), s.end(), [&ans](char c){ ans += std::tolower(c); });
		return ans;
}


}  // namespace anagram
