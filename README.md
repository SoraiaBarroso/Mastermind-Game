# Mastermind-Game-

This is an implementation of the Mastermind Game


MASTERMIND:

Mastermind is a game composed of 8 pieces of different colors. A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code. After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.

A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

USAGE:

·To play with a random code generated and 10 attempts: run ./my_mastermind 
·To generate your own 4 digits code: run ./my_mastermind -c 0123 
·To choose the number of attempts: run ./my_mastermind -t 4 
·Flag combination is accepted: run ./my_mastermind -c 0123 -t 4
