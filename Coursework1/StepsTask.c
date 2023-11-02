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

//Main Function
int main() 
{
    //Open file to read
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        perror("");
        return 1;
    }

    char line_count[24]; //For counting records
    int record_num = 0;

    //Counts number of records in file
    while(fgets(line_count, 24, file) != NULL)
    {
        record_num = record_num + 1;
    }
    printf("Number of records in file: %d\n", record_num);

    //Close file, so can use another fgets
    fclose(file);

    //Open file to use fgets again
    char filename_2 [] = "FitnessData_2023.csv";
    FILE *file_2 = fopen(filename_2, "r");
    if(file_2 == NULL)
    {
        perror("");
        return 1;
    }

    //Prints out first 3 lines
    for(int i = 0; i < 3; i++)
    {
        char dataline [24]; //To store line from file

        //Gets first line from file, then 2nd, then 3rd
        fgets(dataline, 24, file_2);

        //For token function
        char my_delimiter = ',';
        char my_date[11];
        char my_time[6];
        char my_steps[8];
        //Runs token function
        tokeniseRecord(dataline, &my_delimiter, my_date, my_time, my_steps);
        //Prints in wanted format
        int step_2 = atoi(my_steps);
        printf("%s/%s/%d\n", my_date, my_time, step_2);
    }

    fclose(file_2);
    return 0;
}