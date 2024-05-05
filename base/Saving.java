import java.util.*;

public class Saving extends Checking{
	
	protected double saving_balance;

	public static void main(String[] args){
		new Saving();
		
		}// end main
	
	public Saving(){
		
	}// end constructor

	public double getSavingBalance(){
		this.saving_balance = getBalance() * (1 + ((0.2/100) * 0.5)); // rate = 0.2%, time period = 6 months
		return this.saving_balance;
	}
}// end class def
