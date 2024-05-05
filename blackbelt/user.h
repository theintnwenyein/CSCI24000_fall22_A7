#ifndef USER_H_EXISTS
#define USER_H_EXISTS
#include <string>

class User{
	private:
		std::string pin;
		std::string account_no;
		bool correct;
		int answer;

	public:
		User();
		void setPin(std::string pin);
		void setAccountno(std::string account_no);
		std::string getPin();
		std::string getAccountno();
		bool pinCheck(std::string account_no, std::string pin);
		int printMenu();

};
#endif
