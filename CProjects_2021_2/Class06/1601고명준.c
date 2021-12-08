#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<wchar.h>
#include<locale.h>
#include<windows.h>
wchar_t shape[4] = { L'♠',L'◆',L'♥',L'♣' }; // 카드를 출력할 때 사용될 모양
char* player[4] = { "user","com1","com2","com3" }; // 순서를 출력할 때 사용될 문자열 배열
int k = 0, n = 0, dir = 1; //k는 순서,n은 총 게임 참가자의 수(user+com),dir 턴이 돌아가는 방향
typedef struct {//카드 한 장
	int num;//카드 숫자 1 = A, 11 = K, 12 = Q, 13 = J // 카드의 수
	wchar_t shape; // 카드의 모양
}Card;
typedef struct {//카드 꾸러미
	Card* card; //카드들
	int count; //카드의 개수
}CardPack;
Card PickCard(CardPack* card, int i) {//뽑고자 하는 순서의 카드를 뽑고 CardPack 재정렬
	Card pick = card->card[i];//뽑은 카드
	for (int j = i; j < (card->count) - 1; j++)
		card->card[j] = card->card[j + 1];
	(card->count)--;
	return pick;
}
void PrintCard(Card* card, int i) { // 가지고 있는 카드들 출력
	printf("\n");
	for (int j = 0; j < i; j++)	wprintf(L"|%c  | ", (card + j)->shape);
	printf("\n");
	for (int j = 0; j < i; j++)	printf("|    | ");
	printf("\n");
	for (int j = 0; j < i; j++) {
		if ((card + j)->num == 1) {
			wprintf(L"|   A| ");
		}
		else if ((card + j)->num == 11) {
			wprintf(L"|   K| ");
		}
		else if ((card + j)->num == 12) {
			wprintf(L"|   Q| ");
		}
		else if ((card + j)->num == 13) {
			wprintf(L"|   J| ");
		}
		else {
			printf("|  %2d| ", (card + j)->num);
		}
	}printf("\n");
}
void Check(Card gameCard, CardPack card, int* Can, int* countCan, int j) { //gameCard와 비교했을 때 card에서 낼 수 있는 카드의 배열 생성,Can 낼 수 있는 카드 배열,count 낼 수 있는 카드 수,j com인지 user인지 체크하기 위한 인자
	if (j)	printf("\n낼 수 있는 카드\n"); //j를 통해 com인지 user인지 체크
	*countCan = 0;//초기화
	for (int i = 0; i < 19; i++) { //초기화
		Can[i] = 0;
	}
	for (int i = 0; i < card.count; i++) {//비교 후 배열에 가능한 카드의 순서 출력 +배열에 넣기
		if (gameCard.num == card.card[i].num || gameCard.shape == card.card[i].shape) {
			if (j)	printf("%d번 ", i + 1);
			Can[*countCan] = i;
			++* countCan;
		}
	}if (j)	printf("\n");
}
void Game(Card* gameCard, CardPack* play, CardPack* card) {//게임 진행
	char i = 0;
	Sleep(1000); //delay 1초
	printf("\n----------------------%s---------------------\n", player[k]);//누구 순서인지 출력
	printf("남은 카드 : %d개", play->count);//남은 카드 출력
	int Can[19] = { 0 }; //낼 수 있는 카드의 순서를 받을 배열
	int countCan = 0; //낼 수 있는 카드의 개수를 받을 변수
	if (!k) {//user인지 아닌지 판단, k = 0이면 user로 밑의 안내 코드 실행
		printf("\ngameCard\n");
		PrintCard(gameCard, 1);
		printf("\nyour Card\n");
		PrintCard(play->card, play->count);
	}
	Check(*gameCard, *play, Can, &countCan, !k);//낼 수 있는 카드 체크
	if (countCan == 0) {//낼 수 있는 카드가 없으면 실행
		printf("\n낼 수 있는 카드가 없습니다.\n카드를 가져옵니다.");
		if (!k) {
			rewind(stdin);
			getchar(i);
			Sleep(1000); // enter 누르고 1초 delay 후 실행
		}
		play->card[play->count] = PickCard(card, rand() % (card->count));//전체 카드에서 랜덤으로 카드 한 개 가져옴
		if (!k) { // user일 시 안내
			printf("\n가져온 카드");
			PrintCard(play->card + play->count, 1);
		}
		--(card->count);
		++(play->count);
	}
	else {//낼 카드가 있으면
		int choose;
		int j = 0;
		if (!k) {
			printf("낼 카드를 선택하세요");
			while (1) {//낼 수 있는 카드 선택할 때까지 낼 카드 입력
				scanf("%d", &choose);
				for (int i = 0; i < countCan; i++) {
					if (choose == Can[i] + 1) {
						j = 1;
						break;
					}
				}if (j) {
					break;
				}
				else {
					printf("\n낼 수 있는 카드를 선택해주세요.");
				}
			}
		}
		card->card[card->count] = *gameCard;//기존에 있던 gameCard 전체 card 카드팩으로
		++card->count;
		if (k)	*gameCard = PickCard(play, Can[rand() % countCan]); // com이면 랜덤으로 gameCard로
		else    *gameCard = PickCard(play, choose - 1);//user면 선택한 카드 gameCard로
		switch (gameCard->num) {//K,Q,J등의 특수 카드 기능들
		case(11):
			k -= dir;
			break;
		case(12):
			dir = -dir;
			break;
		case(13):
			k += dir;
			break;
		default:
			break;
		}

	}
	printf("\ngameCard\n");
	PrintCard(gameCard, 1);//현재 gameCard 출력
	k += dir; // 순서 넘어가기
	if (k < 0)	k += n;
	if (k / n != 0)	k = k % n;
}
int main() {
	setlocale(LC_ALL, "");//유니코드를 사용하기 위한 위치 지정
	printf("몇 개의 컴퓨터와 플레이하시겠습니까?(최대 3개)\n");
	while (1) {
		scanf("%d", &n);//플레이할 com 수 입력
		if (n >= 4 || n <= 0)	printf("최대 3개까지 가능합니다. 다시 입력해주세요.\n");
		else   break;
	}
	n++;//user 추가
	Card gameCard;//게임에서 내져 있는 카드
	CardPack card;//전체 카드 더미
	CardPack* play_ = malloc(sizeof(CardPack) * n);//필요한 player 수만큼 카드 더미 메모리 할당
	card.card = malloc(sizeof(Card) * 52); // card에 카드 52장 메모리 할당
	card.count = 0;//초기화
	for (int i = 0; i < n; i++) {//player 댁 카드 메모리 할당 및 초기화
		play_[i].card = malloc(sizeof(Card) * 19);
		play_[i].count = 0;
	}
	int win = 0, end = 0; // win 이긴 사람,end 게임의 종료 여부
	for (int i = 0; i < 4; i++) { // card에 조커를 뺀 원카드 전체카드 넣기
		for (int j = 1; j <= 13; j++) {
			card.card[card.count].num = j;
			card.card[card.count].shape = shape[i];
			card.count++;
		}
	}
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {//card 섞기
		int r = rand() % 52;
		Card temp = card.card[i];
		card.card[i] = card.card[r];
		card.card[r] = temp;
	}
	gameCard = PickCard(&card, rand() % card.count);//랜덤으로 카드 한 개 gameCard로
	for (int i = 0; i < n; i++) {//플레이어 카드 7장씩 분배
		for (int j = 0; j < 7; j++) {
			play_[i].card[play_[i].count] = PickCard(&card, rand() % card.count);
			play_[i].count++;
		}
	}
	printf("게임을 시작합니다.\n");//시작
	while (!end) {//end = 1일 때까지 실행
		Game(&gameCard, &play_[k], &card);//게임 실행
		for (int i = 0; i < n; i++) {//카드 개수가 0이 된 player가 있는 지 감지
			if (play_[i].count == 0) {
				win = i; // 승자
				end = 1; // 종료
			}
		}

	}
	if (win == 0) {//user가 승자이면
		printf("승리하셨습니다.");
	}
	else {
		printf("패배하셨습니다.");
	}
}