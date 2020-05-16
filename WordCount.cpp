#include<stdio.h>
#include<assert.h>
#include<string.h>
int CodeCount(char* Path)//计算字符个数函数
{

	FILE* file = fopen(Path, "r");
	assert(file != NULL);    //若文件不存在则报错

	char code;
	int count = 0;

	while ((code = fgetc(file)) != EOF)     //读取字符直到结束
		count++;    //不论是什么字符，包括空格，换行符都将其计算在内    

	fclose(file);

	return count;
}

int WordCount(char* Path) {    //计算单词个数函数

	FILE* file = fopen(Path, "r");
	assert(file != NULL);

	char word;
	int is_word = 0;    //用于记录字符是否处于单词中
	int count = 0;

	while ((word = fgetc(file)) != EOF) {
		if ((word >= 'a' && word <= 'z') || (word >= 'A' && word <= 'Z')) {    //判断是否为字母            
			count += (is_word == 0);
			is_word = 1;    //记录单词状态
		}
		else
			is_word = 0;    //记录不处于单词状态
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
		printf("请输入-c或者-w!");
	return 0;
}
//若生成解决方案报错，可能是因为代码中scanf不能用，
//请在配置属性/c/预处理器定义中加入  _CRT_SECURE_NO_WARNINGS
//直接执行代码会报错，请在cmd命令窗口执行 格式如下：wordcount -c test.txt