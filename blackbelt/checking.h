#ifndef CHECKING_H_EXISTS
#define CHECKING_H_EXISTS

class Checking{
	protected:
		double balance;
		double amount;
	public:
		Checking();
		
		void setBalance(double balance);
		void deposit();
		void withdraw();
		double getBalance();
};
#endif
