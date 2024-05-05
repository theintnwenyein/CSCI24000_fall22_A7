import java.util.*;

public class Admin{
	Scanner input = new Scanner(System.in);
	protected String adminAcc;
	protected String adminPin;
	protected String userAcc;
	protected String userPin;
	protected double initialChecking;
	protected double initialSaving;
	protected String line;
	protected String deletedAcc;
	protected int answer;

	public static void main(String[] args){
		new Admin();
		
	}// end main

	public Admin(){
		this.adminAcc = "00000";
		this.adminPin = "12345";
	}// end constructor
	
	public int printMenu(){
		System.out.println("Success! Please enter one of the options from the following menu.");
		System.out.println("1) Add a user");
		System.out.println("2) Delete a user");
		System.out.println("3) List all users");
		System.out.println("4) Apply interest to all saving accounts");
		System.out.println("5) Exit");
		System.out.print("\n" + "Please enter your choice: ");
		answer = input.nextInt();
		return answer;
	}
	public void addUser(){
		System.out.print("Please enter the account number of the new user: ");
		this.userAcc = input.next();
		while(this.userAcc.length() != 5){
			System.out.print("Please enter a valid account number: ");
			this.userAcc = input.next();
		}
		System.out.print("Please enter the pin of the new account: ");
		this.userPin = input.next();
		while(this.userPin.length() != 5){
			System.out.print("Please enter a valid PIN: ");
			this.userPin = input.next();
		}

		System.out.print("Please enter the starting balance of the new checking accout: ");
		this.initialChecking = input.nextDouble();
		System.out.print("Please enter the starting balance of the new saving account: ");
		this.initialSaving = input.nextDouble();
	
	}// end addUser
	public String getNewUser(){
		return this.userAcc + "," + this.userPin;

	}// end getNewUser

	public String deleteUser(){
		System.out.print("Please enter the account number to be deleted: ");
		deletedAcc = input.next();
		return deletedAcc;
		
	}// end deleteUser

}// end class def

	
