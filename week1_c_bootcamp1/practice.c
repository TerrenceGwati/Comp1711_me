#include <stdio.h>

int main(void)
{
    int length;
    int width;

    printf("What is the length of first side: ");
    scanf("%i", &length);

    printf("what is the length of second side: ");
    scanf("%i", &width);
    

    int area = length * width;

    printf("The area of the rectangle is %i.\n", area);

    return 0;
}


