#include<stdio.h>
int main() {
    printf("-----------------------------------------------------------------\n");
    printf("Instructions : �ȳ��� ���� ��, ���� ���������� �Է��ϼ���.\n");
    printf("-----------------------------------------------------------------\n\n\n");
    char f1, f2;
    char m1, m2;
    printf("-----------------------------------------------------------------\n");
    printf("�θ��� ABO�� �������� �Է��ϼ���.(AA, AB, AO, BB, BO, OO�� �ϳ�)\n");
    printf("��: ");
    scanf("%c%c", &f1, &f2);
    printf("��: ");
    scanf("%*c%c%c", &m1, &m2);
    printf("\n");

    printf("������ �ڳ��� ������:\n");
    int f = f1 + f2;
    int m = m1 + m2;

    if (f == 130 && m == 130) {
        printf("AA:1");
    }
    else if (f == 130 && m == 131) {
        printf("AA:1/2\nAB:1/2");
    }
    else if (f == 130 && m == 144) {
        printf("AA:1/2\nAO:1/2");
    }
    else if (f == 130 && m == 132) {
        printf("AB:1");
    }
    else if (f == 130 && m == 145) {
        printf("AA:1/2\nAB:1/2");
    }
    else if (f == 130 && m == 168) {
        printf("AA:1/2\nAB:1/2");
    }


    else if (f == 131 && m == 130) {
        printf("AA:1/2\nAB:1/2");
    }
    else if (f == 131 && m == 131) {
        printf("AA:1/4\nAB:1/2\nBB:1/4");
    }
    else if (f == 131 && m == 144) {
        printf("AA:1/4\nAB:1/4\nAO:1/4\nBO:1/4");
    }
    else if (f == 131 && m == 132) {
        printf("AB:1/2\nBB;1/2");
    }
    else if (f == 131 && m == 145) {
        printf("AB:1/4\nAO:1/4\nBB:1/4\nBO:1/4");
    }
    else if (f == 131 && m == 168) {
        printf("AO:1/2\nBO:1/2");
    }


    else if (f == 144 && m == 130) {
        printf("AA:1/2\nAO:1/2");
    }
    else if (f == 144 && m == 131) {
        printf("AA:1/4\nAB:1/4\nAO:1/4\nBO:1/4");
    }
    else if (f == 144 && m == 144) {
        printf("AA:1/2\nAO:1/2\n");
    }
    else if (f == 144 && m == 132) {
        printf("AB:1/2\nBO:1/2");
    }
    else if (f == 144 && m == 145) {
        printf("AB:1/4\nAO:1/4\nBO:1/4\nOO:1/4");
    }
    else if (f == 144 && m == 168) {
        printf("AO:1/2\nOO:1/2");
    }


    else if (f == 132 && m == 130) {
        printf("AB:1");
    }
    else if (f == 132 && m == 131) {
        printf("AB:1/2\nBB:1/4");
    }
    else if (f == 132 && m == 144) {
        printf("AB:1/2\nBO:1/2");
    }
    else if (f == 132 && m == 132) {
        printf("BB:1");
    }
    else if (f == 132 && m == 145) {
        printf("BB:1/2\nBO:1/2");
    }
    else if (f == 132 && m == 168) {
        printf("BO:1");
    }


    else if (f == 145 && m == 130) {
        printf("AB:1/2\nAO:1/2");
    }
    else if (f == 145 && m == 131) {
        printf("AB:1/4\nAO:1/4\nBB:1/4\nBO:1/4");
    }
    else if (f == 145 && m == 144) {
        printf("AB:1/4\nAO:1/4\nBO:1/4\nOO:1/4");
    }
    else if (f == 145 && m == 132) {
        printf("BB:1/2\nBO:1/2");
    }
    else if (f == 145 && m == 145) {
        printf("BB:1/4\nBO:1/2\nOO:1/4");
    }
    else if (f == 145 && m == 168) {
        printf("BO:1/2\nOO:1/2");
    }


    else if (f == 168 && m == 130) {
        printf("AO:1");
    }
    else if (f == 168 && m == 131) {
        printf("AO:1/2\nBO:1/2");
    }
    else if (f == 168 && m == 144) {
        printf("AO:1/2\nOO:1/2");
    }
    else if (f == 168 && m == 132) {
        printf("BO:1");
    }
    else if (f == 168 && m == 145) {
        printf("BO:1/2\nOO:1/2");
    }
    else if (f == 168 && m == 168) {
        printf("OO:1");
    }
    printf("\n-----------------------------------------------------------------\n\n\n");



    char fr1, fr2;
    char mr1, mr2;
    printf("-----------------------------------------------------------------\n");
    printf("�θ��� Rh�� �������� �Է��ϼ���.(++, +-, --�� �ϳ�)\n"); // ++ = 86, +- = 88, -- = 90
    printf("��: ");
    scanf("%*c%c%c", &fr1, &fr2);
    printf("��: ");
    scanf("%*c%c%c", &mr1, &mr2);
    printf("\n");
    printf("������ �ڳ��� ��������: \n");
    int fr = fr1 + fr2;
    int mr = mr1 + mr2;
    if (fr == 86 && mr == 86) {
        printf("Rh+: 1");
    }
    else if (fr == 86 && mr == 88) {
        printf("Rh+: 1");
    }
    else if (fr == 86 && mr == 90) {
        printf("Rh+: 1");
    }

    else if (fr == 88 && mr == 86) {
        printf("Rh+: 1");
    }
    else if (fr == 88 && mr == 88) {
        printf("Rh+: 3/4\nRh-: 1/4");
    }
    else if (fr == 88 && mr == 90) {
        printf("Rh+: 1/2\nRh-: 1/2");
    }

    else if (fr == 90 && mr == 86) {
        printf("Rh+: 1");
    }
    else if (fr == 90 && mr == 88) {
        printf("Rh+: 1/2\nRh-: 1/2");
    }
    else if (fr == 90 && mr == 90) {
        printf("Rh-: 1");
    }
    printf("\n-----------------------------------------------------------------\n");


    return 0;

}