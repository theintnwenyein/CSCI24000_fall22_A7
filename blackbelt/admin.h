#ifndef ADMIN_H_EXISTS
#define ADMIN_H_EXISTS
#include <string>
class Admin{
	private:
		std::string adminAcc;
		std::string adminPin;
		std::string userAcc;
		std::string userPin;
		std::string line;
		std::string deletedAcc;
		int answer;

	public:
		double initialChecking;
		double initialSaving;
		Admin();
		std::string getAdminAcc();
		std::string getAdminPin();
		int printMenu();
		void addUser();
		std::string getNewUser();
		std::string deleteUser();

};
#endif
