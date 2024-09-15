#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using std::string;
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	Account::_amount = initial_deposit;
	Account::_accountIndex = getNbAccounts();
	std::cout << "index:" << getNbAccounts() << ";amount:" << initial_deposit << ";created\n";
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed\n";
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	char	buffer[20];

	std::time_t currentTime = std::time(0);
	std::tm *localTime = std::localtime(&currentTime);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	// std::cout << "[19920104_091532] ";
	std::cout << buffer << " ";
}
