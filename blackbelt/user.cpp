#include "user.h"
#include <iostream>
#include <string>

User::User(){
	User::pin = "";
	User::account_no = "";
}

void User::setPin(std::string pin){
	User::pin = pin;
}

void User::setAccountno(std::string account_no){
	User::account_no = account_no;
}

std::string User::getPin(){
	return User::pin;
}

std::string User::getAccountno(){
	return User::account_no;
}

bool User::pinCheck(std::string account_no, std::string pin){
	User::correct = false;
	if(User::account_no == account_no and User::pin == pin){
		User::correct = true;
	}
	return User::correct;
}

int User::printMenu(){
	std::cout<<"\n"<<"Success! Please choose one of the options from the menu."<<std::endl;
	std::cout<<"1) Get Checking Balance"<<std::endl;
	std::cout<<"2) Deposit into Checking"<<std::endl;
	std::cout<<"3) Withdraw from Checking"<<std::endl;
	std::cout<<"4) Get Saving Balance"<<std::endl;
	std::cout<<"5) Deposit into Saving"<<std::endl;
	std::cout<<"6) Withdraw from Saving"<<std::endl;
	std::cout<<"7) Exit"<<std::endl;
	std::cout<<"Please enter your choice: ";
	std::cin>>User::answer;
	return User::answer;
}

