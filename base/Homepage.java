import java.util.*;
import java.io.*;

public class Homepage{

	static Scanner input = new Scanner(System.in);
	
	static Admin a = new Admin(); // Instantiate Admin
	static String accno;
	static String pin;
	static double checkingBalance;
	static double savingBalance;
	static String line; // For reading each line from the file
	static int count; // For the number of line in the file
	int index; 
	static boolean correct;
	static int answer; // For getting the answer from the user

	// Creating arraylist to sotre the account numbers and pins
	static ArrayList<String> accounts = new ArrayList<String>();
	ArrayList<String> pins = new ArrayList<String>();

	// Creating arraylist to store each Checking balance and Saving balance
	// Second arraylist is a copy of the original one for the purpose of processing data
	
	ArrayList<Double> checkingBal = new ArrayList<Double>();
	ArrayList<Double> secondCheckingBal = checkingBal;


	ArrayList<Double> savingBal = new ArrayList<Double>();
	ArrayList<Double> secondSavingBal = savingBal;

	// An arraylist to sotre the account number of deleted account by the admin
	ArrayList<String> deletedAcc = new ArrayList<String>();

	// Arraylists of User object, Checking object, and the Saving object
	static ArrayList<User> u = new ArrayList<User>();
	static ArrayList<Checking> c = new ArrayList<Checking>();
	static ArrayList<Saving> s = new ArrayList<Saving>();


	// Main
	public static void main(String[] args){
		Homepage p = new Homepage();
		p.readFile();
		p.testing();
		correct = false;

		// Looping the program in case the user wants to perform another operation
		// or do something for a friend's account
		while(!correct){
			System.out.println("\n" + "Are there anything else you want to do today?" + "\n");
			System.out.println("1) Yes. I want to start again.");
			System.out.println("2) No. I am good");
			System.out.print("\n" + "Please enter your choice: ");
			pin = input.nextLine();
			if(pin.equals("1")){
				p.testing();
			}
			else{
				System.out.println("Thank you for choosing RETH Bank. Have a wonderful day.");
				correct = true;
			}
		}// end while
		
	}// end main

	// Checking the length of the account number
	public boolean check(String accno){
		correct = false;
		if(accno.length() == 5){
			correct = true;
		}
		return correct;
	}
	

	public void readFile(){
		try{
			File theFile = new File("information.txt");
			File deletedFile = new File("deletedAcc.txt"); // Deleted account numbers are stored in deletedAcc.txt

			Scanner input = new Scanner(theFile);
			Scanner deleted = new Scanner(deletedFile);

			while(deleted.hasNextLine()){
				line = deleted.nextLine();
				deletedAcc.add(line); // Adding the deleted account in the text file to the arraylist
			}

			while(input.hasNextLine()){
				line = input.nextLine();
				accno = line.split(",")[0]; // Getting the account number
				if(check(accno) == true && !deletedAcc.contains(accno)){  // If the length of the account number is 5 and it is not the deleted account

					pin = line.split(",")[1]; // Getting the PIN
					u.add(new User()); 
	
					accounts.add(accno);
					pins.add(pin);

					// Standard starting balance is $100 for each user
					checkingBal.add(100.0);
					savingBal.add(100.0);

					count++;	
				}// end while
			}// end while
				
				// Setting the account number and pin for each user
				for(int i = 0; i < count; i++){
					u.get(i).setAccountno(accounts.get(i));
					u.get(i).setPin(pins.get(i));					
				}
			
		}catch(IOException e){
			System.out.println(e.getMessage());
		}// end catch
		

		// Setting the balances for each user
		for(int i = 0; i < checkingBal.size(); i++){
			c.add(new Checking());
			c.get(i).setBalance(secondCheckingBal.get(i));
			
		}// end for
		
		for(int i = 0; i <savingBal.size(); i++){
			s.add(new Saving());
			s.get(i).setBalance(secondSavingBal.get(i));
			//System.out.println(s.get(i).getSavingBalance());
		}// end for


	}// end readFile

