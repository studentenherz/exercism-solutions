#include "queen_attack.h"

#include <stdexcept>

namespace queen_attack {

chess_board::chess_board(ii white, ii black): w{white}, b{black} {
	if (w.first < 0 || w.first > 7 || w.second < 0 || w.second > 7 || b.first < 0 || b.first > 7 || b.second < 0 || b.second > 7)
		throw std::domain_error("The chess board is in the range (0, 0) to (7, 7).");
	
	if (w == b) throw std::domain_error("Queen positions must be distinct");
}

ii chess_board::white() const {return w;}
ii chess_board::black() const {return b;}

bool chess_board::can_attack() const {
	return (w.first == b.first || w.second == b.second || w.first - w.second == b.first - b.second || w.first + w.second == b.first + b.second);
}

}  // namespace queen_attack
