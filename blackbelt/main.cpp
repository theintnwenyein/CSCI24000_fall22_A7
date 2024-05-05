#include "checking.h"
#include "saving.h"
#include "user.h"
#include "admin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

Admin a;
bool correct;
int place, answer;
std::ifstream fFile;	// to read information.txt
std::ifstream sFile;	// to read deletedAcc.txt
std::ofstream oFile;	// to write into information.txt
std::ofstream dFile;	// to write into deletedAcc.txt
std::ofstream aFile;	// to write into deletedAcc.txt
std::stringstream ss;
std::string line, account, pin, deletedAcc,accno;

std::vector<std::string> accounts;
std::vector<std::string> pins;	
std::vector<std::string> deletedAccs;
std::vector<double> checkingBal;
std::vector<double> savingBal;

// Vectors of objects
std::vector<User> u;
std::vector<Checking> c;
std::vector<Saving> s;

// Function prototypes
void readFile();
bool check();
bool contains();
void adminMenu();
int getIndex();
void userMenu();
void testing();


int main(){
	readFile();
	testing();
	
	correct = false;
	while(!correct){
		std::cout<<"\n"<<"Are there anything else you want to do today?"<<std::endl;
		std::cout<<"1) Yes. I want to start again."<<std::endl;
		std::cout<<"2) No. I am good"<<std::endl;
		std::cout<<"\n"<<"Please enter your choice: ";
		std::cin>>answer;
		if(answer == 1){
			testing();
		}
		else{
			std::cout<<"Thank you for choosing RETH Bank. Have a wonderful day."<<std::endl;
			correct = true;
		}
	}
}// end main

bool check(std::string accno){
	correct = false;
	if(accno.length() == 5){
		correct = true;
	}
	return correct;
}// end check

// checking if the account numbers in information.txt are the same as the ones in deletedAcc.txt in order to prevent reading deleted account numbers
bool contains(std::string accno){
	correct = true;
	if(find(deletedAccs.begin(), deletedAccs.end(), accno) != deletedAccs.end()){
		correct = false;
	}
	return correct;
}// end contains

void readFile(){
	sFile.open("deletedAcc.txt");
	fFile.open("information.txt");

	while(getline(sFile,deletedAcc)){
		deletedAccs.push_back(deletedAcc); // getting deleted account number
			}// end while
	while(getline(fFile,line)){
		ss.clear();
		ss.str(line);

		getline(ss, account, ',');
		getline(ss, pin, ',');
		
		if(check(account) == true and contains(account) == true){
			accounts.push_back(account);
			pins.push_back(pin);
			u.push_back(User());
			c.push_back(Checking());
			s.push_back(Saving());

			checkingBal.push_back(100.0);
			savingBal.push_back(100.0);
		}// end if

		
	}// end while

	for(int i = 0; i < accounts.size(); i++){
		u.at(i).setAccountno(accounts.at(i));
		u.at(i).setPin(pins.at(i));
		c.at(i).setBalance(checkingBal.at(i));
		s.at(i).setBalance(savingBal.at(i));
		
	}// end for

}// end readFile

