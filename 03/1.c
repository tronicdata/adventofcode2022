// https://adventofcode.com/2022/day/2
// Calculate Rock Paper Scissors Strategy

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int calcPriority(char item){
    int total = 0;
    bool stop = false;

    char c;
    int i = 1;
    for(c='a'; c<='z' && !stop; c++, i++){
        if( c == item){
            total += i;
            stop = true;
        }
    }
    for(c='A'; c<='Z' && !stop; c++, i++){
        if( c == item){
            total += i;
            stop = true;
        }
    }
    return total;
}

int main(){

    int sum = 0;

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

        int length = strlen(buf);
        int mid = length/2;

        char comp1[length];
        int i, k;
        for(i=0; i < mid; i++){
            comp1[i] = buf[i];
        }
        comp1[i] = '\0';

        char comp2[length];
        for(i = mid, k=0; i < length; i++, k++ ){
            comp2[k] = buf[i];
        }
        comp2[k] = '\0';

        bool stop = false;
        for(i=0; i<strlen(comp1) && !stop; i++){
            int j;
            for(j=0; j<strlen(comp2) && !stop; j++){
                if(comp1[i] == comp2[j]){
                    sum += calcPriority(comp2[j]);
                    stop = true;
                }
            }

        }

        /*
            - Capture line in variable
            - slit line into two variables. Compartment 1 and compartment 2
            - loop through each char in compartment 1
            - - loop through each char in compartment 2 
            - - - compare comparemnt 1 char to each in compartment 2
            - - - if we find a match then record item
            - - - - Add item to array
            - - - - break loop
            - Map alphabet to an array of numbers 0-52 
        */

        
    }

    printf("sum = %i\n", sum);
    

    // Close the file
    fclose(file);
    
    return 0;
}

