#include "checking.h"
#include <iostream>
#include <string>

Checking::Checking(){

	// Setting default values
	Checking::balance = 100.0;
	Checking::amount = 0.0;
}

void Checking::setBalance(double balance){
	Checking::balance = balance;
}

void Checking::deposit(){
	std::cout<<"Please enter the amount you want to deposit: ";
	std::cin>>Checking::amount;
	Checking::balance += Checking::amount;
	std::cout<<"Success! Your balance is now " << Checking::balance << std::endl;
}

void Checking::withdraw(){
	std::cout<<"Please enter the amount you want to withdraw: ";
	std::cin>>Checking::amount;
	if(Checking::amount > Checking::balance){
		std::cout<<"You only have " << Checking::balance << " in your checking account. You cannot withdraw more than that."<<std::endl;
	}
	else{
		Checking::balance -= Checking::amount;
		std::cout<<"Success! Your balance is now " << Checking::balance <<std::endl;
	}
}

double Checking::getBalance(){
	return Checking::balance;
}


