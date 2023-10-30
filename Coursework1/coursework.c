#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() 
{
    
    char dataline[] = "2023-09-01,12:15,270"; //must take first 3 lines from csv file
    char my_delimiter = ',';

    char my_date[11];
    char my_time[6];
    char my_steps[8];

    tokeniseRecord(dataline, &my_delimiter, my_date, my_time, my_steps);

    printf("%s/%s/%s\n", my_date, my_time, my_steps); //outputs in correct format


    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        perror("");
        return 1;
    }

    int size = 21;
    char line[size];
    int count = 0;
    int i = 0;

    while(fgets(line, size, file) != NULL)
    {
        
    }

    printf("Number of records in file: %d", count);

    fclose(file);
    return 0;
}