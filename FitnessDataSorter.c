#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() 
{
    FitnessData fitness[100];
    char input_file[90];
    int read;
    int records;
    printf("Enter filename: ");
    scanf("%s", input_file);

    FILE* file = fopen(input_file, "r");
    
    if (file == NULL)
    {
        printf("Error in opening file\n");
        return 1;
    }

    do 
    {
        read = fscanf(file, 
                      "%11[^,],%6[^,],%d\n",
                      fitness[records].date,
                      fitness[records].time,
                      &fitness[records].steps);

        if (read == 3 && !feof(file))
        {
            records++;
        }
        else if (read != 3 && EOF)
        {
           printf("Error: invalid file.\n");
        }              

    } while(!feof(file));

    fclose(file);

    //qsort(fitness, records, sizeof(FitnessData));

    
}