#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"


int poschr(char str[],const char* key);
char *strleng(char *str, int pos, int len);
void getword(char *s, int n, int strsize);

char wd[] = "Kind,Lot No,kdkdkd,good";


// Main Program
int main(int argc, char *argv[]){
	
	FILE *fp;
	char str[120];
	char *ptr,*sp;
	int k_len;

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
	
	do{
	
		fgets(str,120,fp);
		printf("%s",str);

		
		
	} while(poschr(str,"R e s u l t   M a p")==-1);
	
	getword(wd,4,sizeof(wd));
	
	fclose(fp);
	//free(sp);

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
	if(tcp==NULL) return -1;
	
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

char *strleng(char *str, int pos, int len){
	
	char *ptr,*sp;
	int i;
	
	sp = (char*)malloc((len+1)*sizeof(char));
	
	ptr = str + pos * sizeof(char);
	for(i = 0;i < len;i++){
		printf("%c",*(ptr+i));
		sp[i] = *(ptr + i);
	}
	sp[len] = '\0';
	
	//for(i=0;i < len;i++) printf("%c\n",sp[i]);
	
	return sp;
}


void getword(char *s, int n, int strsize){
	
	int i = 0, wf = 0,k = 0;
	int temp1 = 0,temp2=0,temp0=0;
	char *str;
	printf("%d\n",strsize);
	do {
		printf("i is:%d\n",i);
		printf("wf is:%d\n",wf);
		if(i == 19) k =-1;
		if(s[i] == ',') {
	

			wf++;
		
			if(n == 1){
				temp2 = i;
				temp0 = 0;
				k = -1;
				printf("statement1\n");
			}
			
			if((wf == n)&&(n != 1)){
				temp2 = i;
				temp0 = temp1+1;
				k = -1;
				printf("statement2\n");
			}
			
			/*
			else{
				temp2 = strsize;
				temp0 = temp1;
				k = -1;
				printf("statement3\n");
			}
			*/
			temp1 = i;
		}

		if(k == -1) break;
		
		i++;

	} while(1);
	k = 0;
	if(wf < n){
		temp2 = strsize+1;
		i--;
		while(k != -1){
			if(s[i] == ','){
				temp0 = i + 1;
				k = -1;
			}
			i--;
		}
	}
	
	printf("temp1:%d,temp2:%d\n",temp0,temp2);
	
	str = (char*)malloc((temp2-temp0)*sizeof(char));
	str = strleng(s,temp0,temp2-temp0);
	
	printf("string:%s\n",str);

	free(str);
}