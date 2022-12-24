// https://adventofcode.com/2022/day/1
// find which elf is carrying most calories

#include <stdio.h>

struct leaderboardEntry {
    int calories;
    int elfNumber;
};

void updateLeaderboard(int calorieCount, int elfNumber, struct leaderboardEntry *leaderboard){
    
    int i;
    for( i = 0; i < 3; i++){
        
        if(calorieCount > leaderboard[i].calories){
            leaderboard[i+1] = leaderboard[i];
            leaderboard[i].calories = calorieCount;
            leaderboard[i].elfNumber = elfNumber;
        }
        
    }
    
}
    
int main(){
    
    int currentCaloriesCount= 0;
    int elfNumber= 0;
    struct leaderboardEntry leaderboard[3]= {{0, 0}, {0, 0}, {0, 0}};
    int elfWithLargestCalories= -1;
    
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
        
        int calories;
        
        if(sscanf(buf, "%d", &calories) == 1){
            
            currentCaloriesCount+= calories;
            
        } else {
           
           updateLeaderboard(currentCaloriesCount, elfNumber, leaderboard); 
            
            // reset calorie counter for next elf
            currentCaloriesCount = 0;
            elfNumber++;
    
        }
    }
    
    // Close the file
    fclose(file);

    printf("Elf with the largest calories = %d, with %d Calories!\n", leaderboard[0].elfNumber, leaderboard[0].calories);
    
    int totalCaloriesTop3Elves= leaderboard[0].calories + leaderboard[1].calories + leaderboard[2].calories;
    
    printf("Top 3 largest calorie carrying elfs, have a total of %d calories\n", totalCaloriesTop3Elves);
    
    return 0;
}

