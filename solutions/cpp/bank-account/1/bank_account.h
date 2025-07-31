#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <atomic>


namespace Bankaccount {
class Bankaccount {
	std::atomic<int> _balance = 0;
	bool _is_opened = false;
public:
	void open();
	void close();
	int balance() const;
	void deposit(int amount);
	void withdraw(int amount);
};  // class Bankaccount

}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H