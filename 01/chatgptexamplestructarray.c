#include <stdio.h>

// Define a struct with two fields
struct exampleStruct {
    int field1;
    int field2;
};

// Define a function that takes an array of exampleStruct instances as an argument
// and returns an updated array of exampleStruct instances
struct exampleStruct *updateStructArray(struct exampleStruct *structArray, int size){

    // Modify the structArray in-place
    int i;
    for(i = 0; i < size; i++){
        structArray[i].field1 = i;
        structArray[i].field2 = i * 2;
    }

    // Return the updated structArray
    return structArray;
}

int main(){

    // Create an array of exampleStruct instances
    struct exampleStruct structArray[3];

    // Initialize the structArray
    int i;
    for(i = 0; i < 3; i++){
        structArray[i].field1 = 0;
        structArray[i].field2 = 0;
    }

    // Call the updateStructArray function to update the structArray
    struct exampleStruct *updatedStructArray = updateStructArray(structArray, 3);

    // Print the values in the updated structArray
    for(i = 0; i < 3; i++){
        printf("structArray[%d].field1 = %d\n", i, updatedStructArray[i].field1);
        printf("structArray[%d].field2 = %d\n", i, updatedStructArray[i].field2);
    }

    return 0;
}