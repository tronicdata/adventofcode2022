// https://adventofcode.com/2022/day/2
// Calculate Rock Paper Scissors Strategy

#include <stdio.h>
#include <string.h>

#define WIN 6
#define LOSE 0
#define DRAW 3

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
                
                points = 1;
                printf("X vs %c\n", opp);
                
                if(opp == 'C'){
                    printf("WIN!\n");
                    points+= WIN;
                } else if(opp == 'B'){
                    printf("LOSE!\n");
                    points+= LOSE;
                } else {
                    printf("DRAW!\n");
                    points+= DRAW;
                }
                
                
                printf("Points scored: %d\n", points);
                
                break;
                
            case 'Y':
            
                points = 2;
                
                printf("Y vs %c\n", opp);
                if(opp == 'A'){
                    printf("WIN!\n");
                    points+= WIN;
                } else if(opp == 'C'){
                    printf("LOSE!\n");
                    points+= LOSE;
                } else {
                    printf("DRAW!\n");
                    points+= DRAW;
                }
                
                break;
                
            case 'Z':
            
            
                printf("Z vs %c\n", opp);
            
                points = 3;
                
                if(opp == 'B'){
                    printf("WIN!\n");
                    points+= WIN;
                } else if(opp == 'A'){
                    printf("LOSE!\n");
                    points+= LOSE;
                } else {
                    printf("DRAW!\n");
                    points+= DRAW;
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

