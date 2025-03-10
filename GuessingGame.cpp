#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number within a specified range
int gRandomNum(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

// Function to play the game
void playGame(int lower, int upper, int maxAttempts) {
    // Generate the secret number
    int secretNumber = gRandomNum(lower, upper);
    int guess;
    int attempts = maxAttempts;
    int score = 0;

    // Welcome message
    cout << "Welcome to the number guessing game!\n";
    cout << "I have chosen a number between " << lower << " and " << upper << ".\n";

    // Main game loop
    while (attempts > 0) {
        // Prompt user for guess and display attempts left
        cout << "Enter your guess (attempts left: " << attempts << "): ";
        cin >> guess;

        // Check if guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number.\n";
            score = attempts;
            cout << "Your score: " << score << endl;
            return;
        } else if (guess < secretNumber) {
            cout << "Too low. Try again.\n";
        } else {
            cout << "Too high. Try again.\n";
        }

        // Decrease attempts count
        attempts--;
    }

    // If all attempts are used up
    cout << "Sorry, you've run out of attempts.\n";
}

int main() {
    srand(time(0)); // Seed the random number generator

    char playAgain;
    do {
        int lower, upper, maxAttempts;

        // Display difficulty levels and get user choice
        cout << "Choose difficulty level:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        int choice;
        cin >> choice;

        // Set game parameters based on user choice
        switch (choice) {
            case 1:
                lower = 1;
                upper = 10;
                maxAttempts = 5;
                break;
            case 2:
                lower = 1;
                upper = 50;
                maxAttempts = 7;
                break;
            case 3:
                lower = 1;
                upper = 100;
                maxAttempts = 10;
                break;
            default:
                cout << "Invalid choice. Setting to medium difficulty.\n";
                lower = 1;
                upper = 50;
                maxAttempts = 7;
                break;
        }

        // Play the game with the chosen parameters
        playGame(lower, upper, maxAttempts);

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
