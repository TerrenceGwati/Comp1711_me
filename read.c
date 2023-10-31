#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file;

    file = fopen("squares.dat", "r");

    if (file == NULL)
    {
        perror("error");
        return 1;
    }
    
    int buffer_size = 10;
    char line_buffer[buffer_size];
    int counter = 0;
    float sum;

    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        sum += atoi(line_buffer);
        counter++;
    }

    printf("Your average is: %.2f\n", sum / counter);



    fclose(file);
    return 0;
}