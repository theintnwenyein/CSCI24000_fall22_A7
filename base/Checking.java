import java.util.*;

public class Checking{
	Scanner input = new Scanner(System.in);
	protected double balance;
	protected double amount;

	public static void main(String[] args){
		new Checking();	
	}// end main


	public Checking(){
		this.amount = 0;
	}// end constructor

	public void setBalance(double balance){
		this.balance = balance;
	} // end setter

	public void deposit(){
		System.out.print("Please enter the amount you want to deposit: ");
		this.amount = input.nextDouble();
		this.balance += this.amount;
		System.out.println("Success! Your balance is now " + this.balance + ".");
	}// end deposit

	public void withdraw(){
		System.out.print("Please enter the amount you want to withdraw: ");
		this.amount = input.nextDouble();
		if(this.amount > this.balance){
			System.out.println("You only have " + this.balance + " in you checking account. You cannot withdraw more than that.");
		}
		else{
			this.balance -= this.amount;
			System.out.println("Success! Your balance is now " + this.balance + ".");
	}
	}// end withdraw

	public double getBalance(){
		return this.balance;
	} // end getter
}

