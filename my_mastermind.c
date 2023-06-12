#include "my_mastermind.h"
#include <stdio.h>
#include <string.h>

//Pieces will be '0' '1' '2' '3' '4' '5' '6' '7' '8 and 4 pieces
int check_input(char* input) { 
    int i = 0;

    for (;i < 4 && input[i] != 0; i++) {
        if (input[i] >= 48 && input[i] <= 56) {
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

//lenght of input
int len_input(char* input) {
    int i = 0;
    while (input[i] != '\n') {  
        i++;
    }
    return i; 
}

//check if input is equal to secretcode
int check_secretcode(char* secret_code, char* input) {
    int Wellplaced = 0, Missplaced = 0, input_temp_size = 0, secret_temp_size = 0;
    char input_temp[4], secret_temp[4]; 

    for (int i = 0; i < 4; i++) {
        if (secret_code[i] == input[i]) {
            Wellplaced++;
        } else {
            input_temp[input_temp_size++] = input[i];  
            secret_temp[secret_temp_size++] = secret_code[i];
        }
    }
        
    for (int i = 0; i < input_temp_size; i++) { 
        for (int j = 0; j < secret_temp_size; j++) {
            if (secret_temp[i] == input_temp[j]) {  
                Missplaced++; secret_temp_size--; 
                secret_temp[j] = secret_temp[secret_temp_size];
                break;
            }
        }
    }
    //result to user
    if (Wellplaced < 4) {
        printf("Well placed pieces: %d\n", Wellplaced);
        printf("Misplaced pieces: %d\n---\n", Missplaced);
        return 0;
    }else {
        printf("Congratz! You did it!");
        return 1;
    }
}

int main(int argc, char** argv)
{
    char* secret_code = malloc(sizeof(char)); 
    int max_attempts = 10;
    int c_flag = 0;
    int i = 1;

    //if the person has entered -c
    for (int i = 0; i < argc; i++) {
        if(strcmp(argv[i], "-c") == 0)
        {
            secret_code = argv[i + 1];  
            c_flag = 1;
        }
    }

    if(c_flag == 0){
        srand(time(NULL));
        for (int i = 0; i < 4; i++) {
            int* random_number = malloc(5*sizeof(int*));
            *random_number = (rand() % 8);
            secret_code[i] = (*random_number + '0');
        }
    }
    
    // -t 
    for (int i = 0; i < argc; i++) {
        if(strcmp(argv[i], "-t") == 0){
            max_attempts = atoi(argv[i + 1]);
        }
    }

    secret_code[4] = '\0';

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
    printf("---\n");

    for (; i <= max_attempts; i++) {
        printf("Round %d\n", i);

        char* input = malloc(sizeof(char));

        int bytes_read = read(0, input, 5);

        if (bytes_read == 0) {
            printf("Exiting...");
            return 0;
        }

        check_input(input);

        while (len_input(input) != 4) {  
            printf("Wrong Input\n");
            int bytes_read = read(0, input, 5);

            if (bytes_read == 0)
            {
                printf("Exiting...\n");
                return 0;
            }
        }

        int result = check_secretcode(secret_code, input);

        if (result != 0) {
            break;
        }

        if(i == max_attempts)
            printf("You didn't find the secret code; Good luck next time!");
    }

    return 0;
}