#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount {

auto Bankaccount::open() -> void {
	const std::lock_guard lock(_mutex);
	if (_is_opened)
		throw std::runtime_error("Can't open an already opened account");
	_is_opened = true;
}

auto Bankaccount::close() -> void {
	const std::lock_guard lock(_mutex);
	if (!_is_opened)
		throw std::runtime_error("Can't close unopened account");
	_balance = 0;
	_is_opened = false;
}

auto Bankaccount::balance() const -> int {
	const std::lock_guard lock(_mutex);
	if (!_is_opened)
		throw std::runtime_error("Can't check balance of unopened/closed account");
	return _balance;
}

auto Bankaccount::deposit(int amount) -> void {
	if (amount < 0)
		throw std::runtime_error("Can't deposit negative amount");

	const std::lock_guard lock(_mutex);
	if (!_is_opened)
		throw std::runtime_error("Can't deposit on unopened/closed account");
	_balance += amount;
}

auto Bankaccount::withdraw(int amount) -> void {
	if (amount > _balance)
		throw std::runtime_error("Can't withdraw more than deposited");
	if (amount < 0)
		throw std::runtime_error("Can't withdraw negative amount");

	const std::lock_guard lock(_mutex);
	if (!_is_opened)
		throw std::runtime_error("Can't withdraw from unopened/closed account");
	_balance -= amount;
}

}