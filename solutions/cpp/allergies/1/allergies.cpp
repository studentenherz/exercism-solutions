#include "allergies.h"

#include <stdexcept>

namespace allergies {

const std::map<std::string, unsigned int> allergy_test::_values{{"eggs", 1}, {"peanuts", 2}, {"shellfish", 4}, {"strawberries", 8}, {"tomatoes", 16}, {"chocolate", 32}, {"pollen", 64}, {"cats", 128}};

allergy_test::allergy_test(unsigned int score) {
	for (const auto& [key, value] : _values){
		if (score & value){
			_allergies.insert(key);
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
