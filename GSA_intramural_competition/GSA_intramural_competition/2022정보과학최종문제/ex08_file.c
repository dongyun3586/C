#include <stdio.h>
int main(void) {
  int i;
  long int pos;
  FILE* fp = fopen("test.dat", "w+b");  // �б� �� ���� ���, ���� ���� ���

  for (i = 0; i < 10; i++)
    fwrite(&i, sizeof(int), 1, fp);     // https://modoocode.com/69
  pos = ftell(fp);                      // https://modoocode.com/74 ��Ʈ���� ��ġ �������� ���� ��ġ ��ȯ
  printf("pos=%ld\n", pos);
  fclose(fp);
}