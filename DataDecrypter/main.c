#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

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

    for(i=0;i<strlen(source)-1;i++){
        if(j==strlen(key)){
            j=0;
        }
        ReturnKey[i]=key[j];
        j++;
        }
        return ReturnKey;
}

char *CDecrypt(char *source){
    int i;
    for(i=0;i<strlen(source)-1;i++){
     if(source[i]>=65 && source[i]<=90){
               source[i]=source[i]-3;
               if(source[i]<65){
                source[i]=90+(source[i]-64);
               }
        }
        if(source[i]>=97 && source[i]<=122){
            source[i]=source[i]-3;
               if(source[i]<97){
                source[i]=122+(source[i]-96);
               }
        }
    }
    return source;
}

char *VDecrypt(char *source, char *key){
    int i;
    for(i=0;i<strlen(source)-1;i++){
        if(source[i]>=65 && source[i]<=90){
                source[i]=(source[i]-65)-(key[i]-65);
                if(source[i]<0){
                source[i]=65+26+source[i];
                }else{
                    source[i]=source[i]+65;
                }
        }
        if(source[i]>=97 && source[i]<=122){
            source[i]=(source[i]-97)-(key[i]-97);
                if(source[i]<0){
                source[i]=97+26+source[i];
                }else{
                    source[i]=source[i]+97;
                }
                }
        }

        return source;
}
int main()
{   int i;
    s.top=-1;
    char name[10000];
    char container[10000];
    char VigKey[]="INFERNO";
    char *NamePtr;
    char *KeyPtr;
    printf("give a name: ");
    scanf("%s",&name);

    char GeneratedKey[strlen(name)];
    KeyPtr=VigKey;
    NamePtr=name;
    strcpy(GeneratedKey,GenKey(KeyPtr,NamePtr));    //key generated for Vignere

    NamePtr=name;
    strcpy(container,CDecrypt(NamePtr));             /*Caeser decryption done */
    KeyPtr=GeneratedKey;
    NamePtr=container;
    strcpy(container,VDecrypt(NamePtr,KeyPtr));     /*Vignere Decryption done*/

    for(i=strlen(name)-1;i>=0;i--){
        push(container[i]);
        fflush(stdin);
    }

    for(i=0;i<strlen(name);i++){
        name[i]=s.stack[i];                         /*reverse String*/
    }

    printf("Decrypted: %s\n",name);
    free(GeneratedKey);

}
