#include "two_fer.h"

namespace two_fer
{

std::string two_fer(const std::string& name){
	return "One for " + (name.size() ? name : "you" ) + ", one for me.";
}

} // namespace two_fer

