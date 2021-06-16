#include<stdio.h>
#include<stdlib.h>
#include<string.h> //문자열을 다루는 함수들을 가지고 있는 헤더파일이다.
#include<ctype.h>  //문자들을 조건에 맞는지 검사하고 변환하는 함수들을 가지고 있는 헤더파일이다. 여기서 사용하는 함수는 isdigit 함수로, 
//isdigit(int c)는 c가 숫자이면 0이 아닌 값을 반환하는 함수이다.
#include<windows.h>

#define limit 8//아이디와 비밀번호의 길이제한은 8이므로 이것을 쉽게 나타내기 위해 limit 상수를 지정하였다.

//회원가입을 담당하는 함수, 그리고 로그인을 담당하는 함수를 정의하였다.
void join(char a[], int i);
int login(char a[], int i);

int main()
{
    char id[limit + 1] = ""; //입력받은 아이디를 가지고 있는다.
    char password[limit + 1] = ""; //입력받은 비밀번호를 가지고 있는다.
    int key_code;

    printf("<회원가입>\n");
    printf("글자수 : 8글자 이내\n");
    printf("글자제한 : 영어 소문자와 숫자만 사용가능\n");

    join(id, 0); //정의된 join 함수를 사용한다.
    join(password, 1);//정의된 join 함수를 사용한다.
    //-->아이디 관리와 비밀번호 관리를 하나의 함수로 작동시키기 위해서 함수의 두 번째 변수에 0을 넣으면 아이디 관리, 1을 넣으면 비밀번호 관리를 할 수 있다.
    system("cls"); // 콘솔화면을 비우는 역할을 한다.
    printf("회원가입이 완료되었습니다.\n");
    printf("");
    printf("로그인 하세요.\n");

    do
    {
        key_code = (login(id, 0) && login(password, 1));//아이디 관리와 비밀번호 관리를 하나의 함수로 작동시키기 위해서 함수의 두 번째 변수에 0을 넣으면 아이디 관리, 1을 넣으면 비밀번호 관리를 할 수 있다.

        if (key_code == 1)
            printf("로그인 되었습니다.");
        else
            printf("로그인에 실패했습니다.");
    } while (key_code != 1);

    return 0;
}

void join(char a[], int i) //join 함수(회원가입을 담당하는 함수)를 정의한다.-->기존에 설정한 조건에 아이드나 비밃ㄴ호가 맞지 않는 경우 다시설정하도록한다.
{
    if (i == 0) //아이디에는 0, 그리고 비밀번호에는 1을 매칭한다. 아이디와 비번을 동시에 받기 어려울 것 같아 두부분으로 나눠 처리하였다고 보면 된다.
    {
        printf("아이디를 입력하시오");
        scanf("%s", a);
    }

    if (i == 1)
    {
        printf("비밀번호를 입력하시오");
        scanf("%s", a);
    }

    char* p = a; //char*는 문자열을 의미한다.

out: //out은  함수 바깥으로 값이 나오는 매개변수이다.

    while (strlen(a) > limit) //아이디나 비밀번호의 길이가 제한 길이(limit=8)을 넘어간다면 다시 입력하게 한다.
    {
        printf("글자수를 초과했습니다");
        scanf("%s", a);
    }

    for (int i = 0; i <= limit; i++)
    {
        if (islower(*(p + i)) == 0) //islower은 특정 문자가 소문자인지 알려주는 함수이다. 이를 통해 아이지나 비밀번호에 조건에 맞지 않는 수가 있다면 다시입력하도록한다.
        {
            if (isdigit(*(p + i)) == 0) //입력받은 값이 0~9인지 확인 그외-숫자가 아닌 다른 문자인 경우 다시 출력하도록한다,
            {
                if (*(p + i) != NULL) //
                {
                    printf("%s\n", a);
                    puts("잘못된 문자가 입력되어 있습니다.");
                    scanf("%s", a);
                    goto out;
                    //break;
                }
            }
        }
    }

}

int login(char a[], int i) //로그인을 담당하는 함수이다. 회원가입 담당함수와 거의 동일한 구조를 이루고 있다.
{
    char arr[limit + 1] = "";

    if (i == 0)
    {
        printf("아이디 : ");
        scanf("%s", arr);
    }

    if (i == 1)
    {
        printf("비밀번호 : ");
        scanf("%s", arr);
    }

    if (strcmp(a, arr) != 0)//strcmp는 문자열을 비교해주는 함수로 비밀번호가 틀렸는지 맞았는지를 확인한다.
        return 0;
    else
        return 1;

}
