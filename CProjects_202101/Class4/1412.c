#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int userchoice;
    printf("안녕하세요. 수천봇입니다.\n");
    printf("다음 기능 중 한 가지를 선택하세요.\n");
    printf("1. 방정식 풀이   2. 원소 찾기   3. BMI   4. 랜덤 99단   5. GSA38   6. 수천봇 제작자 정보"); //사실 방정식 풀이가 가장 주요한 기능이다.
    scanf("%d", &userchoice); //수 입력받기
    if (userchoice == 1) // 방정식 풀이
    {
        printf("\n\n정수 계수 방정식 풀이\n");
        int deg;
        printf("방정식의 차수를 입력해주세요 (1, 2, 3) : ");
        scanf("%d", &deg);
        if (deg == 1) //차수 1차일 때
        {
            int Ii, Io;
            float Ix;
            printf("\nAx + B = 0   :   A, B = ");
            scanf("%d, %d", &Ii, &Io); //일차방정식 입력 받기
            if (Ii == 0)
                printf("일차방정식이 아닙니다.\n");
            else
            {
                Ix = (float)Io / Ii * (-1); //일차방정식 근 구하고 출력
                printf("x = %.4f", Ix);
            }
        }
        else if (deg == 2) //차수 2차일 때
        {
            int IIii, IIi, IIo; //범위 2,147,483,647 (2^31 -1) 까지인 int형으로 설정
            float IIxi, IIxii; //math.h의 sqrt 함수를 사용하므로 float형으로 설정
            long long IId; // 판별식에 제곱이 있으므로 범위 9,223,372,036,854,775,807 (2^63 -1) 까지의 long long으로 설정
            printf("\nAx^2 + Bx + C = 0   :   A, B, C = ");
            scanf("%d, %d, %d", &IIii, &IIi, &IIo); //이차방정식 입력받기
            if (IIii == 0)
                printf("이차방정식이 아닙니다.\n");
            else
            {
                IId = (long long)IIi * IIi - 4 * (long long)IIii * IIo; //이차방정식의 판별식
                if (IId > 0) //판별식 0초과, 서로 다른 두 실근
                {
                    IIxi = (-IIi + sqrt(IId)) / (2 * IIii); //첫 번째 근
                    IIxii = (-IIi - sqrt(IId)) / (2 * IIii);// 두 번째 근
                    printf(" x = %.6f\n", IIxi);
                    printf(" x = %.6f\n", IIxii);
                }
                else if (IId == 0) //판별식 0, 중근(실근)
                    printf(" x = %.6f\n (중근)\n ", (-IIi) / (2 * IIii));
                else
                {
                    printf("이차방정식의 실근이 존재하지 않습니다.\n복소수근 : \n"); //실근이 아닌 복소수 근으로 존재
                    printf(" x = %.6f + %.6fi\n x = %.6f - %.6fi\n", (-0.5) * IIi / IIii, sqrt((-1) * IId), (-0.5) * IIi / IIii, sqrt((-1) * IId));
                }
            }
        }
        else if (deg == 3)//차수 3차일 때
        {
            int IIIiii, IIIii, IIIi, IIIo;
            float IIIx, IIIA, IIIB, IIIDa, IIIDb; //중간 계산 과정에 필요한 변수들
            long long IIIX, IIIY, IIIZ;
            printf("\nAx^3 + Bx^2 + Cx + D = 0   :   A, B, C, D = ");
            scanf("%d, %d, %d, %d", &IIIiii, &IIIii, &IIIi, &IIIo);
            if (IIIiii == 0)
                printf("삼차방정식이 아닙니다.\n");
            else
            {
                printf("%dx^3 + %dx^2 + %dx + %d = 0\n", IIIiii, IIIii, IIIi, IIIo);
                IIIX = 2 * pow(IIIii, 3) - 9 * IIIiii * IIIii * IIIi + 27 * pow(IIIiii, 2) * IIIo;
                IIIY = pow(IIIii, 2) - 3 * IIIiii * IIIo;
                IIIZ = pow(IIIX, 2) - 4 * pow(IIIY, 3);
                IIIDa = IIIX + sqrt(IIIZ);
                IIIDb = IIIX - sqrt(IIIZ);
                if (IIIDa >= 0) //근을 구할 때 필요한 IIIA의 값 설정, IIIDa의 세제곱근을 하려고 했으나 cbrt함수가 없는 관계로 for문으로 만들었다.
                {
                    for (IIIA = 0.000000f; IIIA < 2642245.949629f; IIIA += 0.000001f) // IIIDa는 IIIZ를 이용했고, IIIZ는 IIIY^3을 가지고 있다.
                    {
                        if (pow(IIIA, 3) >= IIIDa)break;
                    }
                }
                if (IIIDa < 0)
                {
                    for (IIIA = 0.000000f; IIIA > -2642245.949629f; IIIA -= 0.000001f) // 따라서 long long int의 범위인 2^63 - 1의 세제곱근인 2642245.949629까지 시도한다.
                    {
                        if (pow(IIIA, 3) <= IIIDa)break;
                    }
                }
                if (IIIDb >= 0)//근을 구할 때 필요한 IIIB의 값 설정, IIIDb의 세제곱근이다.
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
                        if (pow(IIIB, 3) <= IIIDb)break; // 이 break문을 사용하여 for문을 나가고 그때의 값을 IIIA와 IIIB의 값으로 설정한다.
                    }
                }
                IIIx = (IIIA + IIIB + IIIii) / ((-3.000000) * IIIiii);
                printf(" x = %.6f\n", IIIx); //삼차방정식의 한 실근을 출력한다. 공식에 의해 반드시 실근이어야 하는 값만을 출력하므로 세 실근을 가지는 삼차방정식에서는 이 프로그램을 통해 인수분해를 진행할 수 있게 한다.
            }
        }
        else
            printf("다른 수를 입력해주세요"); //1, 2, 3차방정식이 아니면 프로그램을 진행하지 않는다.
    }
    if (userchoice == 2) //주기율표 출력
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
    if (userchoice == 3) // BMI 계산
    {
        float height, weight, mheight, bmi;
        printf("\n\nBMI(신체질량지수) 계산\n");
        printf("키(cm) : ");
        scanf("%f", &height);
        printf("몸무게(kg) : ");
        scanf("%f", &weight); // 키, 몸무게 입력 받음

        mheight = height / 100; // mheight = meter height, 키를 미터 단위로 나타냄
        bmi = weight / (mheight * mheight);
        if (bmi < 18.5)
            printf("BMI : %.3f, 저체중입니다. 정상 체중 범위는 %.2f ~ %.2f kg 입니다.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else if (bmi >= 18.5 && bmi < 23)
            printf("BMI : %.3f, 정상입니다. 정상 체중 범위는 %.2f ~ %.2f kg 입니다.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else if (bmi >= 23 && bmi < 25.5)
            printf("BMI : %.3f, 과체중입니다. 정상 체중 범위는 %.2f ~ %.2f kg 입니다.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else if (bmi >= 25.5 && bmi < 30)
            printf("BMI : %.3f, 경도비만입니다. 정상 체중 범위는 %.2f ~ %.2f kg 입니다.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
        else
            printf("BMI : %.3f, 비만입니다. 정상 체중 범위는 %.2f ~ %.2f kg 입니다.", bmi, (pow(mheight, 2) * 18.5), (pow(mheight, 2) * 23));
    }
    if (userchoice == 4) // 랜덤 99단 출제, 수업시간에 재밌어서 선택하게 되었다.
    {
        printf("랜덤 99단 출제\n");
        srand(time(NULL)); // 완전히 랜덤으로 출제
        int dan, i, jungdap, userdap, n, count = 0;
        printf("구구단 몇 문제? \n");
        scanf("%d", &n);
        for (int a = 0; a < n; a++)
        {
            dan = rand() % 90 + 10; // 곱하는 두 수는 각각 10에서 99사이의 두자리 자연수로 한다.
            i = rand() % 90 + 10;
            jungdap = dan * i;
            printf("%d * %d = ", dan, i);
            scanf("%d", &userdap);
            if (jungdap == userdap)
            {
                printf("맞았습니다. \n");
                count++;
            }
            else
                printf("틀렸습니다. 정답은 %d입니다.\n", jungdap);
        }
        printf("%d 문제 중 %d 문제 맞혔습니다.", n, count);
    }
    if (userchoice == 5) //GSA38 명단
    {
        int pick;
        printf("38기 학생 명단\n");
        printf("반 출력 =  1~6, 전체 출력 = 7  : \n");
        scanf("%d", &pick);
        if (pick == 7)
            printf("GSA38 명단 (99명)\n\n");
        if (pick == 1 || pick == 7)
            printf("1-1 (17명)  |  담임 : 김지훈T\n강예혁, 강은찬, 고성윤, 김  건, 김동건, 김주완, 김태우, 노현서\n신유찬, 심윤섭, 윤가온, 윤지환, 이다연, 전승원, 정상호, 진태인, 한민솔\n\n");
        if (pick == 2 || pick == 7)
            printf("1-2 (16명)  |  담임 : 정지현T\n김기홍, 김동우, 김승윤, 김현수, 박재원, 박주형, 박진우, 신동민\n염예찬, 이유겸, 이재윤, 이정무, 이정민, 임경훈, 장혜원, 최정연\n\n");
        if (pick == 3 || pick == 7)
            printf("1-3 (17명)  |  담임 : 서율희T\n곽나영, 권도휘, 김규민, 김상원, 김지섭, 박지용, 백인성, 송준영\n양해승, 유하민, 이승헌, 이채원, 이호형, 지승현, 추수혁, 태종혁, 한  준\n\n");
        if (pick == 4 || pick == 7)
            printf("1-4 (16명)  |  담임 : 최용석T\n김도준, 김도형, 김범석, 김성준, 민재경, 방준하, 배준성, 봉준상\n성하늘, 유재성, 이현진, 임정훈, 전수정, 정지윤, 최희웅, 편성주\n\n");
        if (pick == 5 || pick == 7)
            printf("1-5 (16명)  |  담임 : 이인호T\n김민재, 김보란, 김희주, 박찬혁, 배열희, 서지운, 원승빈, 이현승\n임승민, 장현준, 정광원, 정재원, 최원우, 최현민, 황규현, 황보승욱\n\n");
        if (pick == 6 || pick == 7)
            printf("1-6 (17명)  |  담임 : 최병길T\n고명준, 김규헌, 김동빈, 김성우, 김시우, 김영우, 김은우, 김정우\n김현우, 송명헌, 이정민, 임원상, 전종훈, 조수민, 조하진, 하정윤, 한지민\n\n");
    }
    if (userchoice == 6)// 그냥 본인 정보를 넣고 싶었음
    {
        printf("\n 제작자 정보 \n");
        printf(" 1412 임정훈 / GSA38 / 21073 / 수천 / 시리우스");
    }
}
