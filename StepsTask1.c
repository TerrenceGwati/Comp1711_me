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

    FITNESS_DATA fitness_data[100];
    
    
    int read;
    int num_of_records = 0;
    do
    {
       read = fscanf(file,                  //got help from youtube on how to read the date format and time(https://www.youtube.com/watch?v=rbVt5v8NNe8)
                     "%11[^,],%6[^,],%d\n",
                     fitness_data[num_of_records].date,
                     fitness_data[num_of_records].time,
                     &fitness_data[num_of_records].steps);

       if (read == 3);
       {
        num_of_records++;
       }

       if (read != 3 && !feof(file))
       {
        printf("Error in the format\n");
        return 1;
       }

       if (ferror(file))
       {
        printf("Error\n");
        return 1;
       }             
    } while(!feof(file));

    fclose(file);

    printf("Number of records in file: %d\n", num_of_records);
    
    for (int i = 0; i < 3; i++)
    {
        printf("%s/%s/%d\n",
               fitness_data[i].date,
               fitness_data[i].time,
               fitness_data[i].steps);
    }
    

    



}