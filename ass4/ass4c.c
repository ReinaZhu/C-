#include <stdio.h>
#include "utf8.h"
#include <string.h>
unsigned int StringToInt(char* str_number);

struct every_block{
    char name[100];
    unsigned int start;
    unsigned int end;
};
struct every_block split(const char* line);
int main(){
    unsigned int   codepoint;
    int            bytes_in_char;
    struct every_block block_array[300];


    FILE *blocks;
    char a_line[1024];
    a_line[1]='\0';
    blocks = fopen("blocks.txt", "r");
    if(blocks == NULL)
    {
        printf("blocks name is error!");
        return -1;
    }
    int count=0;
    do{
        fgets(a_line,1024,blocks);
        count++;
    }while(count<34);
    count=0;
    while(fgets(a_line,1024,blocks)!=NULL){
        block_array[count]=split(a_line);
        count++;
    }


    char pp[1024];
    int country_count[count];
    int num=0;
    while(num<count){
        country_count[num]=0;
        num++;
    }
    while(scanf("%s",pp)!=EOF) {
        unsigned char *p = (unsigned char *) pp;
        while (*p) {
            codepoint = utf8_to_codepoint(p, &bytes_in_char);
            if (codepoint) {
                for(int j=0;j<count;j++){
                    if(codepoint>block_array[j].start&&codepoint<block_array[j].end){
                        country_count[j]+=1;
                    }
                }

                p += bytes_in_char;  // Same as the line that follows
                //_utf8_incr(p);
            } else {
                p++;  // Try the next character
            }
        }
    }
    int max=0;
    int index=0;
    for(int j=0;j<count;j++){
        if(country_count[j]>max){
            max=country_count[j];
            index=j;
        }
    }
    printf("It should be %s",block_array[index].name);
    fclose(blocks);

    return 0;
}
struct every_block split(const char* line){
    struct every_block this_block;
    unsigned char * str=(unsigned char*)line;
    int len=utf8_charlen(str);
    char split_word[3][100];
    int start=0;
    for(int i=0;i<len-1;i++) {
        if (line[i] == '.' && line[i + 1] == '.') {
            strncpy(split_word[0],line,i);
            split_word[0][i]='\0';
            start = i + 2;
        }
        if (line[i] == ';') {
            strncpy(split_word[1],line+start,i-start);
            split_word[1][i-start]='\0';
            start = i + 2;
        }
    }
    strncpy(split_word[2],line+start,len-start);
    split_word[2][len-start]='\0';
    this_block.start= StringToInt(split_word[0]);
    this_block.end= StringToInt(split_word[1]);
    strcpy(this_block.name,split_word[2]);


    return this_block;
}
unsigned int StringToInt(char* str_number){
    unsigned char * str=(unsigned char*)str_number;
    int value=0;
    int len=utf8_charlen(str);
    for(int i=0;i<len;i++){
        int val;
        if(str_number[i]=='A'){
            val=10;
        }
        else if(str_number[i]=='B'){
            val=11;
        }
        else if(str_number[i]=='C'){
            val=12;
        }
        else if(str_number[i]=='D'){
            val=13;
        }
        else if(str_number[i]=='E'){
            val=14;
        }
        else if(str_number[i]=='F'){
            val=15;
        }
        else{
            val=str_number[i]-48;
        }
        int time=1;
        for(int j=len-1;j>i;j--){
            time=16*time;
        }
        value+=val*time;
    }
    return value;
}
