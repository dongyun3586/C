#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int userchoice;
    printf("�ȳ��ϼ���. ��õ���Դϴ�.\n");
    printf("���� ��� �� �� ������ �����ϼ���.\n");
    printf("1. ������ Ǯ��   2. ���� ã��   3. BMI   4. ���� 99��   5. GSA38   6. ��õ�� ������ ����"); //��� ������ Ǯ�̰� ���� �ֿ��� ����̴�.
    scanf("%d", &userchoice); //�� �Է¹ޱ�
    if (userchoice == 1) // ������ Ǯ��
    {
        printf("\n\n���� ��� ������ Ǯ��\n");
        int deg;
        printf("�������� ������ �Է����ּ��� (1, 2, 3) : ");
        scanf("%d", &deg);
        if (deg == 1) //���� 1���� ��
        {
            int Ii, Io;
            float Ix;
            printf("\nAx + B = 0   :   A, B = ");
            scanf("%d, %d", &Ii, &Io); //���������� �Է� �ޱ�
            if (Ii == 0)
                printf("������������ �ƴմϴ�.\n");
            else
            {
                Ix = (float)Io / Ii * (-1); //���������� �� ���ϰ� ���
                printf("x = %.4f", Ix);
            }
        }
        else if (deg == 2) //���� 2���� ��
        {
            int IIii, IIi, IIo; //���� 2,147,483,647 (2^31 -1) ������ int������ ����
            float IIxi, IIxii; //math.h�� sqrt �Լ��� ����ϹǷ� float������ ����
            long long IId; // �Ǻ��Ŀ� ������ �����Ƿ� ���� 9,223,372,036,854,775,807 (2^63 -1) ������ long long���� ����
            printf("\nAx^2 + Bx + C = 0   :   A, B, C = ");
            scanf("%d, %d, %d", &IIii, &IIi, &IIo); //���������� �Է¹ޱ�
            if (IIii == 0)
                printf("������������ �ƴմϴ�.\n");
            else
            {
                IId = (long long)IIi * IIi - 4 * (long long)IIii * IIo; //������������ �Ǻ���
                if (IId > 0) //�Ǻ��� 0�ʰ�, ���� �ٸ� �� �Ǳ�
                {
                    IIxi = (-IIi + sqrt(IId)) / (2 * IIii); //ù ��° ��
                    IIxii = (-IIi - sqrt(IId)) / (2 * IIii);// �� ��° ��
                    printf(" x = %.6f\n", IIxi);
                    printf(" x = %.6f\n", IIxii);
                }
                else if (IId == 0) //�Ǻ��� 0, �߱�(�Ǳ�)
                    printf(" x = %.6f\n (�߱�)\n ", (-IIi) / (2 * IIii));
                else
                {
                    printf("������������ �Ǳ��� �������� �ʽ��ϴ�.\n���Ҽ��� : \n"); //�Ǳ��� �ƴ� ���Ҽ� ������ ����
                    printf(" x = %.6f + %.6fi\n x = %.6f - %.6fi\n", (-0.5) * IIi / IIii, sqrt((-1) * IId), (-0.5) * IIi / IIii, sqrt((-1) * IId));
                }
            }
        }
        else if (deg == 3)//���� 3���� ��
        {
            int IIIiii, IIIii, IIIi, IIIo;
            float IIIx, IIIA, IIIB, IIIDa, IIIDb; //�߰� ��� ������ �ʿ��� ������
            long long IIIX, IIIY, IIIZ;
            printf("\nAx^3 + Bx^2 + Cx + D = 0   :   A, B, C, D = ");
            scanf("%d, %d, %d, %d", &IIIiii, &IIIii, &IIIi, &IIIo);
            if (IIIiii == 0)
                printf("������������ �ƴմϴ�.\n");
            else
            {
                printf("%dx^3 + %dx^2 + %dx + %d = 0\n", IIIiii, IIIii, IIIi, IIIo);
                IIIX = 2 * pow(IIIii, 3) - 9 * IIIiii * IIIii * IIIi + 27 * pow(IIIiii, 2) * IIIo;
                IIIY = pow(IIIii, 2) - 3 * IIIiii * IIIo;
                IIIZ = pow(IIIX, 2) - 4 * pow(IIIY, 3);
                IIIDa = IIIX + sqrt(IIIZ);
                IIIDb = IIIX - sqrt(IIIZ);
                if (IIIDa >= 0) //���� ���� �� �ʿ��� IIIA�� �� ����, IIIDa�� ���������� �Ϸ��� ������ cbrt�Լ��� ���� ����� for������ �������.
                {
                    for (IIIA = 0.000000f; IIIA < 2642245.949629f; IIIA += 0.000001f) // IIIDa�� IIIZ�� �̿��߰�, IIIZ�� IIIY^3�� ������ �ִ�.
                    {
                        if (pow(IIIA, 3) >= IIIDa)break;
                    }
                }
                if (IIIDa < 0)
                {
                    for (IIIA = 0.000000f; IIIA > -2642245.949629f; IIIA -= 0.000001f) // ���� long long int�� ������ 2^63 - 1�� ���������� 2642245.949629���� �õ��Ѵ�.
                    {
                        if (pow(IIIA, 3) <= IIIDa)break;
                    }
                }
                if (IIIDb >= 0)//���� ���� �� �ʿ��� IIIB�� �� ����, IIIDb�� ���������̴�.
                {
                    for (IIIB = 0.000000f; IIIB < 2642245.949629f; IIIB += 0.000001f)
                    {
                        if (pow(IIIB, 3) >= IIIDb)break;
                    }
                }
                if (IIIDb < 0)
                {
                    for (IIIB = 0.000000f; IIIB > -2642245.949629f; IIIB -= 0.000001f)
                    {
                        if (pow(IIIB, 3) <= IIIDb)break; // �� break���� ����Ͽ� for���� ������ �׶��� ���� IIIA�� IIIB�� ������ �����Ѵ�.
                    }
                }
                IIIx = (IIIA + IIIB + IIIii) / ((-3.000000) * IIIiii);
                printf(" x = %.6f\n", IIIx); //������������ �� �Ǳ��� ����Ѵ�. ���Ŀ� ���� �ݵ�� �Ǳ��̾�� �ϴ� ������ ����ϹǷ� �� �Ǳ��� ������ ���������Ŀ����� �� ���α׷��� ���� �μ����ظ� ������ �� �ְ� �Ѵ�.
            }
        }
        else
            printf("�ٸ� ���� �Է����ּ���"); //1, 2, 3���������� �ƴϸ� ���α׷��� �������� �ʴ´�.
    }
    if (userchoice == 2) //�ֱ���ǥ ���
    {
        printf("\n\n");
        printf("     1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18 \n");
        printf(" 1   H                                                                   He \n");
        printf(" 2   Li  Be                                          B   C   N   O   F   Ne \n");
        printf(" 3   Na  Mg                                          Al  Si  P   S   Cl  Ar \n");
        printf(" 4   K   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr \n");
        printf(" 5   Rb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  An  Te  I   Xe \n");
        printf(" 6   Cs  Ba  *   Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn \n");
        printf(" 7   Fr  Ra  **  Rf  Db  Sg  Bh  Hs  Mt  Ds  Rg  Cn  Nh  Fl  Mc  Lv  Ts  Of \n\n");
        printf("      *  La  Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er  Tm  Yb  Lu\n");
        printf("     **  Ac  Th  Pa  U   Np  Pu  Am  Cm  Bk  Cf  Es  Fm  Md  No  Lr\n");
    }
    if (userchoice == 3) // BMI ���
    {
        float height, weight, mheight, bmi;
        printf("\n\nBMI(��ü��������) ���\n");
        printf("Ű(cm) : ");
        scanf("%f", &height);
        printf("������(kg) : ");
        scanf("%f", &weight); // Ű, ������ �Է� ����

        mheight = height / 100; // mheight = meter height, Ű�� ���� ������ ��Ÿ��
        bmi = weight / (mheight * mheight);
        if (bmi < 18.5)
            printf("BMI : %.3f, ��ü���Դϴ�. ���� ü�� ������ %.2f ~ %.2f kg �Դϴ�.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else if (bmi >= 18.5 && bmi < 23)
            printf("BMI : %.3f, �����Դϴ�. ���� ü�� ������ %.2f ~ %.2f kg �Դϴ�.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else if (bmi >= 23 && bmi < 25.5)
            printf("BMI : %.3f, ��ü���Դϴ�. ���� ü�� ������ %.2f ~ %.2f kg �Դϴ�.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else if (bmi >= 25.5 && bmi < 30)
            printf("BMI : %.3f, �浵���Դϴ�. ���� ü�� ������ %.2f ~ %.2f kg �Դϴ�.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else
            printf("BMI : %.3f, ���Դϴ�. ���� ü�� ������ %.2f ~ %.2f kg �Դϴ�.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
    }
    if (userchoice == 4) // ���� 99�� ����, �����ð��� ��վ �����ϰ� �Ǿ���.
    {
        printf("���� 99�� ����\n");
        srand(time(NULL)); // ������ �������� ����
        int dan, i, jungdap, userdap, n, count = 0;
        printf("������ �� ����? \n");
        scanf("%d", &n);
        for (int a = 0; a < n; a++)
        {
            dan = rand() % 90 + 10; // ���ϴ� �� ���� ���� 10���� 99������ ���ڸ� �ڿ����� �Ѵ�.
            i = rand() % 90 + 10;
            jungdap = dan * i;
            printf("%d * %d = ", dan, i);
            scanf("%d", &userdap);
            if (jungdap == userdap)
            {
                printf("�¾ҽ��ϴ�. \n");
                count++;
            }
            else
                printf("Ʋ�Ƚ��ϴ�. ������ %d�Դϴ�.\n", jungdap);
        }
        printf("%d ���� �� %d ���� �������ϴ�.", n, count);
    }
    if (userchoice == 5) //GSA38 ���
    {
        int pick;
        printf("38�� �л� ���\n");
        printf("�� ��� =  1~6, ��ü ��� = 7  : \n");
        scanf("%d", &pick);
        if (pick == 7)
            printf("GSA38 ��� (99��)\n\n");
        if (pick == 1 || pick == 7)
            printf("1-1 (17��)  |  ���� : ������T\n������, ������, ����, ��  ��, �赿��, ���ֿ�, ���¿�, ������\n������, ������, ������, ����ȯ, �̴ٿ�, ���¿�, ����ȣ, ������, �ѹμ�\n\n");
        if (pick == 2 || pick == 7)
            printf("1-2 (16��)  |  ���� : ������T\n���ȫ, �赿��, �����, ������, �����, ������, ������, �ŵ���\n������, ������, ������, ������, ������, �Ӱ���, ������, ������\n\n");
        if (pick == 3 || pick == 7)
            printf("1-3 (17��)  |  ���� : ������T\n������, �ǵ���, ��Թ�, ����, ������, ������, ���μ�, ���ؿ�\n���ؽ�, ���Ϲ�, �̽���, ��ä��, ��ȣ��, ������, �߼���, ������, ��  ��\n\n");
        if (pick == 4 || pick == 7)
            printf("1-4 (16��)  |  ���� : �ֿ뼮T\n�赵��, �赵��, �����, �輺��, �����, ������, ���ؼ�, ���ػ�\n���ϴ�, ���缺, ������, ������, ������, ������, �����, ����\n\n");
        if (pick == 5 || pick == 7)
            printf("1-5 (16��)  |  ���� : ����ȣT\n�����, �躸��, ������, ������, �迭��, ������, ���º�, ������\n�ӽ¹�, ������, ������, �����, �ֿ���, ������, Ȳ����, Ȳ���¿�\n\n");
        if (pick == 6 || pick == 7)
            printf("1-6 (17��)  |  ���� : �ֺ���T\n�����, �����, �赿��, �輺��, ��ÿ�, �迵��, ������, ������\n������, �۸���, ������, �ӿ���, ������, ������, ������, ������, ������\n\n");
    }
    if (userchoice == 6)// �׳� ���� ������ �ְ� �;���
    {
        printf("\n ������ ���� \n");
        printf(" 1412 ������ / GSA38 / 21073 / ��õ / �ø��콺");
    }
}
