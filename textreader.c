#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void printFile(FILE* file,int skip){
    char c;
    int number=0;
    while((c=fgetc(file))!=EOF){
if(skip==1) printf("%c",c);
else {
	if(++number==skip){
            printf("%c",c);
break;
    }}
}
}
int main(int argc,char* argv[]){
    if(argc==1){
        printf("Wrong arguments\n");
        printf("Usage: ./program [-Z] filename1.txt\n");
        return 0;
    }
    int isFlag = 1,charNum=1;

    if(!strcmp(argv[1],"-Z")){
        isFlag=3;
        int idx=0;
        while(argv[2][idx]!='\0'){
            if(!isdigit(argv[2][idx++])){
                printf("Error: wrong parameter: \n");
                printf("second argument is not a digit\n");
                return 0;
            }
        }
        charNum=atoi(argv[2]);

    }
    for(int i=isFlag;i<argc;i++){
        FILE* file;
        file=fopen(argv[i],"r");
        if(file==NULL) {
            printf("Error: cannot open file: ");
            printf("%s",argv[i]);
            printf("\n");
            continue;
        }
        printf("Open file: ");
        printf("%s\n",argv[i]);
        printFile(file,charNum);
        fclose(file);
        printf("\nClose file: ");
        printf("%s\n",argv[i]);
    }
    return 0;
}
