#include <stdio.h>

void printStudent(struct student s);

struct date
{
    int year;
    int month;
    int day;
};

struct student
{
    int sno;
    char name[20];
    struct date birthday;
};

void main()
{
    struct date d = { 2021, 10, 1 };
    struct student s1 = { 20210001, "ȫ�浿", d };
    printStudent(s1);

    struct student s2 = { 20210002, "��ö��", {2019, 9, 3} };
    printStudent(s2);

    return 0;
}

void printStudent(struct student s) {
    printf("�й�: %d\n", s.sno);
    printf("�̸�: %s\n", s.name);
    printf("�������: %d-%2d-%2d\n", s.birthday.year, s.birthday.month, s.birthday.day);
}

