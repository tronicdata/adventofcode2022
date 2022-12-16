// https://adventofcode.com/2022/day/2
// Calculate Rock Paper Scissors Strategy

#include <stdio.h>
#include <string.h>

#define WIN 6
#define LOSE 0
#define DRAW 3
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main(){
    
    int totalScore = 0;
    
    // Open the file for reading
    FILE *file = fopen("inputData.txt", "r");
    
    // Check if the file was opened successfully
    if( file == NULL ){
        perror("Error opening file");
        return -1;
    }
    
    
    // Read the contents of the file line by line
    char buf[1024];
    while (fgets(buf, sizeof(buf), file) != NULL){
        
        char opp= buf[0];
        char player= buf[2];
        
        // printf("%c %c\n", opp, player);
        
        int points = 0; 
        switch(player){
            
            case 'X':
                //LOSE 
                
                points = LOSE;
                if(opp == 'C'){
                    points+= PAPER;
                } else if(opp == 'B'){
                    points+= ROCK;
                } else {
                    points+= SCISSORS;
                }
                
                break;
                
            case 'Y':
            
                //DRAW
                points = DRAW;
                
                if(opp == 'A'){
                    points+= ROCK;
                } else if(opp == 'C'){
                    points+= SCISSORS;
                } else {
                    points+= PAPER;
                }
                
                break;
                
            case 'Z':
                //WIN
            
                points = WIN;
                
                if(opp == 'B'){
                    points+= SCISSORS;
                } else if(opp == 'A'){
                    points+= PAPER;
                } else {
                    points+= ROCK;
                }
                
                break;
                
            default:
            
                printf("nothing\n");
                
        } 
        
        totalScore += points;
        
        printf("Total Score: %d\n", totalScore);
        
        
        
        // totalScore += determineWinner(opp, player);
        
        /*
        int totalScore = 0;
        char opp;
        char player;
        
        - seperate line into letters
        - - set first letter to opp, and second letter to player
        - compare letters
        - determine win/lose/draw
        - totalScore+= playerLetter + win/lose/draw
        
        */
        
    }
    
    printf("Total Score= %d\n", totalScore);
    
    // Close the file
    fclose(file);

    
    return 0;
}

