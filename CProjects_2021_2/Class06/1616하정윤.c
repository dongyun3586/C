#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

struct dtime {
	int day;
	int hr;
	int min;
	int sec;
};

int main() {

	struct tm* in, * out, * today, day1;	// �Ի�, ���, ���� ��¥�� �ð�, ���б���۳�
	struct dtime tp, tl;				// time passed, time left

	time_t start, finish, passed, left;

	time_t now;
	now = time(NULL);

	int iyr, imth, iday;	// iyr = in year = �Ի��� �⵵
	int oyr, omth, oday;
	char* weekday[] = { "�Ͽ���", "������", "ȭ����", "������", "�����", "�ݿ���", "�����" };

	int tda;	// ���б� �����ϰ� ���� ��

	day1.tm_year = 2021 - 1900;
	day1.tm_mon = 3 - 1;
	day1.tm_mday = 2;
	day1.tm_hour = 1;
	day1.tm_min = 1;
	day1.tm_sec = 1;
	// mktime�Լ� ������ ��, ��, �� �� �ʿ�

	mktime(&day1);
	// mktime �Լ��� ȣ���ϸ� ��, ��, �� ���� ���� ����ü�� tm_wday�� tm_yday�� ����.

	today = localtime(&now);
	tda = today->tm_yday - day1.tm_yday + 1;

	printf("\n**** ! ������ COUNTDOWN ! ****\n");
	printf("������ 2021�г⵵ �������� %d��° �Ǵ� ��!\n\n", tda);
	printf("[�Ի� �ð��� 19:30 , ��� �ð��� 16:20] ���ܴ� �������� �ʴ´�~\n\n\n");

	in = localtime(&now);	//�ʱ�ȭ

	printf("���� �Ի��߾�? (yyyy mm dd) : ");

	scanf("%d %d %d", &iyr, &imth, &(in->tm_mday));
	in->tm_year = iyr - 1900;
	in->tm_mon = imth - 1;
	in->tm_hour = 19;
	in->tm_min = 30;
	in->tm_sec = 0;

	start = mktime(in);
	// mktime �Լ��� �Ű������� ���� ����ü�� time_t������ ��ȯ 
	// => in�� time_t������ �ٲ� start�� ����

	printf("\n\n�Ի��� ��¥ : %d�� %2d�� %2d�� %s\n"
		, in->tm_year + 1900, in->tm_mon + 1, in->tm_mday, weekday[in->tm_wday]);


	out = localtime(&now);

	printf("\n\n���� �����? (yyyy mm dd) : ");

	scanf("%d %d %d", &oyr, &omth, &(out->tm_mday));
	out->tm_year = oyr - 1900;
	out->tm_mon = omth - 1;
	out->tm_hour = 16;
	out->tm_min = 20;
	out->tm_sec = 0;

	finish = mktime(out);

	printf("\n\n��� ��¥ : %d�� %2d�� %2d�� %s\n"
		, out->tm_year + 1900, out->tm_mon + 1, out->tm_mday, weekday[out->tm_wday]);


	today = localtime(&now);

	printf("\n\n���� ��¥ : %d�� %2d�� %2d�� %s\n\n"
		, today->tm_year + 1900, today->tm_mon + 1, today->tm_mday, weekday[today->tm_wday]);

	while (1) {

		now = time(NULL);	//now�� ��� ������Ʈ��Ŵ

		passed = now - start;	//�Ի�ð����� ���ݱ��� �帥 ��
		left = finish - now;	//���ݺ��� ���ð����� ���� ��

		tp.day = (int)passed / 86400;	//24*3600=86400
		tp.hr = (int)passed / 3600 % 24;
		tp.min = (int)passed % 3600 / 60;
		tp.sec = (int)passed % 60;

		tl.day = (int)left / 86400;
		tl.hr = (int)left / 3600 % 24;
		tl.min = (int)left % 3600 / 60;
		tl.sec = (int)left % 60;

		today = localtime(&now);	//��� �����Ǵ� ����ð�

		printf("���� �ð�  %02d : %02d : %02d\t\t ���ݱ��� ��ƾ �ð�  %d�� %02d�ð� %02d�� %02d��\t ������ ���� �ð�  %d�� %02d�ð� %02d�� %02d��\r"
			, today->tm_hour, today->tm_min, today->tm_sec
			, tp.day, tp.hr, tp.min, tp.sec
			, tl.day, tl.hr, tl.min, tl.sec);
		// \r�� ���� �Ǿ����� ���ư� �ð� ��� �����

		if (kbhit() == 1)	// Ű���忡 �Է°��� ������ break
			break;
	}

	return 0;
}