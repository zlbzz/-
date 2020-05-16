#include<stdio.h>
#include<assert.h>
#include<string.h>
int CodeCount(char* Path)//�����ַ���������
{

	FILE* file = fopen(Path, "r");
	assert(file != NULL);    //���ļ��������򱨴�

	char code;
	int count = 0;

	while ((code = fgetc(file)) != EOF)     //��ȡ�ַ�ֱ������
		count++;    //������ʲô�ַ��������ո񣬻��з��������������    

	fclose(file);

	return count;
}

int WordCount(char* Path) {    //���㵥�ʸ�������

	FILE* file = fopen(Path, "r");
	assert(file != NULL);

	char word;
	int is_word = 0;    //���ڼ�¼�ַ��Ƿ��ڵ�����
	int count = 0;

	while ((word = fgetc(file)) != EOF) {
		if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {    //�ж��Ƿ�Ϊ��ĸ            
			count += (is_word == 0);
			is_word = 1;    //��¼����״̬
		}
		else
			is_word = 0;    //��¼�����ڵ���״̬
	}
	fclose(file);

	return count;
}
int main(int argc, char* argv[])
{
	if (!strcmp(argv[1], "-c"))
		printf("code count: %d\n", CodeCount(argv[2]));
	else if (!strcmp(argv[1], "-w"))
		printf("word count: %d\n", WordCount(argv[2]));
	else
		printf("������-c����-w!");
	return 0;
}
//�����ɽ������������������Ϊ������scanf�����ã�
//������������/c/Ԥ�����������м���  _CRT_SECURE_NO_WARNINGS
//ֱ��ִ�д���ᱨ������cmd�����ִ�� ��ʽ���£�wordcount -c test.txt