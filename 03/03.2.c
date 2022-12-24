// https://adventofcode.com/2022/day/2
// Calculate Rock Paper Scissors Strategy

#include <stdio.h>
#include <stdlib.h>
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
    char *elf1;
    char *elf2;
    char *elf3;
    int elfCount = 1;

    elf1 = (char*) malloc(100);
    elf2 = (char*) malloc(100);
    elf3 = (char*) malloc(100);

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

        if( elfCount % 3 == 0 ){
            elf3 = (char *) realloc(elf3, length);
            strcpy(elf3, buf);

            bool stop = false;
            int i;
            for(i=0; i<strlen(elf1) && !stop; i++){
                int j;
                for(j=0; j<strlen(elf2) && !stop; j++){
                    if(elf1[i] == elf2[j]){
                        int k;
                        for(k=0; k<strlen(elf3) && !stop; k++){
                            if(elf2[j] == elf3[k]){
                                sum += calcPriority(elf3[k]);
                                stop = true;
                            }
                        }
                    }
                }

            }


        } else if(elfCount % 2 == 0) {
            elf2 = (char *) realloc(elf2, length);
            strcpy(elf2, buf);
            
        } else {
            elf1 = (char *) realloc(elf1, length);
            strcpy(elf1, buf);
        }

        elfCount++;
        
    }

    free(elf1);
    free(elf2);
    free(elf3);

    printf("sum = %i\n", sum);
    

    // Close the file
    fclose(file);
    
    return 0;
}

