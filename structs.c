#include <stdio.h>

struct student { //student is not a variable.
    char name [20];
    char student_id [11]; // Assuming up to 10 digits.
    unsigned mark;
};

int main () 
{
struct student new_student = {.name = "Terrence Gwatipedza",//the .<fieldname> is used to initialise individual fields:
                              .student_id = "28932123",
                              .mark = 35};
printf("Student name: %s\n", new_student.name);
printf("Student ID: %s\n", new_student.student_id);
printf("Final mark: %u\n", new_student.mark);
return 0;
}