#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

#define WORDMAX 32 // 최대 단어 수
#define STRMAX 20 // 최대 글자 수

typedef struct dayword {
	int num_words;
	char word_eng[WORDMAX][STRMAX];
	char word_kor[WORDMAX][STRMAX];
}dayword; // 챕터를 담기 위한 구조체
dayword set = { 0 }; // 학습할 챕터를 담기 위한 구조체
dayword day01_1, day01_2, day15_1; // 챕터를 담기 위한 구조체

#pragma region
void select(); // 챕터 선택
void setting(char eng[WORDMAX][STRMAX], char kor[WORDMAX][STRMAX], dayword dayset); // set 구조체에 선택한 챕터 복사
void start(); // 학습 모드 선택, 이동(write, choose)
void write(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]); // 주관식(한->영)
void choose(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]); // 객관식
int countWords(char word[WORDMAX][STRMAX]); // 이차원 배열의 단어 수 반환
void generateRandom(); // 1부터 단어 수까지의 수들을 무작위로 배열(중복 방지)
void printLine(); // 줄 출력
void swapStructure(dayword* a, dayword* b);
void over(); // 프로그램 종료
#pragma endregion

int mode, day, random[WORDMAX]; // 단어 학습 챕터, 모드 선택, 난수 배열

#pragma region
char day01_1_eng[WORDMAX][STRMAX] = { "annual", "eleborately", "costume", "officially", "declare", "origin", "slave", "rebellion", "rule", "temporary", "celebrate", "coal", "modern", "old-fashioned", "race", "ethnicity", "symbolize", "equality", "integrate", "citizen",  "diversity", "unity", "similarity" };
char day01_1_kor[WORDMAX][STRMAX] = { "매년의", "공들여", "의상", "공식적으로", "선언하다", "기원", "노예", "반란", "지배하다", "일시적인", "축하하다", "석탄", "현대의", "구식의", "인종", "민족성", "상징하다", "평등", "통합하다", "시민","다양성", "통합", "유사점" };
char day01_2_eng[WORDMAX][STRMAX] = { "ancient", "impressive", "tomb", "monument", "wheat", "sacred", "texture", "nutritional", "benefit", "grain", "fiber", "archaeology", "artwork", "preserve", "yeast", "mud", "method", "reflect", "typical", "revolution", "justice", "represent", "generation", "magnificence", "term" };
char day01_2_kor[WORDMAX][STRMAX] = { "고대의", "인상적인", "무덤", "기념물", "밀", "신성한", "질감", "영양상의", "이득", "곡물", "섬유질", "고고학", "예술품", "보존하다", "효모", "진흙", "방법", "반영하다", "전형적인", "혁명", "정의", "나타내다", "세대", "장엄", "용어" };
char day15_1_eng[WORDMAX][STRMAX] = { "witness", "rapid", "ancient", "compete", "government", "profound", "democracy", "rule", "council", "executive", "administrative", "election", "citizen", "assembly", "aristocratic", "authority", "privilege", "inhabitant", "legal", "apparent", "attribute", "limitation", "rebellion", "retain", "stability", "origin", "rivalry", "compromise" };
char day15_1_kor[WORDMAX][STRMAX] = { "목격하다", "빠른", "고대의", "경쟁하다", "정부", "깊은", "민주주의", "지배하다", "평의회", "행정의", "행정상의", "선거", "시민", "의회", "귀족의", "권한", "특권", "주민", "법률상의", "분명한", "특성", "한계", "반란", "유지하다", "안정", "기원", "경쟁", "타협하다" };
#pragma endregion

int main() {
	select();
}

void select() {
	printf("DAY를 선택하세요.\n1. DAY 01-1\n2. DAY 01-2\n3. DAY 15-1\n");
	scanf("%d", &day);
	switch (day) {
	case 1: setting(day01_1_eng, day01_1_kor, day01_1);
		break;
	case 2: setting(day01_2_eng, day01_2_kor, day01_2);
		break;
	case 3: setting(day15_1_eng, day15_1_kor, day15_1);
		break;
	default:
		over();
	}
}

