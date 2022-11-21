#include "my_mastermind.h"
#include <stdlib.h>

//Pieces will be '0' '1' '2' '3' '4' '5' '6' '7' '8 and 4 pieces
int check_input(char* input){
    
    int i = 0;

    for(;i < 4 && input[i] != 0; i++)
    {
        if(input[i] >= 48 && input[i] <= 56)
        {
            return 0;
        }else{
            return 1;
        }
       
    }
    return 0;
}

//lenght of input
int len_input(char* input)
{
    int i = 0;
    while(input[i] != '\n')
    {  
        i++;
    }
    return i; 
}

//read input from user 
void read_input(char* input)
{
    read(0, input, 5);
    input[5] = '\0';
}

//check if input is equal to secretcode
int check_secretcode(char* secret_code, char* input)
{
    int Wellplaced = 0, Missplaced = 0, input_temp_size = 0, secret_temp_size = 0;
    char input_temp[4], secret_temp[4]; 

    for(int i = 0; i < 4; i++){
        if(secret_code[i] == input[i])
        {
            Wellplaced++;
        } else{
            input_temp[input_temp_size++] = input[i];  
            secret_temp[secret_temp_size++] = secret_code[i];
        }
    }
        

    for(int i = 0; i < input_temp_size; i++)
    { 
    for(int j = 0; j < secret_temp_size; j++)
    {
        if(secret_temp[i] == input_temp[j])
        {  
            Missplaced++; secret_temp_size--; 
            secret_temp[j] = secret_temp[secret_temp_size];
            break;
        }
    }
}
    //result to user
    if(Wellplaced < 4)
    {
        printf("Well placed pieces: %d\n", Wellplaced);
        printf("Misplaced pieces: %d\n---\n", Missplaced);
        return 0;
    }else{
        printf("Congratz! You did it!");
        return 1;
    }
}

int main(int ac, char** av)
{
    char* secret_code = malloc(sizeof(char)); 
    int max_attempts = 10;

    //if the person has entered -t or -c
    if(ac > 2 && av[1][0] == '-' && av[1][1] == 'c')
    {
        for(int i = 0; i<4; i++)
        {
            secret_code[i] = av[2][i];
        }
    }else{
        srand(time(NULL));
        for(int i = 0; i < 4; i++)
        {
        int* random_number = malloc(5*sizeof(int*));
        *random_number = (rand() % 8);
        secret_code[i] = (*random_number + '0');
        }
    }

    secret_code[4] = '\0';

    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");
    printf("---\n");

    for(int i = 1; i <= max_attempts; i++)
    {
        printf("Round %d\n", i);

        char* input = malloc(sizeof(char));

        read_input(input);
        check_input(input);

        while(len_input(input) != 4){  
            printf("Wrong Input\n");
            read_input(input);
        }

        int result = check_secretcode(secret_code, input);

            if(result != 0)
            {
            break;
            }
    }
    return 0;
}

