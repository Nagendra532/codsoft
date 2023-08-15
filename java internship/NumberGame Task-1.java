//Task-1  java programming
import java.util.Random;
import java.util.Scanner;

public class NumberGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        
        int minRange = 1;
        int maxRange = 100;
        int targetNumber = random.nextInt(maxRange - minRange + 1) + minRange;
        
        int maxAttempts = 5;
        int attempts = 0;
        boolean hasGuessed = false;
        
        System.out.println("Welcome to the Number Guessing Game!");
        System.out.println("I have selected a number between " + minRange + " and " + maxRange + ".");
        
        while (attempts < maxAttempts) {
            System.out.print("Enter your guess: ");
            int userGuess = scanner.nextInt();
            
            if (userGuess < targetNumber) {
                System.out.println("Too low. Try again.");
            } else if (userGuess > targetNumber) {
                System.out.println("Too high. Try again.");
            } else {
                System.out.println("Congratulations! You've guessed the number " + targetNumber + " correctly!");
                hasGuessed = true;
                break;
            }
            
            attempts++;
        }
        
        if (!hasGuessed) {
            System.out.println("Sorry, you've used all your attempts. The number was " + targetNumber + ".");
        }
        
        scanner.close();
    }
}
