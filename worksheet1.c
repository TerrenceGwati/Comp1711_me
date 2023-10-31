#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file;

    file = fopen("squares.dat", "w");

    if (file == NULL)
    {
        printf("Error\n");
        return 1;
    }

    


    printf("give me 5 positive integers: ");
    unsigned n;
    scanf("%u", &n);
     
    for (int i = 1; i <= n ; i++)
    {
    
        fprintf(file, "%d\n", i * i);

    }
    fclose(file);
    return 0;

}