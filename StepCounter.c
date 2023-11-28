#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#define buffer_size 1000

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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



// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array

int main()
{

    // array of fitness data
    FITNESS_DATA fitness[1000];
    FILE *input = NULL;
  
    char line[buffer_size];
    char filename[buffer_size];
    char choice;
    int counter = 0;
    float mean = 0;
    float sum;
    int y = 0;
    int z = 1000;

    while (1)
    {
       

       printf("Menu options: \n");
       printf("A: Specify the filename to be imported-you need to check that the file opened correctly\n");
       printf("B: Display the total number of records in the file\n");
       printf("C: Find the date and time of the timeslot with the fewest steps\n");
       printf("D: Find the date and time for the timeslot with the largest number of steps\n");
       printf("E: Find the mean step count of all the records in the file\n");
       printf("F: Find the longest continuous period where the step count is above 500 steps\n");
       printf("Q: Quit\n");
   
        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':
            
            if (input != NULL) {
                    fclose(input); // Close the previous file if it's open
                }
                printf("Input filename: ");
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);

                input = fopen(filename, "r");
                if (!input) {
                    printf("Error: could not open file\n");
                    return 1;
                }
            
            counter = 0;
            while (fgets(line, buffer_size, input) != NULL)
            {
                // split up the line and store it in the right place
                char date[11];
                char time[6];
                char steps[10];
                tokeniseRecord(line, ",", date, time, steps);
                strncpy(fitness[counter].date, date, sizeof(fitness[counter].date)); //Got help from chat gpt
                strncpy(fitness[counter].time, time, sizeof(fitness[counter].time)); //got help from chat gpt
                fitness[counter].steps = atoi(steps);
                counter++;
            }
            fclose(input);
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", counter);
            
            break;

        case 'C':
        case 'c':
            for (int j = 0; j < counter; j++)
        {
            int x = fitness[j].steps;
            if (x < z)
            {
                z = x;  
            }
        }
        for (int k = 0; k < counter; k++)
        { 
            if (fitness[k].steps == z)
            {
                printf("Fewest steps: %s %s\n",
                       fitness[k].date,
                       fitness[k].time);
            }
        }
            
            break;

        case 'D':
        case 'd':
           for (int j = 0; j < counter; j++)
        {
            int x_2 = fitness[j].steps;
            if (x_2 > y)
            {
                y = x_2;  
            }
        }
        for (int k = 0; k < counter; k++)
        { 
            if (fitness[k].steps == y)
            {
                printf("Largest steps: %s %s\n",
                       fitness[k].date,
                       fitness[k].time);
            }
        }
            break;

        case 'E':
        case 'e':
             for (int i = 0; i < counter; i++)
             {
                sum += fitness[i].steps;
             }
            float mean = sum / counter;
            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
            break;

        
        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
