#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define TRUE 1
#define FALSE 0
#define SIZE 20

typedef struct {
    char c;
    int lv;
} Node;

Node* newNode(char _c, int _lv){
    Node* newnode = malloc(sizeof(Node));
    newnode->c = _c;
    newnode->lv = _lv;
    return newnode;
}

bool in(char* str, char c){
    int i = 0;
    while(str[i] != '\0'){
        if ( str[i] == c) return TRUE;
        i++;
    }
    return FALSE;
}

void split(char* str, char* insStr, int insIte, int _lv, Node* Ans[], int* ansIte){
    while ( !in( str, insStr[insIte] ) ){
        insIte++;
        if (insIte == strlen(insStr) ){
            return;
        }
    }
    Ans[*ansIte] = newNode(insStr[insIte], _lv);
    Ans[*ansIte]->c = insStr[insIte];
    Ans[*ansIte]->lv = _lv;
    *ansIte += 1;
    int len = strlen(str);
    char* left = malloc(len * sizeof(char));
    char* right = malloc(len * sizeof(char));
    int ite = 0;
    while ( str[ite] != insStr[insIte] ){
        left[ite] = str[ite];
        ite++;
    }
    left[ite] = '\0';
    ite++;
    while (str[ite] != '\0'){
        right[ite - strlen(left)-1] = str[ite];
        ite++;
    }
    right[ite - strlen(left)-1] = '\0';
    if (insIte == strlen(insStr) - 1 ) return;
    split(left, insStr, insIte+1, _lv+1, Ans, ansIte);
    split(right, insStr, insIte+1, _lv+1, Ans, ansIte);
}

void getInput(char* c, char* str){
    scanf("%c%*c", c);
    gets(str);
}

char* strRev(char *str){
    int len = strlen(str);
    char* newStr = malloc(len*sizeof(char));
    for (int i = len-1; i >= 0; i--){
        newStr[len - i - 1] = str[i];
    }
    return newStr;
}

int main(){
    char type1;
    char str1[SIZE];
    char type2;
    char str2[SIZE];
    getInput(&type1, str1);
    getInput(&type2, str2);
    int len = strlen(str1);
    Node* nodes[SIZE];
    int nodeIte = 0;
    char* str;
    char* ins;
    if (type1 == 'I'){
        str = str1;
        switch (type2){
        case 'P':
            ins = str2;
            break;
        case 'O':
            ins = strRev(str2);
            break;
        }
    }
    else if (type2 == 'I') {
        str = str2;
        switch (type1){
        case 'P':
            ins = str1;
            break;
        case 'O':
            ins = strRev(str1);
            break;
        }
    }
    split(str, ins, 0, 0, nodes, &nodeIte);

    for(int i = 0; i < SIZE; i++){
        for (int j = 0; j < nodeIte; j++){
            if (nodes[j]->lv == i){
                printf("%c", nodes[j]->c);
            }
        }
    }
    return 0;
}

