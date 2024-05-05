- The balances are reset every time the program is run because the balances cannot be edited in the text file, and the program needs initialization of balances of each account in order to run.
- After deleting an account, the deleted account number will be written in deletedAcc.txt, and added to the deleted accounts' arraylist
- Information.txt will only contain the account number and the pin, and the deleted accounts will be still there even after deletion, but will not be read to the program

Goal: To make an ATM in Java with the admin, user, checking, and saving accounts

Input: The text file of user account number and pins

Output: 

For User - 

1) To Get Checking Balance
2) To Deposit into Checking
3) To Withdraw from Checking
4) To Get Saving Balance
5) To Deposit into Saving
6) To Withdraw from Saing
7) Exit

For Admin - 

1) To Add a new user
2) To delete a user
3) To List all the users
4) To apply interest into all saving accounts
5) Exit

Steps:
- Create a text file with the account numbers, and pins of each user: information.txt
- Create an empty text file to store the account number of deleted account: deletedAcc.txt
- Make a Checking class
- Make a Saving class which is inherited from the Checking class
- Make a User class
- Make an Admin Class
- Make a Homepage class to put everything together
- Make a makefile for linking purpose

Checking class:
- Refer to the UML, and create attributes, setters and getters, and methods
- Make a deposit method which ask the amount from the user, and update the balance
- Make a withdraw method which ask the amount from the user, and update the balance if the account is not empty



Saving class:
- Refer to the UML, and extends the Checking class
- Make a new method to apply interest to the saving account with a fixed rate of 0.2% and a duration of 6 months



User class:
- Refer to the UML, and create necessary attributes with setters and getters
- Create a method to validate the account number and pin the user entered, and returna boolean value
- Create a method to print the Menu for the user, and return the user's choice



Admin class:
- Refer to the UML, and create necessary attributes with setters and getters
- Create a method to print the Admin Menu, and return the user's choice
- Creat a method to add a new user, which asks the new account number, new pin, and new balances
- Create a method to return the account information of the user to store in the text file
- Create a method to delete a user by asking the account number to be deleted



Homepage class:
- Refer to the UML, and create necessary attributes, instantiate relevant objects, and create arraylists
- Create a method to validate the length of the account number, which returns a boolean


- Create a method to read the file, information.txt, and get account number and pin by splitting the line
	- Check if the read account is the deleted account number from the arraylist of deleted accounts
	- If so, skip the line
	- Otherwise, add the account information to the arraylists of account number, and pins
	- Set the initial balance for each user as $100.0
	- Initialize each object for the number of times of the existing users


- Create a method to perform the admin's operations
	- First, validate the admin's account and pin, and ask for what she wants to do after showing the menu
	- If she chose to add a new user, call the addUser method from the admin class, and add the new entered information to the arraylists of the balances, and write the new account information to the information.txt
	- If she chose to deleted a user, call the deleteUser method from the admin class
		- If the entered account is not empty, ask her if she wants to continue deleting the account by withdrawing alll the funds in the account
			- If she chose to proceed, set the balances of that account to $0.0, and write the account information to the deletedAcc.txt, and remove all information about that account from the arraylists
		- If the entered account is empty, simply delete the account as stated above
	- If the admin chose to list all the users, print all the account information and balances of each user
	- If she chose to apply interest to all saving accounts, call the getSavingBalance from the Saving class, and print them
	- If she chose to exit, say goodbye


- Create a method to perform the user's operations
	- First, validate the user's account and pin, and ask what she wants to do after showing the menu
	- If she wants to get the balances of her checking and saving account, call the balance getters from Checking and Saving classes and print them
	- If she wants to deposit into checking or saving, call the deposit method from the classes, and update the new balances into the arraylist
	- If she wants to withdraw from checking or saving, call the withdraw method from the classes, and update the new balances into the arraylist
	- If she chose to exit, say goodbye


- Creat a method to put the adminMenu() and userMenu() together: testing()
	- Validate the entered account information, and if the account number equals to the admin's, call the adminMenu()
	- If it is not the admin's, but if the length of the account number is still 5, call the userMenu() for futher validation
	- Otherwise, even the account number's length is not 5, print "Unrecognized User"


- In the main method, call the readFile() and testing() first
	- Then, ask the user if she wants to do anything else, and if she answers yes, call the tesing() again by making a while loop
	- If she answers no, simply say goodbye
