#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;
int Randomize(int first_number,int last_number) {
    if (last_number == 0) {
        long long int randomized_number = ((rand() % (last_number+1)) + (first_number+1))-1;
    }
    else {
        long long int randomized_number = (rand() % last_number) + first_number;
        return randomized_number;
    }
}
int main() {
    long long int first_number, last_number, guess, amountOfguesses,amountOfattempts=0, randomized_number;
    bool easy = false, medium = false, hard = false, victory = false;
    short int diff_pick;
    cout << "Welcome to the Number Guessing Game 1.0!" << endl;
    Sleep(3000);
    cout << "Choose your range of numbers:" << endl;
    Sleep(3000);
    cout << "Reminder: The last number must be at least 3 more than the first number." << endl;
    Sleep(2000);
    cout << "First number is: "; cin >> first_number; cout << endl;
    cout << "Last number is: "; cin >> last_number; cout << endl;
    if (last_number - first_number < 3) { cout << "Your values don't meet game's rules, please try again."; Sleep(10000); abort();}
    Sleep(3000);
    cout << "Choose your difficulty:" << endl;
    cout << "Press \"1\" for: "<< "\t" << "Easy - " << (last_number - first_number) / 2 + 1 << " attempts." << endl;
    cout << "Press \"2\" for: " << "\t" << "Medium - " << (last_number - first_number) / 4 + 1 << " attempts." << endl;
    cout << "Press \"3\" for: " << "\t" << "Hard - " << (last_number - first_number) / 8 + 1 << " attempts." << endl;
    cin >> diff_pick;
    Sleep(2000);
    randomized_number = Randomize(first_number, last_number);
    switch (diff_pick) 
    {
    case 1: easy = true; amountOfguesses = (last_number - first_number) / 2 + 1; break;
    case 2: medium = true; amountOfguesses = (last_number - first_number) / 4 + 1; break;
    case 3: hard = true; amountOfguesses = (last_number - first_number) / 8 + 1; break;
    default: cout << "Your value doesn't meet game's rules, the game will close in 10 seconds. Please try again."; Sleep(10000); abort();
    }
    cout << "I'm thinking of a number between " << first_number << " and " << last_number << "." << endl;
    cout << "Take your time, you have " << amountOfguesses << " guesses." << endl;
    while (amountOfguesses) {
        cin >> guess;
        if (guess > last_number || guess < first_number) {
            cout << "That number is out of guessing range! Try again!" << endl;
        }
        else {
            if (guess == randomized_number) {
                victory = true;
                break;
            }
            else {
                --amountOfguesses;
                ++amountOfattempts;
                cout << "Wrong! You have " << amountOfguesses << " guesses left." << endl;
            }
        }
    }
    if (victory == true) {
        cout << "Congratulations! You guessed the number in " << amountOfattempts <<" attempts." << endl;
    }
    else {
        cout << "You lost! Good luck next time!" << endl;
    }
}