#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <vector>
#include <string>

namespace anagram {

class anagram {
    const std::string _word;
    std::vector<int> _count;
public:
    anagram(const std::string& s);
    std::vector<std::string> matches(const std::vector<std::string>& words) const;
private:
    bool is_anagram(const std::string& word) const;
    static std::string to_lower(const std::string& s);
};

}  // namespace anagram

#endif // ANAGRAM_H