	public void adminMenu(){
		try{
			FileWriter writer = new FileWriter("information.txt",true); // including ture since it is appending
			FileWriter deleted = new FileWriter("deletedAcc.txt",true);

			BufferedWriter bw = new BufferedWriter(writer);
			BufferedWriter bd = new BufferedWriter(writer);
			BufferedWriter del = new BufferedWriter(deleted);

			System.out.print("Please enter your PIN: ");
			pin = input.nextLine();
			if(pin.equals(a.adminPin)){
				a.printMenu();
				switch(a.answer){
					case 1:
						a.addUser();
						bw.write(a.getNewUser());
						secondCheckingBal.add(a.initialChecking);
						secondSavingBal.add(a.initialSaving);
						bw.close();
			
						System.out.println("Successfully added the new user with the following information!");
						System.out.println("Account number, PIN: " + a.userAcc + "," + a.userPin);
						System.out.println("Starting Checking Balance, starting Saving Balance: "+ a.initialChecking + "," + a.initialSaving);
					 	break;
					case 2:
						index = accounts.indexOf(a.deleteUser());
						if(checkingBal.get(index) != 0 | savingBal.get(index) != 0){
							System.out.println("You cannot delete. The account is not empty." + "\n");
							System.out.println("1) Do you want to continue by withdrawing all the funds in the account?");
							System.out.println("2) Nevermind." + "\n");
							System.out.print("Please enter your choice: " + "\n");
							pin = input.nextLine();
							if(pin.equals("1")){
								System.out.println("Withdrawing all the funds...");
								checkingBal.set(index,0.0);
								savingBal.set(index,0.0);
								System.out.println("Deleting the account...");
								
								// Writing the deleted account number to deletedAcc.txt
								del.write(accounts.get(index));
								del.write("\n");
								del.close();

								pins.set(index,"0");
								secondCheckingBal.remove(index);
								secondSavingBal.remove(index);
								accounts.remove(index);
								pins.remove(index);
								System.out.println("Successfully deleted");
								

							}
							
						}
						else{

							
							del.write(accounts.get(index));
							del.close();
							pins.set(index,"0");
							secondCheckingBal.remove(index);
							secondSavingBal.remove(index);
							accounts.remove(index);
							pins.remove(index);
							System.out.println("Successfully deleted.");
							bd.close();
						}
						break;
					case 3:

						System.out.println("\n" + "Format: Account Number, PIN, Checking Balance, Saving Balance" + "\n");
						for(int i = 0; i < accounts.size(); i++){
							if(accounts.get(i).length() == 5){

								System.out.println(accounts.get(i) + "," + pins.get(i) + "," + checkingBal.get(i) + "," + savingBal.get(i) );	
							}// end if
						}// end for
						break;
					case 4:
						for(int i = 0; i < accounts.size(); i++){
							if(accounts.get(i).length() == 5){
								System.out.println("\n" + "Saving account balance is now " + s.get(i).getSavingBalance());
							}
						}
						break;
					case 5:
						System.out.println("Thank you for choosing RETH Bank. Have a wonderful day.");
						break;
				}// end switch
			}// end pin if
			else{
				System.out.println("Wrong PIN!");
			}// end else
		}catch(IOException e){
			System.out.println(e.getMessage());
		}

	}// end adminMenu	


	public void userMenu(){

			for(int i = 0; i < checkingBal.size(); i++){
				if(accno.length() == 5 && accno.equals(u.get(i).getAccountno())){
					index = i;

					System.out.print("Please enter your PIN: ");
					pin = input.nextLine();
					if(u.get(index).pinCheck(accno,pin) == true){
						switch(u.get(index).printMenu()){
							case 1: 
								System.out.println("Your Checking balance is " + secondCheckingBal.get(index));
								break;
							case 2:
								c.get(index).deposit();
								secondCheckingBal.set(index,c.get(i).balance);
								break;
							case 3: 
								c.get(index).withdraw();
								secondCheckingBal.set(index,c.get(i).balance);
								break;
							case 4:
								System.out.println("Your Saving balance is " + s.get(index).getSavingBalance());
								break;
							case 5:
								s.get(index).deposit();
								secondSavingBal.set(index,s.get(i).saving_balance);
								break;
							case 6:
								s.get(index).withdraw();
								secondSavingBal.set(index,s.get(i).saving_balance);
								break;
							case 7:
								System.out.println("Thank you for choosing RETH Bank. Have a wonderful day.");
								break;
						}// end swiitch
					}// end pin if

				}// end if

			}// end for
//		}// end if
		
	}// end userMenu()

	public void testing(){
		System.out.print("Please enter your account number to get started: ");
		accno = input.nextLine();
		if(accno.length() == 5 && accno.equals(a.adminAcc)){
			adminMenu();
		}
		else if(accno.length() == 5 && !accno.equals(a.adminAcc)){
			userMenu();
		}
		else{
			System.out.println("Unrecognized user");
		}
	}// end testing
}// end class