// Getting an index of a certain element in a vector using iterator
int getIndex(std::string accno){
	auto it = std::find(accounts.begin(), accounts.end(), accno);
	place = std::distance(accounts.begin(),it);
	return place;
}
void adminMenu(){

	oFile.open("information.txt", std::ios_base::app); // std::ios_base::app for appending text
	dFile.open("deletedAcc.txt", std::ios_base::app);
	aFile.open("deletedAcc.txt", std::ios_base::app);
	std::cout<<"Please enter your PIN: ";
	std::cin>>pin;

	if(pin == a.getAdminPin()){
		switch(a.printMenu()){
			case 1:
				a.addUser();
				oFile<<a.getNewUser();
				checkingBal.push_back(a.initialChecking);
				savingBal.push_back(a.initialSaving);
				oFile.close();
				std::cout<<"Successfully added!"<<std::endl;
				break;
			case 2:
				place = getIndex(a.deleteUser());
				if(checkingBal.at(place) != 0 or savingBal.at(place) != 0){
					std::cout<<"Failed! The account is not empty."<<std::endl;
					std::cout<<"1) Do you want to continue by withdrawing all the available funds?"<<std::endl;
					std::cout<<"2) Nevermind."<<" \n"<<std::endl;
					std::cin>>answer;
					if(answer == 1){
						std::cout<<"Withdrawing all the funds..."<<std::endl;
						checkingBal.at(place) = 0.0;
						savingBal.at(place) = 0.0;
						std::cout<<"Deleting the account..."<<std::endl;

						// writing the deleted account number to the file
						dFile<<accounts.at(place);
						dFile.close();

						// Removing the deleted account's information from the vectors
						accounts.erase(accounts.begin() + place);
						pins.erase(pins.begin() + place);
						checkingBal.erase(checkingBal.begin() + place);
						savingBal.erase(savingBal.begin() + place);
						std::cout<<"Successfully deleted"<<std::endl;
							
					}// end if
				}// end if
				else{
					aFile<<accounts.at(place);
					aFile.close();
					accounts.erase(accounts.begin() + place);
					pins.erase(pins.begin() + place);
					checkingBal.erase(checkingBal.begin() + place);
					savingBal.erase(savingBal.begin() + place);
					std::cout<<"Successfully deleted"<<std::endl;
				}// end else
				break;
			case 3:
				std::cout<<"\n"<<"Format: Account Number, PIN, Checking Balance, Saving Balance"<<"\n"<<std::endl;
				for(int i = 0; i < accounts.size(); i++){
					std::cout<<accounts.at(i)<<","<<pins.at(i)<<","<<checkingBal.at(i)<<","<<savingBal.at(i)<<std::endl;

				}// end for
				break;
			case 4:
				for(int i = 0; i < accounts.size(); i++){
					std::cout<<"\n"<<"Saving accout balance is now "<< s.at(i).getSavingBalance()<<std::endl;
				}// end for
				break;
			case 5:
				std::cout<<"Thank you for choosing RETH Bank. Have a wonderful day."<<std::endl;
				break;
		
		}// end switch
	}// end if
	else{
		std::cout<<"Wrong PIN!"<<std::endl;
	}

}// end adminMenu

void userMenu(){
	for(int i = 0; i < accounts.size(); i++){
		if(accno.length() == 5 and accno == u.at(i).getAccountno()){
			place = i;

			std::cout<<"Please enter your PIN: ";
			std::cin>>pin;

			if(u.at(place).pinCheck(accno,pin) == true){
				answer = u.at(place).printMenu();
				switch(answer){
						case 1:
							std::cout<<"Your checking balance is "<< checkingBal.at(place)<<std::endl;
							break;
						case 2:
							c.at(place).deposit();
							checkingBal.at(place) = c.at(place).getBalance();
							break;
						case 3:
							c.at(place).withdraw();
							checkingBal.at(place) = c.at(place).getBalance();
							break;
						case 4:
							std::cout<<"Your saving balance is now "<< s.at(place).getSavingBalance()<<std::endl;
							break;
						case 5:
							s.at(place).deposit();
							savingBal.at(place) = s.at(place).getSavingBalance();
							break;
						case 6:
							s.at(place).withdraw();
							savingBal.at(place) = s.at(place).getSavingBalance();
							break;
						case 7:
							std::cout<<"Thank you for choosing RETH Bank. Have a wonderful day."<<std::endl;
							break;

						}// end switch
			}// end if
		}// end if
	}//end for
}// end userMenu

void testing(){
	std::cout<<"Please enter your account number to get started: ";
	std::cin>>accno;
	if(accno.length() == 5 and accno == a.getAdminAcc()){
		adminMenu();	
	}
	else if(accno.length() == 5 and accno != a.getAdminAcc()){
		userMenu();
	}
	else{
		std::cout<<"Unrecognized User"<<std::endl;
	}
}// end testing
