# Welcome to My Mastermind
***

## Task
Mastermind is a game composed of 8 pieces of different colors. A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

## Description
The program checks user input for options if no options are provided it generates a random secret code and a default number of attemps which is 10. <br>
for each round it checks the number provided and compares it with the secret code, and outputs how many numbers are correct. <br>
If the user havent found the correct number after the defined number of attemps the game stops and the user loses.

## Installation
There is no installation, run make and then ./my_mastermind [options]

## Usage
gcc -o my_mastermind my_mastermind.c <br> 
./my_mastermind [-option] [option]

·To play with a random code generated and 10 attempts: run ./my_mastermind <br>
·To generate your own 4 digits code: run ./my_mastermind -c [4 digit number] <br>
·To choose the number of attempts: run ./my_mastermind -t [1 digit number] <br>
·Flag combination is accepted: run ./my_mastermind -c 0123 -t 4 <br>

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
