# include "Account.hpp"
# include <iomanip>
# include <iostream>
# include <ctime>

int	Account::_nbAccounts = -1;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return ;
}

Account::Account( void )
{
	return ;
}
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts + 1 << ";total:" << _totalAmount << ";deposits:"
				<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	return ;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
		std::cout << "refused" << std::endl;
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amout:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
			<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	std::time_t time;
	std::tm		*localTime;
	int			year;
	int			month;
	int			day;
	int			hour;
	int			minute;
	int			second;

	time = std::time(0);
	localTime = std::localtime(&time);
	year = localTime->tm_year + 1900;
	month = localTime->tm_mon + 1;
	day = localTime->tm_mday;
	hour = localTime->tm_hour;
	minute = localTime->tm_min;
	second = localTime->tm_sec;
	std::cout << "[" << year << std::setfill('0') << std::setw(2) << month
				<< std::setfill('0') << std::setw(2) << day << "_"
				<< std::setfill('0') << std::setw(2) << hour
				<< std::setfill('0') << std::setw(2) << minute
				<< std::setfill('0') << std::setw(2)<< second << "]";
	return ;
}
