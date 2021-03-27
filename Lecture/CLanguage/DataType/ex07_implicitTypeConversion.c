#include <stdio.h>

int main_ex07_implicitTypeConversion()
{
#pragma region �ڷ��� Ȯ��(type promotion)
    // 1. int�� float �ڷ����� ���� ��� => �Ǽ�
    int num1 = 11;
    float num2 = 4.4f;

    printf("%f\n", num1 + num2);    // 15.400000: ������ �Ǽ� ����. ������ �Ǽ��� ��ȯ��
    printf("%f\n", num1 - num2);    // 6.600000: ������ �Ǽ� ����. ������ �Ǽ��� ��ȯ��
    printf("%f\n", num1 * num2);    // 48.400002: ������ �Ǽ� ����. ������ �Ǽ��� ��ȯ��
    printf("%f\n", num1 / num2);    // 2.500000: ������ �Ǽ� ������. ������ �Ǽ��� ��ȯ��

    // 2. int�� long long int �ڷ����� ���� ��� => long long ��
    long long num3 = 123456789000;
    int num4 = 10;

    printf("%lld\n", num3 + num4);    // 123456789010
    printf("%lld\n", num3 - num4);    // 123456788990
    printf("%lld\n", num3 * num4);    // 1234567890000
    printf("%lld\n", num3 / num4);    // 12345678900
#pragma endregion

#pragma region �ڷ��� ���(type demotion)
    //// 3. float �ڷ������� int�� ������ ���� => int������ ��ȯ��.
    //float num1 = 11.0f;
    //float num2 = 5.0f;

    //int num3 = num1 / num2;    // �Ǽ����� �Ǽ��� ������ 2.2�� �������� 
    //                           // ���� �ڷ������� 2�� ����ǰ� 0.2�� ������

    //printf("%d\n", num3);    // 2

    //// 4. int �ڷ��� ���� char �ڷ����� ���� => char������ ��ȯ��.
    //char num4 = 28;
    //int num5 = 1000000002;

    //char num6 = num4 + num5;    // char���� ū ���ڴ� ������ �� ����
    //                            // 28 + 2�� ���� �� �ڸ����� ������

    //printf("%d\n", num6);    // 30
#pragma endregion

    return 0;
}