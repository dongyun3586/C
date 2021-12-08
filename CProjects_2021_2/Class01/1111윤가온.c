#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include"UserDefinedLibrary.h"//헤더파일 불러오기
#define WORD_MAX 20
#define SENT_MAX 100
#define PARA_MAX 1200
//단어, 문장, 글의 최대 글자수를 상수로 지정ㄴ
int main() {
	srand(time(NULL));
	int mode;
	char words[200][WORD_MAX] = { "apple","aussie","astronaut","ascend","agriculture","assign","alaska","dallas",
		"fall","ask","flask","sad","leak","fear","leaf","lake","safe","seal","conceal","fade","commute",
		"route","detour","fine","notice","meander","diverge","navigate","hail","transfer","direction",
		"charter","convenient","designate","curb","fare","bypass","commission","moor","run","cushion",
		"pandemonium","convoluted","veer","cramped","opposite","interrupt","borrow","locate","recommend",
		"destination","disregard","bound","rapid","acute","transport","avenue","backseat","blame","block",
		"descent","direct","drive","garage","instant","mileage","mount","path","sidewalk","trouble","vehicle",
		"accelerate","awkward","backward","bald","crawl","dealership","dent","detach","expire","cab","grab",
		"guidepost", "hull","clue","glue","impassable","intact","intersect","intersaction","lane","transit",
		"midway","motion","sickness","park","ticket","passage","pavement","pedestrian","permission","permit",
		"puncture","shortcut","skid","wheel","stop","toll","total","transparent","toe","attrition","elapse",
		"deviate","desist","deflect","jolt","jargon","hamper","roadworthy","strident","swerve","validate",
		"windshield","wobble","frugal","mortgage","loan","statement","recession","stimulate","galvanize",
		"ensure","compensate","account","plummet","remuneration","reimburse","deficit","currency","subsidy",
		"redeem","tally","disparity","budget","endow","skyrocket","rebound","persistant","abundant","eliminate",
		"stock","moratorium","parity","pitch","rig","fund","prospect","appraise","recoup","plunge","demand",
		"unfettered","deposit","crisis","sustain","property","trade","fake","soar","virus","bankrupt","broke",
		"burden","capital","capitalism","circumstance","commodity","cover","coverage","debt","earnings",
		"financial","income","interest","rate","investment","liability","marketplace","monopolize","monopoly",
		"poverty","profitable","share","accumulate","allocate","auspicious","beneficiary","bond","bourgeois" };
	//단어 연습에 사용되는 단어들이 담긴 배열
	char sentences[100][SENT_MAX] =
	{ "The greatest glory in living lies not in never falling, but in rising every time we fall.",
	"The way to get started is to quit talking and begin doing.",
	"Your time is limited, so don't waste it living someone else's life.",
	"If life were predictable it would cease to be life, and be without flavor.",
	"Everything you can imagine is real.",
	"Have enough courage to start and enough heart to finish.",
	"Life is what happens when you're busy making other plans.",
	"Spread love everywhere you go. Let no one ever come to you without leaving happier.",
	"When you reach the end of your rope, tie a knot in it and hang on.",
	"Always remember that you are absolutely unique. Just like everyone else.",
	"Don't judge each day by the harvest you reap but by the seeds that you plant.",
	"The future belongs to those who believe in the beauty of their dreams.",
	"Tell me and I forget. Teach me and I remember. Involve me and I learn.",
	"A mind is like a parachute. It doesn't work if it isn't open.",
	"It is during our darkest moments that we must focus to see the light.",
	"Whoever is happy will make others happy too.",
	"Do not go where the path may lead, go instead where there is no path and leave a trail.",
	"Spread love everywhere you go. Let no one ever come to you without leaving happier.",
	"When you reach the end of your rope, tie a knot in it and hang on.",
	"Always remember that you are absolutely unique. Just like everyone else.",
	"Don't judge each day by the harvest you reap but by the seeds that you plant.",
	"The future belongs to those who believe in the beauty of their dreams.",
	"The journey of a thousand miles begins with one step.",
	"That which does not kill us makes us stronger.",
	"Life is what happens when you're busy making other plans.",
	"When the going gets tough, the tough get going.",
	"You must be the change you wish to see in the world.",
	"You only live once, but if you do it right, once is enough.",
	"Tough times never last but tough people do.",
	"Get busy living or get busy dying.",
	"Whether you think you can or you think you can't, you're right.",
	"Tis better to have loved and lost than to have never loved at all.",
	"A man is but what he knows.",
	"You miss 100 percent of the shots you never take.",
	"If you're going through hell, keep going.",
	"Strive not to be a success, but rather to be of value.",
	"Never regret anything that made you smile.",
	"Great minds discuss ideas; average minds discuss events; small minds discuss people.",
	"Those who dare to fail miserably can achieve greatly.",
	"The opposite of love is not hate; it's indifference.",
	"Never let the fear of striking out keep you from playing the game.",
	"Life is like a box of chocolates. You never know what you're going to get.",
	"He that falls in love with himself will have no rivals.",
	"Life is ten percent what happens to you and ninety percent how you respond to it.",
	"Dream big and dare to fail.",
	"A great man is always willing to be little.",
	"That's one small step for a man, one giant leap for mankind.",
	"Every man is guilty of all the good he did not do.",
	"A successful man is one who can lay a firm foundation with the bricks others have thrown at him.",
	"In three words I can sum up everything I've learned about life: It goes on.",
	"If you judge people, you have no time to love them.",
	"The future belongs to those who prepare for it today.",
	"Don't be afraid to give up the good to go for the great.",
	"The greatest glory in living lies not in never falling, but in rising every time we fall.",
	"No one can make you feel inferior without your consent.",
	"In the long run, the sharpest weapon of all is a kind and gentle spirit.",
	"Change the world by being yourself.",
	"Do what you can, with what you have, where you are.",
	"People are just as happy as they make up their minds to be.",
	"Try not to become a man of success. Rather become a man of value.",
	"Success is not final, failure is not fatal: it is the courage to continue that counts.",
	"Remember that the happiest people are not those getting more, but those giving more.",
	"The only impossible journey is the one you never begin.",
	"It is better to fail in originality than to succeed in imitation.",
	"I have no special talent. I am only passionately curious.",
	"The only person you are destined to become is the person you decide to be.",
	"May you live all the days of your life.",
	"May the Force be with you",
	"We have nothing to fear but fear itself.",
	"Those who cannot remember the past are condemned to repeat it.",
	"The only thing necessary for the triumph of evil is for good men to do nothing.",
	"Insanity is doing the same thing over and over again and expecting different results.",
	"Life would be tragic if it weren't funny.",
	"It is never too late to be what you might have been.",
	"The power of imagination makes us infinite.",
	"Everything you've ever wanted is on the other side of fear.",
	"We design our lives through the power of choices.",
	"Shoot for the moon. Even if you miss, you'll land among the stars.",
	"If you tell the truth, you don't have to remember anything.",
	"Knowing yourself is the beginning of all wisdom.",
	"We are what we repeatedly do; excellence, then, is not an act but a habit.",
	"Life is not a problem to be solved, but a reality to be experienced.",
	"All that we see and seem is but a dream within a dream.",
	"The question isn't who is going to let me; it's who is going to stop me.",
	"Hate comes from intimidation, love comes from appreciation.",
	"What you do speaks so loudly that I cannot hear what you say.",
	"Those who make you believe absurdities can make you commit atrocities.",
	"You can discover more about a person in an hour of play than in a year of conversation.",
	"Once you've accepted your flaws, no one can use them against you.",
	"When we strive to become better than we are, everything around us becomes better too.",
	"Be so good they can’t ignore you.",
	"Challenges are what make life interesting and overcoming them is what makes life meaningful.",
	"You will face many defeats in life, but never let yourself be defeated.",
	"Keep your face to the sunshine and you can never see the shadow.",
	"Always forgive your enemies; nothing annoys them so much.",
	"Power tends to corrupt, and absolute power corrupts absolutely.",
	"Do not go where the path may lead; go instead where there is no path and leave a trail.",
	"Those who cannot remember the past are condemned to repeat it.",
	"Nothing is impossible, the word itself says,'I'm possible!'",
	"A mind is like a parachute. It doesn't work if it isn't open." };
	//문장연습에 사용되는 문장들이 담긴 배열
	char article[3][PARA_MAX] =
	{ "Developing expertise carries costs of its own.We can become experts in some areas,like speaking a language or knowing our favorite foods,simply by living our lives,but in many other domains expertise requires considerable training and effort.What's more,expertise is domain specific.The expertise that we work hard to acquire in one domain will carry over only imperfectly to related ones,and not at all to unrelated ones.In the end,as much as we may want to become experts on everything in our lives,there simply isn't enough time to do so.Even in areas where we could,it won't necessarily be worth the effort.It's clear that we should concentrate our own expertise on those domains of choice that are most common and /or important to our lives,and those we actively enjoy learning about and choosing from.",
	"Difficulties arise when we do not think of people and machines as collaborative systems,but assign whatever tasks can be automated to the machines and leave the rest to people.This ends up requiring people to behave in machine - like fashion,in ways that differ from human capabilities.We expect people to monitor machines,which means keeping alert for long periods,something we are bad at.We require people to do repeated operations with the extreme precision and accuracy required by machines,again something we are not good at.When we divide up the machine and human components of a task in this way,we fail to take advantage of human strengths and capabilities but instead rely upon areas where we are genetically,biologically unsuited.Yet,when people fail,they are blamed.",
	"Creative thinking requires our brains to make connections between seemingly unrelated ideas.Is this a skill that we are born with or one that we develop through practice?Let's look at the research to uncover an answer.In the 1960s,a creative performance researcher named George Land conducted a study of 1,600 five-year-olds and 98 percent of the children scored in the 'highly creative' range.Dr Land re-tested each subject during five year increments.When the same children were 10-years-old,only 30 percent scored in the highly creative range.This number dropped to 12 percent by age 15 and just 2 percent by age 25.As the children grew into adults they effectively had the creativity trained out of them.In the words of Dr Land,'non-creative behavior is learned'.",
	};
	//글 연습에 사용되는 글들이 담긴 배열
	SetConsoleTitle(TEXT("타자연습프로그램"));//창제목 변경
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);//전체화면으로 변환
	while (1) {
		system("cls");
		rewind(stdin);
		mode = startmenu();//연습 선택함수
		system("cls");
		switch (mode) {
		case 1:
			charprac();//글자 연습함수
			break;
		case 2:
			wordprac(words);//단어 연습함수, main함수에서 정의된 words 배열을 넘김
			break;
		case 3:
			sentprac(sentences);//문장연습함수, main함수에서 정의된 sentences 배열을 넘김
			break;
		case 4:
			articprac(article);//글 연습 함수, main함수에서 정의된 sentences 배열을 넘김
			break;
		case 5:
			return 0;
		}
	}
}
