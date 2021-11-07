#include <stdio.h>
#include <string.h>

struct highschool
{
    int id;
    char name[50];
};

typedef struct
{
    int id;
    char name[20];
    float percentage;
    struct highschool hs_data;     // structure within structure
} student;

int main()
{
    student stu = { 1, "이동윤", 99.5, {1111, "광주과학고등학교"} };
    printf("Id is: %d \n", stu.id);
    printf("Name is: %s \n", stu.name);
    printf("Percentage is: %.1f \n\n", stu.percentage);
    printf("Highschool Id is: %d \n", stu.hs_data.id);
    printf("Highschool Name is: %s \n", stu.hs_data.name);
    return 0;
}