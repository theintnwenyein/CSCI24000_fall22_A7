import java.util.*;

public class User{
	protected String pin;
	protected String account_no;
	protected boolean correct;
	protected int answer;
	Scanner input = new Scanner(System.in);
	
	public static void main(String[] args){
		new User();
	} // end main
	
	public User(){
		this.pin = "";
		this.account_no = "";
	}

	public void setPin(String pin){
		this.pin = pin;
	}

	public void setAccountno(String account_no){
		this.account_no = account_no;
	}

	public String getPin(){
		return this.pin;
	}

	public String getAccountno(){
		return this.account_no;
	}
	
	// method to check the validity of the account number and the pin
	public boolean pinCheck(String account_no, String pin){
		this.correct = false;
		if(this.account_no.equals(account_no) & this.pin.equals(pin)){
			correct = true;
		}
		else{
			correct = false;
		}
		return this.correct;
	}

	public int printMenu(){
		System.out.println("\n" + "Success! Please choose one of the options from the following menu.");
		System.out.println("1) Get Checking Balance");
		System.out.println("2) Deposit into Checking");
		System.out.println("3) Withdraw from Checking");
		System.out.println("4) Get Saving Balance");
		System.out.println("5) Deposit into Saving");
		System.out.println("6) Withdraw from Saving");
		System.out.println("7) Exit");
		System.out.print("Please enter your choice: ");
		answer = input.nextInt();
		return answer;
	}// end printMenu

}// end class	
