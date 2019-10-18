EDIT: Alex helped me get the program to start over based on user input after submitting this assignment last night,
the updated code is in the assignment file.


Design: Define secret number (as 0 to be updated later), min and max range (0 and 100), and ask user 1 to input the 
secret number,then update secret number. Define user 2 tries and attempts used. Ask user 2 to guess secret number, if 
too low, print too low, update min range to number guessed. If too high, print too high, update max range to number 
guessed. Repeat a maximum of 5 times, updating the range and telling user 2 that their guess is too low/high. Once user
2 guesses number or runs out of tries, ask if they would like to play again. If yes, run program again, if no, terminate
program.

Testing: User 1 secret number = 50. User 2 guess = 25, expected output = "25 is too low! You have 4 tries left, Guess the
number between 25 and 100: ". User 2 guess = 75, expected output = "75 is too high! You have 3 tries left, Guess the number
between 25 and 75: ". User 2 guess = 50, expected output = "You guessed it, 50! It took you 3 tries, Would you like to play
again? (y/n) ". User 2 input = "y", expected output = rerun program, actual output is program terminates.

Reflection: In week 2, we learned about common inputs (such as scanf) and common outputs (such as printf). We also learned
about data types such as int and char. While working on the project, I learned how to update the range while the program is
running, something I have not previously done. I also (attempted) to have the program start over based on user input which was
unsuccessful. There is nothing I wish I knew before this assignment, so far everything has been new because I have not previously
programmed in C but it has been a good experience. The hardest part of the project was having the program restart and keeping
track of the different outcomes of the guesses. During the implementation process, someone might mix up the different outcomes
of each guess since the set up of each one is very similar. Alex helped me approach this project, we talked through it in the
beginning which helped a lot. This project built off of the character types with the different ways you could approach it,
meaning there were many int's used and possible char's as well.
