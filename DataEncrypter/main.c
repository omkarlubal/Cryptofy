#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAXSIZE 500

struct stack{
    int top;
    char stack[MAXSIZE];
};
typedef struct stack STACK;
STACK s;

void push(char element){

    if(s.top ==(MAXSIZE-1)){
       printf("Stack is full!! ");
    }else{
        s.top = s.top+1;
        s.stack[s.top]=element;
    }
}


char *GenKey(char *key, char *source){
    int i=0,j=0;
    char *ReturnKey = malloc(sizeof(char) * strlen(source));

    for(i=0;i<strlen(source);i++){
        if(j==strlen(key)){
            j=0;
        }
        ReturnKey[i]=key[j];
        j++;
        }
        return ReturnKey;
}

char *VEncrypt(char *source, char *key){
    int i;
    for(i=0;i<strlen(source)-1;i++){
        if(source[i]>=65 && source[i]<=90){
                source[i]=(source[i]-65)+(key[i]-65);
                if(source[i]>25){
                source[i]=(source[i]-26)+65;
                }else{
                source[i]=source[i]+65;
                }
        }
        if(source[i]>=97 && source[i]<=122){
            source[i]=(source[i]-97)+(key[i]-97);
                if(source[i]>25){
                source[i]=(source[i]-26)+97;
                }else{
                source[i]=source[i]+97;
                }
        }
    }
    return source;
}

char *CEncrypt(char *source){
    int i;
    for(i=0;i<strlen(source)-1;i++){
     if(source[i]>=65 && source[i]<=90){
               source[i]=source[i]+3;
               if(source[i]>90){
                source[i]=64+(source[i]-90);
               }
        }
        if(source[i]>=97 && source[i]<=122){
            source[i]=source[i]+3;
               if(source[i]>122){
                source[i]=96+(source[i]-122);
               }
        }
    }
    return source;
}

int main()
{
    int i;
    s.top=-1;
    char name[10000];
    char container[10000];
    char VigKey[]="INFERNO";
    char *NamePtr;
    char *KeyPtr;
    printf("give a name: ");
    scanf("%s",&name);

    for(i=strlen(name)-1;i>=0;i--){
        push(name[i]);                      // String reversed
        fflush(stdin);
    }

    for(i=0;i<strlen(name);i++){
        name[i]=s.stack[i];
    }

    char GeneratedKey[strlen(name)];
    KeyPtr=VigKey;
    NamePtr=name;
    strcpy(GeneratedKey,GenKey(KeyPtr,NamePtr));    //key generated for Vignere

    KeyPtr=GeneratedKey;
    strcpy(container,VEncrypt(NamePtr,KeyPtr));     /* Vignere encryption done */


    NamePtr=container;
    strcpy(container,CEncrypt(NamePtr));             /* Caeser encryption done */
    printf("Encrypted: %s",container);
    free(GeneratedKey);

}
