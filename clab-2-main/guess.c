#include <stdio.h>
#include <stdlib.h>


/* Main function */
int main() {
  
    /* Initializing our variables*/
    int seed, random_num, guess;
    int guess_count = 0;

    /* Asking for user input and saving the value in the address of seed. */
    printf("Enter a random seed: ");
    scanf("%d", &seed);

    /* Telling the program to use the inputed seed as our random seed. */
    srand(seed);

    /* This will generate a number between 1 and 99, so we add the 1
       to make it 1-100. */
    random_num = (rand() % 100) + 1;


    /* This do-while loop will iterate until the random number is guessed
       by the user. It will increment the guesses as we are iterating
       and guessing. */
    
    do {
        printf("Guess a number: ");
        scanf("%d", &guess);
        guess_count++;

        if (guess < random_num) {
            printf("Too low!");
        } else if (guess > random_num) {
            printf("Too high!");
        } else {
            printf("Total guesses = %d", guess_count);
        }
    } while (guess != random_num);

    return 0;
}
