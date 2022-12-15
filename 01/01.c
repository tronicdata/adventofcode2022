// https://adventofcode.com/2022/day/1
// find which elf is carrying most calories

#include <stdio.h>

int main(){
    
    /*
    int currentElf = 0; //keep track of elves
    int currentCaloriesCount = 0;
    int largestCalories=0;
    int elfWithLargestCalories=0;
    
    - read inputData file
    - while read line
    - - currentElf++ 
    - - currentCaloriesCount = 0;
    - - if line is number than add number to currentCalories
    - - - currentCalories = currentCalories + inputData(line)
    - - else if line blank
    - - - if currentCaloriesCount > largestCalories
    - - - - largestCalories = currentCaloriesCount
    - - - - elfWithLargestCalories = currentElf
    - - 
        
    
    */
    
    int currentElf = 1; //keep track of elves
    int currentCaloriesCount= 0;
    int largestCalories=0;
    int elfWithLargestCalories=0;
    
    // Open the file for reading
    FILE *file = fopen("inputData.txt", "r");
    
    // Check if the file was opened successfully
    if( file == NULL ){
        perror("Error opening file");
        return -1;
    }
    
    
    // Read the contents of the file line by line
    char buf[1024];
    while (fgets(buf, 1024, file) != NULL){
        
        
        int calories;
        
        if(sscanf(buf, "%d", &calories) == 1){
            
            // printf("%d\n", calories);
            
            currentCaloriesCount+= calories;
            
            // printf("CurrentCalorieCount=%d\n", currentCaloriesCount);
            
        } else {
            
            // printf("blank line\n");
            
            if( currentCaloriesCount > largestCalories ){
                largestCalories = currentCaloriesCount;
                elfWithLargestCalories = currentElf;
                
                printf("new largest calorie elf added! Elf number %d, with %d calories!\n", elfWithLargestCalories, largestCalories);
            } 
            
            // reset for next elf
            currentCaloriesCount = 0;
            currentElf++;
    
        }
    }
    
    // Close the file
    fclose(file);

    printf("Elf with the largest calories = %d, with %d Calories!\n", elfWithLargestCalories, largestCalories);
    
    return 0;
}