#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

float calculateMean(float arr[], int length);                                                     // ��� ��� �Լ�
void bubbleSortArray(float arr[], int length);                                                    // �迭�� ���� ���� ���ִ� �Լ�
float gaussianRandom(float average, float stddev);                                                // ���Ժ��� ���� ���� �Լ�
void substitutionGaussrandArray(float arr[], int length, float avg, float stddev, float n);       // �迭�� ������ ������ �����ϴ� �Լ�
void variablefine_n(float var, float n);                                                          // �Է��� �Լ��� 0 �̻� 70 �������� Ȯ���ϴ� �Լ�
int Rank(float arr[], float score, int r);				                                          // ������ �˷��ִ� �Լ�
void expectgrade(int rank);                                                                       // �������� ��� �Լ�

int main() {
	float ScorePhysics_a_arr[110] = { 0 };                         // ���� a�� ������ �����ϴ� �迭(user�� ������ ������ �л����� ����)
	float ScorePhysics_b_arr[110] = { 0 };                         // ���� b�� ������ �����ϴ� �迭
	float xsphy_a_arr[110] = { 0 };                                // ���� a�� ����� ������ �����ϴ� �迭
	float xsphy_b_arr[110] = { 0 };                                // ���� b�� ����� ������ �����ϴ� �迭
	float ScorePhysics_arr[110] = { 0 };                           // ���� ������ �����ϴ� �迭
	float ScoreMathematics1_a_arr[110] = { 0 };                    // ���� 1a�� ������ �����ϴ� �迭
	float ScoreMathematics1_b_arr[110] = { 0 };                    // ���� 1b�� ������ �����ϴ� �迭
	float xsmat1_a_arr[110] = { 0 };
	float xsmat1_b_arr[110] = { 0 };
	float ScoreMathematics1_arr[110] = { 0 };                      // ���� 1 ������ �����ϴ� �迭
	float ScoreMathematics2_a_arr[110] = { 0 };                    // ���� 2a�� ������ �����ϴ� �迭
	float ScoreMathematics2_b_arr[110] = { 0 };                    // ���� 2b�� ������ �����ϴ� �迭
	float xsmat2_a_arr[110] = { 0 };
	float xsmat2_b_arr[110] = { 0 };
	float ScoreMathematics2_arr[110] = { 0 };
	float ScoreInformation_arr[110] = { 0 };                       // ������ ������ �����ϴ� �迭
	float xsinf[110] = { 0 };
	float ScoreChemistry_a_arr[110] = { 0 };                       // ȭ�� a�� ������ �����ϴ� �迭
	float ScoreChemistry_b_arr[110] = { 0 };                       // ȭ�� b�� ������ �����ϴ� �迭
	float ScoreChemistry_arr[110] = { 0 };
	float xscem_a_arr[110] = { 0 };
	float xscem_b_arr[110] = { 0 };
	float ScoreBiological_a_arr[110] = { 0 };                      // ������� a�� ������ �����ϴ� �迭
	float ScoreBiological_b_arr[110] = { 0 };                      // ������� b�� ������ �����ϴ� �迭
	float ScoreBiological_c_arr[110] = { 0 };                      // ������� c�� ������ �����ϴ� �迭
	float xsbio_a_arr[110] = { 0 };
	float xsbio_b_arr[110] = { 0 };
	float xsbio_c_arr[110] = { 0 };
	float ScoreBiological_arr[110] = { 0 };
	float ScoreGeoscience_a_arr[110] = { 0 };                      // �������� a�� ������ �����ϴ� �迭
	float ScoreGeoscience_b_arr[110] = { 0 };                      // �������� b�� ������ �����ϴ� �迭
	float xsgeo_a_arr[110] = { 0 };
	float xsgeo_b_arr[110] = { 0 };
	float ScoreGeoscience_arr[110] = { 0 };
	float Allrankavg[110] = { 0 };
	float userScorePhysics_a, userScorePhysics_b, userScorePhysics;
	float userScoreMathematics1_a, userScoreMathematics1_b, userScoreMathematics1, userScoreMathematics2_a, userScoreMathematics2_b, userScoreMathematics2;
	float userScoreInformation;
	float userScoreChemistry_a, userScoreChemistry_b, userScoreChemistry;
	float userScoreBiological_a, userScoreBiological_b, userScoreBiological_c, userScoreBiological;
	float userScoreGeoscience_a, userScoreGeoscience_b, userScoreGeoscience;
	float allscoreavg = 0;
	int userRankPhysics_a = 0, userRankPhysics_b = 0, userRankPhysics = 0;
	int userRankMathematics1_a = 0, userRankMathematics1_b = 0, userRankMathematics1 = 0, userRankMathematics2_a, userRankMathematics2_b, userRankMathematics2;
	int userRankInformation;
	int userRankChemistry_a, userRankChemistry_b, userRankChemistry;
	int userRankBiological_a, userRankBiological_b, userRankBiological_c, userRankBiological;
	int userRankGeoscience_a, userRankGeoscience_b, userRankGeoscience;
	int allrank;
	srand(time(NULL));
	printf("1�г� 2�� 6�� ������ �������� ������Ʈ \n\"���� ����\"\n");
	printf("�� ������ ������ �Է��Ͻʽÿ�\n\n");
	substitutionGaussrandArray(ScorePhysics_a_arr, 99, 35, 12.5, 70);
	for (int i = 0; i < 99; i++) {
		xsphy_a_arr[i] = ScorePhysics_a_arr[i];
	}
	substitutionGaussrandArray(ScorePhysics_b_arr, 99, 4.8, 3.3, 30);
	for (int i = 0; i < 99; i++) {
		xsphy_b_arr[i] = ScorePhysics_b_arr[i];
	}
	substitutionGaussrandArray(ScoreMathematics1_a_arr, 99, 26, 12, 66);
	for (int i = 0; i < 99; i++) {
		xsmat1_a_arr[i] = ScoreMathematics1_a_arr[i];
	}
	substitutionGaussrandArray(ScoreMathematics1_b_arr, 99, 18, 7.2, 34);
	for (int i = 0; i < 99; i++) {
		xsmat1_b_arr[i] = ScoreMathematics1_b_arr[i];
	}
	substitutionGaussrandArray(ScoreMathematics2_a_arr, 99, 36, 9.5, 67);
	for (int i = 0; i < 99; i++) {
		xsmat2_a_arr[i] = ScoreMathematics2_a_arr[i];
	}
	substitutionGaussrandArray(ScoreMathematics2_b_arr, 99, 18, 6.8, 34);
	for (int i = 0; i < 99; i++) {
		xsmat2_b_arr[i] = ScoreMathematics2_b_arr[i];
	}
	substitutionGaussrandArray(ScoreInformation_arr, 99, 61, 13.2, 100);
	for (int i = 0; i < 99; i++) {
		xsinf[i] = ScoreInformation_arr[i];
	}
	substitutionGaussrandArray(ScoreChemistry_a_arr, 99, 35, 8.2, 53);
	for (int i = 0; i < 99; i++) {
		xscem_a_arr[i] = ScoreChemistry_a_arr[i];
	}
	substitutionGaussrandArray(ScoreChemistry_b_arr, 99, 28, 7.5, 47);
	for (int i = 0; i < 99; i++) {
		xscem_b_arr[i] = ScoreChemistry_b_arr[i];
	}
	substitutionGaussrandArray(ScoreBiological_a_arr, 99, 13.8, 4.2, 33);
	for (int i = 0; i < 99; i++) {
		xsbio_a_arr[i] = ScoreBiological_a_arr[i];
	}
	substitutionGaussrandArray(ScoreBiological_b_arr, 99, 18.7, 4.7, 34);
	for (int i = 0; i < 99; i++) {
		xsbio_b_arr[i] = ScoreBiological_b_arr[i];
	}
	substitutionGaussrandArray(ScoreBiological_c_arr, 99, 18.2, 4.9, 33);
	for (int i = 0; i < 99; i++) {
		xsbio_c_arr[i] = ScoreBiological_c_arr[i];
	}
	substitutionGaussrandArray(ScoreGeoscience_a_arr, 99, 30.2, 8.2, 50);
	for (int i = 0; i < 99; i++) {
		xsgeo_a_arr[i] = ScoreGeoscience_a_arr[i];
	}
	substitutionGaussrandArray(ScoreGeoscience_b_arr, 99, 26, 7.1, 50);
	for (int i = 0; i < 99; i++) {
		xsgeo_b_arr[i] = ScoreGeoscience_b_arr[i];
	}

	do {
		printf("����a: ");
		scanf("%f", &userScorePhysics_a);
		variablefine_n(userScorePhysics_a, 70);
	} while (userScorePhysics_a < 0 || userScorePhysics_a > 70);
	ScorePhysics_a_arr[99] = userScorePhysics_a;
	bubbleSortArray(ScorePhysics_a_arr, 100);
	userRankPhysics_a = Rank(ScorePhysics_a_arr, userScorePhysics_a, 0);
	printf("����a������ ���: %.2f��, ����: %d��\n", calculateMean(ScorePhysics_a_arr, 100), userRankPhysics_a);

	do {
		printf("����b: ");
		scanf("%f", &userScorePhysics_b);
		variablefine_n(userScorePhysics_b, 30);
	} while (userScorePhysics_b < 0 || userScorePhysics_b > 30);
	ScorePhysics_b_arr[99] = userScorePhysics_b;
	bubbleSortArray(ScorePhysics_b_arr, 100);
	userRankPhysics_b = Rank(ScorePhysics_b_arr, userScorePhysics_b, 0);
	printf("����b������ ���: %.2f��, ����: %d��\n", calculateMean(ScorePhysics_b_arr, 100), userRankPhysics_b);

	userScorePhysics = userScorePhysics_a + userScorePhysics_b;

	bubbleSortArray(xsphy_a_arr, 99);
	bubbleSortArray(xsphy_b_arr, 99);
	for (int i = 0; i < 99; i++) {
		ScorePhysics_arr[i] = xsphy_a_arr[i] + xsphy_b_arr[i];
	}
	ScorePhysics_arr[99] = userScorePhysics;
	bubbleSortArray(ScorePhysics_arr, 100);
	userRankPhysics = Rank(ScorePhysics_arr, userScorePhysics, 0);
	printf("���� ���: %.2f�� ����: %d��\n", calculateMean(ScorePhysics_arr, 100), userRankPhysics);
	expectgrade(userRankPhysics);

	do {
		printf("����1a: ");
		scanf("%f", &userScoreMathematics1_a);
		variablefine_n(userScoreMathematics1_a, 66);
	} while (userScoreMathematics1_a < 0 || userScoreMathematics1_a > 66);
	ScoreMathematics1_a_arr[99] = userScoreMathematics1_a;
	bubbleSortArray(ScoreMathematics1_a_arr, 100);
	userRankMathematics1_a = Rank(ScoreMathematics1_a_arr, userScoreMathematics1_a, 0);
	printf("����1a������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreMathematics1_a_arr, 100), userRankMathematics1_a);

	do {
		printf("����1b: ");
		scanf("%f", &userScoreMathematics1_b);
		variablefine_n(userScoreMathematics1_b, 34);
	} while (userScoreMathematics1_b < 0 || userScoreMathematics1_b > 34);
	ScoreMathematics1_b_arr[99] = userScoreMathematics1_b;
	bubbleSortArray(ScoreMathematics1_b_arr, 100);
	userRankMathematics1_b = Rank(ScoreMathematics1_b_arr, userScoreMathematics1_b, 0);
	printf("����1b������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreMathematics1_b_arr, 100), userRankMathematics1_b);

	userScoreMathematics1 = userScoreMathematics1_a + userScoreMathematics1_b;

	bubbleSortArray(xsmat1_a_arr, 99);
	bubbleSortArray(xsmat1_b_arr, 99);
	for (int i = 0; i < 99; i++) {
		ScoreMathematics1_arr[i] = xsmat1_a_arr[i] + xsmat1_b_arr[i];
	}
	ScoreMathematics1_arr[99] = userScoreMathematics1;
	bubbleSortArray(ScoreMathematics1_arr, 100);
	userRankMathematics1 = Rank(ScoreMathematics1_arr, userScoreMathematics1, 0);
	printf("����1 ���: %.2f�� ����: %d��\n", calculateMean(ScoreMathematics1_arr, 100), userRankMathematics1);
	expectgrade(userRankMathematics1);

	do {
		printf("����2a: ");
		scanf("%f", &userScoreMathematics2_a);
		variablefine_n(userScoreMathematics2_a, 67);
	} while (userScoreMathematics2_a < 0 || userScoreMathematics2_a > 67);
	ScoreMathematics2_a_arr[99] = userScoreMathematics2_a;
	bubbleSortArray(ScoreMathematics2_a_arr, 100);
	userRankMathematics2_a = Rank(ScoreMathematics2_a_arr, userScoreMathematics2_a, 0);
	printf("����2a������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreMathematics2_a_arr, 100), userRankMathematics2_a);

	do {
		printf("����2b: ");
		scanf("%f", &userScoreMathematics2_b);
		variablefine_n(userScoreMathematics2_b, 33);
	} while (userScoreMathematics2_b < 0 || userScoreMathematics2_b > 33);
	ScoreMathematics2_b_arr[99] = userScoreMathematics2_b;
	bubbleSortArray(ScoreMathematics2_b_arr, 100);
	userRankMathematics2_b = Rank(ScoreMathematics2_b_arr, userScoreMathematics2_b, 0);
	printf("����2b������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreMathematics2_b_arr, 100), userRankMathematics2_b);

	userScoreMathematics2 = userScoreMathematics2_a + userScoreMathematics2_b;

	bubbleSortArray(xsmat2_a_arr, 99);
	bubbleSortArray(xsmat2_b_arr, 99);
	for (int i = 0; i < 99; i++) {
		ScoreMathematics2_arr[i] = xsmat2_a_arr[i] + xsmat2_b_arr[i];
	}
	ScoreMathematics2_arr[99] = userScoreMathematics2;
	bubbleSortArray(ScoreMathematics2_arr, 100);
	userRankMathematics2 = Rank(ScoreMathematics2_arr, userScoreMathematics2, 0);
	printf("����2 ���: %.2f�� ����: %d��\n", calculateMean(ScoreMathematics2_arr, 100), userRankMathematics2);
	expectgrade(userRankMathematics2);

	do {
		printf("����: ");
		scanf("%f", &userScoreInformation);
		variablefine_n(userScoreInformation, 100);
	} while (userScoreInformation < 0 || userScoreInformation > 100);
	ScoreInformation_arr[99] = userScoreInformation;
	bubbleSortArray(ScoreInformation_arr, 100);
	userRankInformation = Rank(ScoreInformation_arr, userScoreInformation, 0);
	printf("���������� ���: %.2f��, ����: %d��\n", calculateMean(ScoreInformation_arr, 100), userRankInformation);
	expectgrade(userRankInformation);

	do {
		printf("ȭ��a: ");
		scanf("%f", &userScoreChemistry_a);
		variablefine_n(userScoreChemistry_a, 53);
	} while (userScoreChemistry_a < 0 || userScoreChemistry_a > 53);
	ScoreChemistry_a_arr[99] = userScoreChemistry_a;
	bubbleSortArray(ScoreChemistry_a_arr, 100);
	userRankChemistry_a = Rank(ScoreChemistry_a_arr, userScoreChemistry_a, 0);
	printf("ȭ��a������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreChemistry_a_arr, 100), userRankChemistry_a);

	do {
		printf("ȭ��b: ");
		scanf("%f", &userScoreChemistry_b);
		variablefine_n(userScoreChemistry_b, 47);
	} while (userScoreChemistry_b < 0 || userScoreChemistry_b > 47);
	ScoreChemistry_b_arr[99] = userScoreChemistry_b;
	bubbleSortArray(ScoreChemistry_b_arr, 100);
	userRankChemistry_b = Rank(ScoreChemistry_b_arr, userScoreChemistry_b, 0);
	printf("ȭ��b������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreChemistry_b_arr, 100), userRankChemistry_b);

	userScoreChemistry = userScoreChemistry_a + userScoreChemistry_b;

	bubbleSortArray(xscem_a_arr, 99);
	bubbleSortArray(xscem_b_arr, 99);
	for (int i = 0; i < 99; i++) {
		ScoreChemistry_arr[i] = xscem_a_arr[i] + xscem_b_arr[i];
	}
	ScoreChemistry_arr[99] = userScoreChemistry;
	bubbleSortArray(ScoreChemistry_arr, 100);
	userRankChemistry = Rank(ScoreChemistry_arr, userScoreChemistry, 0);
	printf("ȭ�� ���: %.2f�� ����: %d��\n", calculateMean(ScoreChemistry_arr, 100), userRankChemistry);
	expectgrade(userRankChemistry);

	do {
		printf("�������a: ");
		scanf("%f", &userScoreBiological_a);
		variablefine_n(userScoreBiological_a, 33);
	} while (userScoreBiological_a < 0 || userScoreBiological_a > 33);
	ScoreBiological_a_arr[99] = userScoreBiological_a;
	bubbleSortArray(ScoreBiological_a_arr, 100);
	userRankBiological_a = Rank(ScoreBiological_a_arr, userScoreBiological_a, 0);
	printf("�������a������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreBiological_a_arr, 100), userRankBiological_a);

	do {
		printf("�������b: ");
		scanf("%f", &userScoreBiological_b);
		variablefine_n(userScoreBiological_b, 34);
	} while (userScoreBiological_b < 0 || userScoreBiological_b > 34);
	ScoreBiological_b_arr[99] = userScoreBiological_b;
	bubbleSortArray(ScoreBiological_b_arr, 100);
	userRankBiological_b = Rank(ScoreBiological_b_arr, userScoreBiological_b, 0);
	printf("�������b������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreBiological_b_arr, 100), userRankBiological_b);

	do {
		printf("�������c: ");
		scanf("%f", &userScoreBiological_c);
		variablefine_n(userScoreBiological_c, 33);
	} while (userScoreBiological_c < 0 || userScoreBiological_c > 33);
	ScoreBiological_c_arr[99] = userScoreBiological_c;
	bubbleSortArray(ScoreBiological_c_arr, 100);
	userRankBiological_c = Rank(ScoreBiological_c_arr, userScoreBiological_c, 0);
	printf("�������c������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreBiological_c_arr, 100), userRankBiological_c);

	userScoreBiological = userScoreBiological_a + userScoreBiological_b + userScoreBiological_c;

	bubbleSortArray(xsbio_a_arr, 99);
	bubbleSortArray(xsbio_b_arr, 99);
	bubbleSortArray(xsbio_c_arr, 99);
	for (int i = 0; i < 99; i++) {
		ScoreBiological_arr[i] = xsbio_a_arr[i] + xsbio_b_arr[i] + xsbio_c_arr[i];
	}
	ScoreBiological_arr[99] = userScoreBiological;
	bubbleSortArray(ScoreBiological_arr, 100);
	userRankBiological = Rank(ScoreBiological_arr, userScoreBiological, 0);
	printf("������� ���: %.2f�� ����: %d��\n", calculateMean(ScoreBiological_arr, 10), userRankBiological);
	expectgrade(userRankBiological);

	do {
		printf("��������a: ");
		scanf("%f", &userScoreGeoscience_a);
		variablefine_n(userScoreGeoscience_a, 50);
	} while (userScoreGeoscience_a < 0 || userScoreGeoscience_a > 50);
	ScoreGeoscience_a_arr[99] = userScoreGeoscience_a;
	bubbleSortArray(ScoreGeoscience_a_arr, 100);
	userRankGeoscience_a = Rank(ScoreGeoscience_a_arr, userScoreGeoscience_a, 0);
	printf("��������a������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreGeoscience_a_arr, 100), userRankGeoscience_a);

	do {
		printf("��������b: ");
		scanf("%f", &userScoreGeoscience_b);
		variablefine_n(userScoreGeoscience_b, 50);
	} while (userScoreGeoscience_b < 0 || userScoreGeoscience_b > 50);
	ScoreGeoscience_b_arr[99] = userScoreGeoscience_b;
	bubbleSortArray(ScoreGeoscience_b_arr, 100);
	userRankGeoscience_b = Rank(ScoreGeoscience_b_arr, userScoreGeoscience_b, 0);
	printf("��������b������ ���: %.2f��, ����: %d��\n", calculateMean(ScoreGeoscience_b_arr, 100), userRankGeoscience_b);

	userScoreGeoscience = userScoreGeoscience_a + userScoreGeoscience_b;

	bubbleSortArray(xsgeo_a_arr, 99);
	bubbleSortArray(xsgeo_b_arr, 99);
	for (int i = 0; i < 99; i++) {
		ScoreGeoscience_arr[i] = xsgeo_a_arr[i] + xsgeo_b_arr[i];
	}
	ScoreGeoscience_arr[99] = userScoreGeoscience;
	bubbleSortArray(ScoreGeoscience_arr, 100);
	userRankGeoscience = Rank(ScoreGeoscience_arr, userScoreGeoscience, 0);
	printf("�������� ���: %.2f�� ����: %d��\n", calculateMean(ScoreGeoscience_arr, 100), userRankGeoscience);
	expectgrade(userRankGeoscience);

	allscoreavg = (userScorePhysics + userScoreMathematics1 + userScoreMathematics2 + userScoreInformation
		+ userScoreChemistry + userScoreBiological + userScoreGeoscience) / 7;
	for (int i = 0; i < 99; i++) {
		Allrankavg[i] = (xsphy_a_arr[i] + xsphy_b_arr[i] + xsmat1_a_arr[i] + xsmat1_b_arr[i] + xsmat2_a_arr[i] + xsmat2_b_arr[i]
			+ xsinf[i] + xscem_a_arr[i] + xscem_b_arr[i] + xsbio_a_arr[i] + xsbio_b_arr[i] + xsbio_c_arr[i] + xsgeo_a_arr[i] + xsgeo_b_arr[i]) / 7;
	}
	Allrankavg[99] = allscoreavg;
	bubbleSortArray(Allrankavg, 100);
	allrank = Rank(Allrankavg, allscoreavg, 0);
	printf("��ü ���: %.2f��, ����: %d��", allscoreavg, allrank);


	return 0;
}

//��� ��� �Լ�
float calculateMean(float arr[], int length) {
	float sum = 0, mean = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}
	mean = sum / length;
	return mean;
}

//�迭�� �������� �ϴ� �Լ�
void bubbleSortArray(float arr[], int length) {
	float t;
	for (int k = 0; k < length; k++) {
		for (int j = 0; j < length - 1 - k; j++) {
			if (arr[j] < arr[j + 1]) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

//�迭�� ������ ���Ժ��� ������ �����ϴ� �Լ�
void substitutionGaussrandArray(float arr[], int length, float avg, float stddev, float n) {
	for (int i = 0; i < length; i++) {
		do {
			arr[i] = gaussianRandom(avg, stddev);
		} while (arr[i] < 0 || arr[i] > n);
		bubbleSortArray(arr, 100);
	}
}

//�Է��� ������ 0~n������ Ȯ���ϴ� �Լ�
void variablefine_n(float var, float n) {
	if (var < 0 || var > n) {
		printf("�߸��� �Է��Դϴ�. 0 �̻� %.1f ������ ���ڸ� �Է��� �ֽʽÿ�\n", n);
	}
}

//���Ժ��� ���� ���� �Լ�
float gaussianRandom(float average, float stddev) {
	double v1, v2, k, temp;
	do {
		v1 = 2 * ((double)rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 ������ ��
		v2 = 2 * ((double)rand() / RAND_MAX) - 1;      // -1.0 ~ 1.0 ������ ��
		k = pow(v1, 2) + pow(v2, 2);
	} while (k >= 1 || k == 0);
	k = sqrt((-2 * log(k)) / k);
	temp = v1 * k;
	temp = (stddev * temp) + average;
	return temp;
}

//���ĵ� �迭���� ������ ���ϴ� �Լ�
int Rank(float arr[], float score, int r) {
	for (int i = 0; i < 100; i++) {
		if (arr[i] == score) {
			r = i + 1;
		}
	}
	return r;
}

//�������� �Լ�
void expectgrade(int rank) {
	if (1 <= rank && rank <= 15) {
		printf("���������� A+�Դϴ�.\n");
	}
	else if (16 <= rank && rank <= 30) {
		printf("���������� A0�Դϴ�.\n");
	}
	else if (31 <= rank && rank <= 45) {
		printf("���������� A-�Դϴ�.\n");
	}
	else if (46 <= rank && rank <= 60) {
		printf("���������� B+�Դϴ�.\n");
	}
	else if (61 <= rank && rank <= 75) {
		printf("���������� B0�Դϴ�.\n");
	}
	else if (76 <= rank && rank <= 90) {
		printf("���������� B-�Դϴ�.\n");
	}
	else {
		printf("���������� C+�Դϴ�.\n");
	}
}