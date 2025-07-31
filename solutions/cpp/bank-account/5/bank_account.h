#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <mutex>

namespace Bankaccount {
class Bankaccount {
	int _balance = 0;
	bool _is_opened = false;

	mutable std::mutex _mutex;
public:
	auto open() -> void;
	auto close() -> void;
	auto balance() const -> int;
	auto deposit(int amount) -> void;
	auto withdraw(int amount) -> void;
};  // class Bankaccount

}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H