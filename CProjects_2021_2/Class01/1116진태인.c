#include <stdio.h>
#include <windows.h>
#include <string.h>

#define MAX 50

void transcription(int* seq, char* Base, int start, int len, int* mRNA);// tata
void translation(char Base[5], int mRNA[MAX], char codon_protein[][3], char protein[][3], int start, int len);

int main()
{
	char Base[5] = { 'T','C','G','A','U' }; // 상보적 염기쌍 끼리 합이 3가 되도록 배열 선언
	char codon_protein[64][3] = { "AAA", "AAU", "AAG", "AAC", "AUA", "AUU", "AUC", "AUG",
		"AGA", "AGU", "AGG", "AGC", "ACA", "ACU", "ACG", "ACC", "UAA", "UAU", "UAG", "UAC", "UUA",
		"UUU","UUG","UUC","UGA","UGU","UGG","UGC","UCA","UCU","UCG","UCC","GAA","GAU","GAG","GAC",
		"GUA","GUU","GUG","GUC","GGA","GGU","GGG","GGC","GCA","GCU","GCG","GCC","CAA","CAU","CAG",
		"CAC","CUA","CUU","CUG","CUC","CGA","CGU","CGG","CGC","CCA","CCU","CCG","CCC"
	};
	char protein[64][3] = { "Lys","Asn","Lys","Asn","Ile","Ile","Ile","Met","Arg","Ser","Arg",
		"Ser","Thr","Thr","Thr","Thr","XXX","Tyr","XXX","Tyr","Leu","Phe","Leu","Phe","XXX","Cys",
		"Trp","abb","abc","abd","abe","abf","abg","abh","abi","abj","abk","abl","abm","abn","abo",
		"abp","abq","abr","abs","abt","abu","abv","abw","abx","aby","abz", "aca","acb","acc","acd",
		"ace","acf","acg","ach","aci","acj","ack","acl"
	};

	char DNA_sequence[MAX]; // 50개
	int sequence[MAX]; // 서열
	printf("Input DNA sequence that you want to analyze\n");
	Sleep(1500);
	printf("(Instructions: DNA sequence must include a single promoter and starting codon.)\n");
	printf("DNA: "); //
	gets(DNA_sequence);
	int DNA_len = strlen(DNA_sequence);
	int transcription_start;//임시로 0으로 초기화시켜놓음
	for (int i = 3; i < DNA_len; i++)
	{
		if (DNA_sequence[i - 3] == 'T' && DNA_sequence[i - 2] == 'A' && DNA_sequence[i - 1] == 'T' && DNA_sequence[i] == 'A')
		{
			transcription_start = i + 1;
			break;
		}
	}
	for (int i = 0; i < DNA_len; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (DNA_sequence[i] == Base[j])
				sequence[i] = j;
		}
	}
	int mRNA[MAX];
	transcription(sequence, Base, transcription_start, DNA_len, mRNA);

	int mRNA_len = DNA_len - transcription_start;
	int translation_start = 0;//임시로 0초기화
	for (int i = 0; i < mRNA_len - 2; i++)
	{
		if (mRNA[i] == 3 && mRNA[i + 1] == 4 && mRNA[i + 2] == 1)
		{
			translation_start = i + 1;
			break;
		}
	}

	translation(Base, mRNA, codon_protein, protein, translation_start, mRNA_len);

	return 0;
}

void transcription(int* seq, char* Base, int start, int len, int* mRNA)
{
	printf("mRNA : ");
	for (int i = start; i < len; i++)
	{
		if (seq[i] == 3)
			mRNA[i - start] = 4;
		else
			mRNA[i - start] = 3 - seq[i];
	}
	for (int i = 0; i < len - start; i++)
		printf("%c", Base[mRNA[i]]);
}

void translation(char Base[5], int mRNA[MAX], char codon_protein[][3], char protein[][3], int start, int len)
{
	char codon[64][3];
	for (int i = start; i < len; i += 3)
	{
		for (int j = 0; j < 3; j++)
		{
			codon[(i - start) / 3][j] = Base[mRNA[i + j]];
		}
	}

	for (int i = 0; i < (len - start) / 3; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (strcmp(codon[i], codon_protein[j]) == 0)
			{
				printf("%s - ", protein[j]);
			}
		}
	}
}