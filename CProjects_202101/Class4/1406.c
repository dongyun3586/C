#include <stdio.h>
#include <math.h> //(pow)를 사용하기 위해서

double firstorderequation(int a, int b);
double secondorderequationone(int a, int b, int c);//이차방정식의 첫번째 근
double secondorderequationtwo(int a, int b, int c);//이차방정식의 두번째 근
void imaginarynumber(int a, int b, int c);  //이차방정식의 허근
void thirdorderequation(int a, int b, int c, int d);
double squarecube(double n);//세제곱근 구하기

int main() {
    int n;
    printf("몇차 방정식을 원하시나요??(3차 이하):");
    scanf("%d", &n);

    switch (n) {
    case (1):
    {
        int a, b;
        printf("ax+b=0꼴로 a b:");
        scanf("%d %d", &a, &b);
        printf("x = %f", firstorderequation(a, b));
        break;
    }
    case (2):
    {
        int a, b, c;
        printf("ax^2+bx+c=0꼴로 a b c:");
        scanf("%d %d %d", &a, &b, &c);
        if (b * b - 4 * a * c > 0)
        {
            printf("x1 = %lf\n", secondorderequationone(a, b, c));
            printf("x2 = %lf\n", secondorderequationtwo(a, b, c));
            break;
        }
        else if (b * b - 4 * a * c == 0)
        {
            printf("중근입니다.\n");
            printf("%lf", secondorderequationone(a, b, c));
            break;
        }
        else
        {
            printf("허근입니다.\n");
            imaginarynumber(a, b, c);

            break;
        }

    }
    case (3):
    {
        int a, b, c, d;
        printf("ax^3 + bx^2 + cx + d = 0 꼴로 a b c d:");
        scanf("%d %d %d %d", &a, &b, &c, &d);
        thirdorderequation(a, b, c, d);
        break;
    }
    default:
    {
        printf("니가 해");
        break;
    }
    }
}

double firstorderequation(int a, int b)
{
    float x;
    x = -((float)b / a);
    return x;

}
double secondorderequationone(int a, int b, int c)
{
    double x1;
    x1 = (-b + sqrt(pow(b, 2) - (double)4 * a * c)) / ((double)2 * a);
    return x1;
}
double secondorderequationtwo(int a, int b, int c)
{
    double x2;
    x2 = (-b - sqrt(pow(b, 2) - 4 * (double)a * c)) / ((double)2 * a);
    return x2;
}
void imaginarynumber(int a, int b, int c)
{
    double alpha, alphai;
    alpha = -(double)b / (2 * a);
    alphai = sqrt((double)4 * a * c - pow(b, 2)) / (2 * a);

    printf("실근=%lf\n허근=%lf", alpha, alphai);
}
void thirdorderequation(int a, int b, int c, int d)
{
    //카르다노의 방법으로 구한다.
    //y^3+m*y+n=0
    double m, n;
    double p, q;
    m = (-pow(b, 2) + (double)3 * a * c) / (3 * pow(a, 2));
    n = (2 * (double)pow(b, 3) - (double)9 * a * b * c + 27 * (double)pow(a, 2) * d) / ((double)27 * pow(a, 3));
    //printf("m=%lf \nn=%lf\n", m, n);

    p = n * n + 4 * pow(m, 3) / 27;
    // printf("p=%lf\n", p);
    if (p >= 0)
    {
        p = (n - sqrt(n * n + 4 * pow(m, 3) / 27)) / 2; //원래 p를 쓸려고 했는데 값이 잘려서 그대로 넣었다.
        q = (n + sqrt(n * n + 4 * pow(m, 3) / 27)) / 2;

        double alpha;
        double beta, betaparti;

        //printf("%d\n", squarecube(p));
        alpha = -(double)b / ((double)3 * a) + squarecube((n - sqrt(n * n + 4 * pow(m, 3) / 27)) / 2) + squarecube((n + sqrt(n * n + 4 * pow(m, 3) / 27)) / 2);
        beta = -(double)b / ((double)3 * a) - 0.5 * (squarecube((n - sqrt(n * n + 4 * pow(m, 3) / 27)) / 2) + squarecube((n + sqrt(n * n + 4 * pow(m, 3) / 27)) / 2));
        betaparti = sqrt(3) * squarecube((n - sqrt(n * n + 4 * pow(m, 3) / 27)) / 2) * 0.5 - sqrt(3) * squarecube((n + sqrt(n * n + 4 * pow(m, 3) / 27)) / 2) / 2;


        printf("*첫번째 근*\n");
        printf("%lf\n", alpha);
        printf("*두번째 근*\n");
        printf("실수:%lf    허수:%lf\n", beta, betaparti);
        printf("*세번째 근* \n");
        printf("실수:%lf    허수:%lf", beta, -betaparti);


    }
    else
    {
        printf("이건 계산 불가능 입니다.ㅠㅠ");
    }
}



double squarecube(double n)
{
    if (n < 0)
    {
        n = -n;
    }

    double num = 100.0, temp;
    double a = 0;

    for (int i = 0; i < (int)sqrt(n); i++)
    {

        for (int j = 1; j <= 1000; j++)
        {
            temp = pow((double)i + (float)j / 1000, 3) - n;

            if (temp < 0)
            {
                temp = -temp;
            }
            if (temp <= num)
            {

                num = temp;
                a = i + (double)j / 1000;
            }

        }
    }
    if (n >= 0)
    {
        return a;
    }
    else
    {
        return -a;
    }

}


