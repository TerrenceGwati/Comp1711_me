#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

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
    char filename[1000];
    int buffer_size;
    char line[buffer_size];
    

    printf("Please enter the name of the data file: ");
    scanf("%s", filename);

    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error in opening file");
        return 1;
    }

   FITNESS_DATA fitness[100];
   
   int start_period = -1;
   int max_period;
   int counter;
   float sum = 0;
   int x;
   int y = 0;
   int z = 10000;
   int start;
   int end;
   int read;
   int records = 0;
   char letter;
   char input_file[1000];


       printf("Menu options: \n");
       printf("A: Specify the filename to be imported\n");
       printf("B: Display the total number of records in the file\n");
       printf("C: Find the date and time of the timeslot with the fewest steps\n");
       printf("D: Find the date and time for the timeslot with the largest number of steps\n");
       printf("E: Find the mean step count of all the records in the file\n");
       printf("F: Find the longest continuous period where the step count is above 500 steps\n");
       printf("Q: Quit\n");
   
   printf("Enter choice: ");
   scanf(" %c", &letter);
    
   switch(letter)
   {
      case 'A':
      case 'a':
        printf("Input filename: ");
        scanf("%s", input_file);

        FILE* new_file;
        new_file = fopen(input_file, "r");
        if (new_file == NULL)
        {
            printf("Error: could not open file.\n");
            return 1;
        }
        else
        {
            printf("File successfully loaded.\n");
        }
        break;

      case 'B':
      case 'b':
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
        printf("Total Records: %d\n", records);
        break;       
        
      case 'C':
      case 'c':
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
        for (int j = 0; j < records; j++)
        {
            int x = fitness[j].steps;
            if (x < z)
            {
                z = x;  
            }
        }
        for (int k = 0; k < records; k++)
        { 
            if (fitness[k].steps == z)
            {
                printf("%s,%s\n",
                       fitness[k].date,
                       fitness[k].time);
            }
        }
        break;

      case 'D':
      case 'd':
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
        for (int j = 0; j < records; j++)
        {
            int x = fitness[j].steps;
            if (x > y)
            {
                y = x;  
            }
        }
        for (int k = 0; k < records; k++)
        { 
            if (fitness[k].steps == y)
            {
                printf("%s,%s\n",
                       fitness[k].date,
                       fitness[k].time);
            }
        }

        
        break;

      case 'E':
      case 'e':
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
        for (int i = 0; i < records; i++)
        {
            sum += fitness[i].steps;
        }
        float mean = sum / records;
        printf("Mean step count: %.0f\n", mean);
        break;
        
      case 'F':
      case 'f':
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

        for (int l = 0; l < records; l++)
        {
             if (fitness[l].steps > 500)
             {
                if (start_period == -1)
                {
                    start_period = l;
                }
                counter++;
             }
             else
             {
                if (counter > max_period)
                {
                    max_period = counter;
                }
                counter = 0;
                start_period = -1;
             }
            
        }
        printf("%s,%s\n", fitness[start_period].date, fitness[start_period].time);
        break;

      case 'Q':
      case 'q':
        return 0;

      default:
        printf("Invalid choice. Try again.\n");   
      
    }

   fclose(file);
   return 0;
   
}

