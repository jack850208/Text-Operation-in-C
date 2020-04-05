#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int poschr(char str[],const char* key);
char *strlen(char str[], int pos, int len);

// Main Program
int main(int argc, char *argv[]){
	
	FILE *fp;
	char str[120];
	char *ptr,*tm;
	
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

	fgets(str,120,fp);

	printf("%s\n",strlen(str,poschr(str,"is"),sizeof("is")));
	fclose(fp);
	return 0;
}



/*************************************************************************
*				Position in String 
*	Usage:	str -> The String you want to search
*			key -> The key word you hope to search in input String
***************************************************************************/
int poschr(char str[],const char* key){
	
	int pos;
	char *tcp;
	
	tcp = strstr(str,key);
	pos = (&tcp[0] - &str[0])/sizeof(char);
	printf("%d\n",pos);
	
	return pos;
}

/*************************************************************************
*				Get a word form position in String 
*	Usage:	str ->	The string you want to search
*			pos ->	The position in the string
*			len ->	Lenth of String you want to get
*************************************************************************/

char *strlen(char *str, int pos, int len){
	
	char *ptr;
	char tm[len];
	int i;
	
	ptr = str + pos * sizeof(char);
	for(i = 0;i < len;i++){
		printf("%c",*(ptr+i));
		tm[i] = *(ptr + i);
		if(i == (len - 1)) printf("\n");
	}
	
	return tm;
	
}