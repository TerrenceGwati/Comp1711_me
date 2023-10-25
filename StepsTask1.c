#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct 
{
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) 
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) 
    {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) 
    {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) 
    {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main()
{
    FILE *file;

    file = fopen("FitnessData_2023.csv", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    FITNESS_DATA fitness_data[120];

    int read = 0;
    int num_of_records = 0;
    do
    {
       read = fscanf(file,
                     "%c,%c,%d\n",
                     fitness_data[num_of_records].date,
                     &fitness_data[num_of_records].time,
                     &fitness_data[num_of_records].steps);
    } while (!feof(file));
    



}