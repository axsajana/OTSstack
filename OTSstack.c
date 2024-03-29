#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

char bentuk_kurung[MAX_SIZE];
int top = -1;

int kurung(char karakter_kurung){
    switch (karakter_kurung){
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return 'X';
    }
}

int isempty(){//0
	if(top == -1)
		return 1;
	else
		return 0;
}

int isfull(){
   if(top == MAX_SIZE-1)
      return 1;
   else
      return 0;
}

char peek(){
   return bentuk_kurung[top];
}

char pop(){
    char data;
    if(!isempty()) {
        data = bentuk_kurung[top];
        top -= 1;
        return data;
    } else {
        printf("Stack Kosong.\n");
   }
}

void push(char data){
	if(!isfull()) {
		top += 1;
		bentuk_kurung[top] = data;
	} else {
		printf("Stack Penuh.\n");
	}
};

int isBalanced(char kurung1[]){
    for(int i = 0; i < strlen(kurung1); i++){
        if(kurung1[i] == '(' || kurung1[i] == '{' || kurung1[i] == '[') {
            push(kurung1[i]);

        } else if(kurung1[i] == ')' || kurung1[i] == '}' || kurung1[i] == ']') {
            if(isempty() || kurung(kurung1[i]) != peek()) {
                printf("NO\n");
                return 0;
            } else {
                pop();
            }
        }
    }

    if(isempty()) {
        printf("YES\n");
        return 1;
    } else {
        printf("NO\n");
        return 0;
    }
}

int cekInput(char kurung1[]){
    for(int i = 0; i < strlen(kurung1); i++){
        if(kurung1[i] != '(' && kurung1[i] != '{' && kurung1[i] != '[' && kurung1[i] != ')' && kurung1[i] != '}' && kurung1[i] != ']'){
            return 0;
        }
    }
    return 1;
}

int main(){

char kurung1[MAX_SIZE];

    printf("Masukkan Kurung: ");
    fgets(kurung1,50,stdin);
    kurung1[strcspn(kurung1, "\n")] = 0;

    if(cekInput(kurung1)){
        isBalanced(kurung1);
    } else {
        printf("Input tidak valid. Hanya menerima tanda kurung.\n");
    }

    return 0;
}