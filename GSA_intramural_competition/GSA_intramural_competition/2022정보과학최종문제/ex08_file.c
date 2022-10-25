#include <stdio.h>
int main(void) {
  int i;
  long int pos;
  FILE* fp = fopen("test.dat", "w+b");  // 읽기 및 쓰기 모드, 이진 형식 모드

  for (i = 0; i < 10; i++)
    fwrite(&i, sizeof(int), 1, fp);     // https://modoocode.com/69
  pos = ftell(fp);                      // https://modoocode.com/74 스트림의 위치 지정자의 현재 위치 반환
  printf("pos=%ld\n", pos);
  fclose(fp);
}