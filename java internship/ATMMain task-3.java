// Task-3 Java programming
import java.util.Scanner;

class BankAccount {
    private double balance;

    public BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Insufficient balance");
        }
    }
}

class ATM {
    private BankAccount bankAccount;

    public ATM(BankAccount account) {
        bankAccount = account;
    }

    public void displayOptions() {
        System.out.println("Options:");
        System.out.println("1. Withdraw");
        System.out.println("2. Deposit");
        System.out.println("3. Check Balance");
        System.out.println("4. Exit");
    }

    public void performTransaction(int choice) {
        Scanner scanner = new Scanner(System.in);
        double amount;

        switch (choice) {
            case 1:
                System.out.print("Enter amount to withdraw: ");
                amount = scanner.nextDouble();
                bankAccount.withdraw(amount);
                break;
            case 2:
                System.out.print("Enter amount to deposit: ");
                amount = scanner.nextDouble();
                bankAccount.deposit(amount);
                break;
            case 3:
                System.out.println("Current balance: " + bankAccount.getBalance());
                break;
            case 4:
                System.out.println("Thank you for using the ATM.");
                System.exit(0);
                break;
            default:
                System.out.println("Invalid choice");
        }
    }
}

public class ATMMain {
    public static void main(String[] args) {
        BankAccount userAccount = new BankAccount(1000);
        ATM atm = new ATM(userAccount);

        Scanner scanner = new Scanner(System.in);
        int choice;

        while (true) {
            atm.displayOptions();
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            atm.performTransaction(choice);
        }
    }
}
