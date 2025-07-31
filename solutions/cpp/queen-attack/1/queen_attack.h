#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>

namespace queen_attack {

using ii = std::pair<int, int>;

class chess_board{
	ii w;
	ii b;
public:
	chess_board(ii, ii);

	ii white(void) const;
	ii black(void) const;

	bool can_attack(void) const;
};

}  // namespace queen_attack

#endif // QUEEN_ATTACK_H