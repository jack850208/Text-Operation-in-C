#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int poschr(char str[],const char* key);

int main(int argc, char *argv[]){
	
	FILE *fp;
	char str[120];
	char *ptr,*tm;
	int f;
	
	// judgement the syntax if correct
	if(argc != 2){
		printf("請確認參數是否輸入正確\n");
		printf("用法：text_read [檔案名稱.txt]\n");
		exit(1);
	}
	
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("檔案開啟失敗，請檢查路徑或檔名是否輸入正確！\n");
		exit(1);
	}
	/*
	while(fgets(str,120,fp)){
		printf("%s",str);
	}
	*/
	
	printf("%p\n",&tm);
	printf("%p\n",&ptr);
	printf("%p\n",*ptr);
	printf("%p\n",&str);
	ptr = fgets(str,120,fp);
	tm = strstr(ptr,"ack");
	printf("%d\n",strlen("Jack"));
	printf("J address in ptr:%p\n",&tm[0]);
	printf("J address +1 in ptr:%p\n",&tm[1]);
	printf("J value in ptr:%c\n",tm[0]);
	printf("J value in ptr+1:%c\n",tm[1]);
	poschr(str,"ack");
	free(ptr);
	fclose(fp);
}


int poschr(char str[],const char* key){
	
	int pos;
	char *tcp;
	
	tcp = strstr(str,key);
	pos = (&tcp[0] - &str[0])/sizeof(char) + 1;
	printf("%d\n",pos);
	
	return pos;
}
