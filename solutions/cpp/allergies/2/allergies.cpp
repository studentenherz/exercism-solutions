#include "allergies.h"

namespace allergies {

const std::string allergy_test::_allergens[] = {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};

allergy_test::allergy_test(unsigned int score) {
	for (unsigned int i = 0; i < 8U; i++){
		if (score & (1 << i)){
			_allergies.insert(_allergens[i]);
		}
	}
}

bool allergy_test::is_allergic_to(const std::string& item) const {
	return _allergies.find(item) != _allergies.end();
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
	return _allergies;
}


}  // namespace allergies
