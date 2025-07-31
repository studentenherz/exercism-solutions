#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {

void Bankaccount::open(){
	if (_is_opened)
		throw std::runtime_error("Can't open an already opened account");
	_is_opened = true;
}

void Bankaccount::close(){
	if (!_is_opened)
		throw std::runtime_error("Can't close unopened account");
	_balance = 0;
	_is_opened = false;
}

int Bankaccount::balance() const {
	if (!_is_opened)
		throw std::runtime_error("Can't check balance of unopened/closed account");
	return _balance;
}

void Bankaccount::deposit(int amount) {
	if (!_is_opened)
		throw std::runtime_error("Can't deposit on unopened/closed account");
	if (amount < 0)
		throw std::runtime_error("Can't deposit negative amount");
	_balance += amount;
}

void Bankaccount::withdraw(int amount) {
	if (!_is_opened)
		throw std::runtime_error("Can't withdraw from unopened/closed account");
	if (amount > _balance)
		throw std::runtime_error("Can't withdraw more than deposited");
	if (amount < 0)
		throw std::runtime_error("Can't withdraw negative amount");
	_balance -= amount;
}

}