void setting(char eng[WORDMAX][STRMAX], char kor[WORDMAX][STRMAX], dayword dayset) {
	dayset.num_words = countWords(eng); // 구조체 요소 복사
	memcpy(dayset.word_eng, eng, WORDMAX * STRMAX); // 구조체 요소 복사
	memcpy(dayset.word_kor, kor, WORDMAX * STRMAX); // 구조체 요소 복사
	swapStructure(&set, &dayset); // 구조체 전체 복사
	start();
}

void start() {
	printf("단어 학습을 시작합니다. 학습 모드를 선택하세요.\n1. 한 -> 영(주관식)\n2. 한 -> 영(객관식)\n3. 영 -> 한(객관식)\n");
	scanf("%d", &mode);
	switch (mode) {
	case 1:
		printf("한 -> 영(주관식)\n");
		write(set.word_kor, set.word_eng); // 출력, 입력 순
		break;
	case 2:
		printf("한 -> 영(객관식)\n");
		choose(set.word_kor, set.word_eng); // 출력, 입력 순
		break;
	case 3:
		printf("영 -> 한(객관식)\n");
		choose(set.word_eng, set.word_kor); // 출력, 입력 순
		break;
	default: over();
	}
}

void write(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]) {
	printLine();
	int count = 0; // 맞힌 문제 수
	char input[STRMAX];
	srand(time(NULL));
	for (int i = 0; i < set.num_words; i++) {
		int j = rand() % set.num_words;
		printf("%s\n입력: ", put[j]);
		scanf("%s", input);
		if (strcmp(input, get[j])) // 두 문자열이 일치하지 않음
			printf("틀렸어요.\n");
		else {
			printf("정답!\n");
			count++;
		}
		printLine();
	}
	printf("%d개 정답!\n", count);
	over();
}

void choose(char put[WORDMAX][STRMAX], char get[WORDMAX][STRMAX]) {
	printLine();
	int input, count = 0;
	for (int i = 0; i < set.num_words; i++) {
		generateRandom(); // 난수 배열 생성
		int j = random[0], j1 = random[1], j2 = random[2], j3 = random[3]; // 난수 배열에서 4개의 수 뽑기
		int n = rand() % 4 + 1; // 1~4 중 난수 1개 생성
		printf("%s\n", put[j]); // 문제 출력
		switch (n) {
		case 1: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j], get[j1], get[j2], get[j3]);
			break;
		case 2: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j1], get[j], get[j2], get[j3]);
			break;
		case 3: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j1], get[j2], get[j], get[j3]);
			break;
		case 4: printf("1. %s\t2. %s\t3. %s\t4. %s\n", get[j1], get[j2], get[j3], get[j]);
			break;
		default: over();
		} // 보기 출력
		scanf("%d", &input);
		if (input == n) {
			printf("정답!\n");
			count++;
		}
		else printf("틀렸어요.\n");
		printLine();
	}
	printf("%d개 정답!\n", count);
	over();
}

void generateRandom() {
	int temp, x, y;
	srand(time(NULL));
	for (int i = 0; i < set.num_words; i++)
		random[i] = i;
	for (int i = 0; i < 99; i++) {
		x = rand() % set.num_words;
		y = rand() % set.num_words;
		if (x != y) { // x=y인 경우 교환하지 않음
			temp = random[x];
			random[x] = random[y];
			random[y] = temp;
		}
	}
}

void printLine() {
	for (int i = 0; i < 30; i++)
		printf("-");
	printf("\n");
}

int countWords(char word[WORDMAX][STRMAX]) {
	int i = 0;
	while (strlen(word[i]) != 0)
		i++;
	return i;
}

void swapStructure(dayword* a, dayword* b) {
	dayword temp = *a;
	*a = *b;
	*b = temp;
}

void over() {
	printf("프로그램을 종료합니다.");
	exit(0);
}