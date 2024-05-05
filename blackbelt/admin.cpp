#include "admin.h"
#include <iostream>
#include <string>

Admin::Admin(){
	Admin::adminAcc = "00000";
	Admin::adminPin = "12345";
}

std::string Admin::getAdminAcc(){
	return Admin::adminAcc;
}

std::string Admin::getAdminPin(){
	return Admin::adminPin;
}

int Admin::printMenu(){
	std::cout<<"Success! Please enter one of the options from the following menu."<<std::endl;
	std::cout<<"1) Add a user"<<std::endl;
	std::cout<<"2) Delete a user"<<std::endl;
	std::cout<<"3) List all users"<<std::endl;
	std::cout<<"4) Apply interest to all saving accounts"<<std::endl;
	std::cout<<"5) Exit"<<std::endl;
	std::cout<<"\n Please enter your choice: ";
	std::cin>>Admin::answer;
	return Admin::answer;
}

void Admin::addUser(){
	std::cout<<"Please enter the account number of the new user: ";
	std::cin>>Admin::userAcc;
	while(Admin::userAcc.length() != 5){
		std::cout<<"Please enter a valid account number."<<std::endl;
		std::cin>>Admin::userAcc;
	}
	std::cout<<"Please enter the PIN of the new account: ";
	std::cin>>Admin::userPin;
	while(Admin::userPin.length() != 5){
		std::cout<<"Please enter a valid PIN."<<std::endl;
	}

	std::cout<<"Please enter the starting balance of the new Checking account: ";
	std::cin>>Admin::initialChecking;
	std::cout<<"Please enter the starting balance of the new Saving account: ";
	std::cin>>Admin::initialSaving;
}

std::string Admin::getNewUser(){
	return Admin::userAcc + "," + Admin::userPin + "\n";
}

std::string Admin::deleteUser(){
	std::cout<<"Please enter the account number to be deleted: ";
	std::cin>>Admin::deletedAcc;
	while(Admin::deletedAcc.length() != 5){
		std::cout<<"Please enter a valid account number: ";
		std::cin>>Admin::deletedAcc;
	}
	return Admin::deletedAcc;
}
