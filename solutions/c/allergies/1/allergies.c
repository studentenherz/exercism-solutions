#include "allergies.h"

bool is_allergic_to(allergen_t allergen, short allergies){
	return (1 << allergen) & allergies;
}

allergen_list_t get_allergens(short allergies){
	allergen_list_t list;
	list.count = 0;

	for (int i = 0; i < ALLERGEN_COUNT; i++){
		if (is_allergic_to(i, allergies)){
			list.count++;
			list.allergens[i] = true;
		}
		else{
			list.allergens[i] = false;
		}
	}

	return list;
}