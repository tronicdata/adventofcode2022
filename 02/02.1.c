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
        
        int points = 0; 
        switch(player){
            
            case 'X':
                
                points = 1;
                
                if(opp == 'C'){
                    points+= WIN;
                } else if(opp == 'B'){
                    points+= LOSE;
                } else {
                    points+= DRAW;
                }
                
                break;
                
            case 'Y':
            
                points = 2;
                
                if(opp == 'A'){
                    points+= WIN;
                } else if(opp == 'C'){
                    points+= LOSE;
                } else {
                    points+= DRAW;
                }
                
                break;
                
            case 'Z':
            
                points = 3;
                
                if(opp == 'B'){
                    points+= WIN;
                } else if(opp == 'A'){
                    points+= LOSE;
                } else {
                    points+= DRAW;
                }
                
                break;
                
            default:
            
                printf("nothing\n");
                
        } 
        
        totalScore += points;
        
    }
    
    printf("Total Score= %d\n", totalScore);
    
    // Close the file
    fclose(file);

    
    return 0;
}

