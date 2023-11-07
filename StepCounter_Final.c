#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Struct moved to header file

#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H

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




// Complete the main function
int main() 
{
    FILE *file;
    file = fopen("FitnessData_2023.csv", "r");

    if (file == NULL)
    {
        printf("Error in opening file");
        return 1;
    }

   FITNESS_DATA fitness[100];
   int read;
   int records = 0;
   char letter;
   char input_file;
   printf("Menu options: \n");
   printf("A: Specify the filename to be imported\n");
   printf("B: Display the total number of records in the file\n");
   printf("C: Find the date and time of the timeslot with the fewest steps\n");
   printf("D: Find the date and time for the timeslot with the largest number of steps\n");
   printf("E: Find the mean step count of all the records in the file\n");
   printf("F: Find the longest continuous period where the step count is above 500 steps\n");
   printf("Q: Quit\n");
   
   printf("Enter choice: ");
   scanf("%c\n", &letter);

   if (letter == 'A')
   {
      printf("Input filename: ");
      scanf("%s", &input_file);
   }
   else if (letter == 'B')
   {
      do
      {
         read = fscanf(file,
                       "%11[^,],%6[^,],%d\n",
                       fitness[records].date,
                       fitness[records].time,
                       &fitness[records].steps);

        if (read == 3)
        {
            records+= 1;
        }

        else if (read != 3 && ferror(file) && !feof(file))
        {
            printf("Error going through record\n");
            return 1;

        }               
      } while (!feof(file));
      printf("Total records: %d\n", records);
      
   }


   fclose(file);
   return 0;
   
}

