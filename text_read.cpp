#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int poschr(char str[],const char* key);
char *strleng(char *str, int pos, int len);
void getword(char *s, int n);

char wd[] = "Kind,Lot No,kdkdkd";


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
	
	getword(wd,2);
	
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
	
	sp = (char*)malloc(len*sizeof(char));
	
	ptr = str + pos * sizeof(char);
	for(i = 0;i < len;i++){
		printf("%c",*(ptr+i));
		sp[i] = *(ptr + i);
		if(i == (len - 1)) printf("\n");
	}
	
	//for(i=0;i < len;i++) printf("%c\n",sp[i]);
	
	return sp;
}


void getword(char s[], int n){
	
	int i = 0, c = 0, temp = 0;
	
	do {
		
		if(ispunct(s[i])){
			c++;
			if(c < n){
				temp = i;
			}
			else{
				temp = i - temp;
			}
		}
		i++;
		if(c = n-1){
			temp = sizeof(s) - i + 1;
			c++;
		}
	} while(c != n);
	
	printf("%d\n",i);
	printf("%d\n",temp);
}