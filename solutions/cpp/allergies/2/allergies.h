#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <unordered_set>
#include <string>

namespace allergies {

class allergy_test{
	static const std::string _allergens[];
	
	std::unordered_set<std::string> _allergies;
public:
	allergy_test(unsigned int score);

	bool is_allergic_to(const std::string& item) const;
	std::unordered_set<std::string> get_allergies() const;
};

}  // namespace allergies

#endif // ALLERGIES_H