#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    char* stack;
};
struct Stack_int{
    int top;
    int* stack;
};

struct Stack* create(){
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack*));
    S->stack = NULL;
    S->top = -1;
    return S;
}
struct Stack_int* create_int(){
    struct Stack_int* S = (struct Stack_int*)malloc(sizeof(struct Stack_int*));
    S->stack = NULL;
    S->top = -1;
    return S;
}

void display(struct Stack* stack){
    printf("\n----------stack-----------\n");
    printf("--------------------------\n");
    for(int i =0;i<=stack->top;i++){
        printf(" %c ->",stack->stack[i]);
    }
    printf("\n--------------------------\n");
}

void display_int(struct Stack_int* stack){
    printf("\n-------stack-int--------\n");
    printf("--------------------------\n");
    for(int i =0;i<=stack->top;i++){
        printf(" %d ->",stack->stack[i]);
    }
    printf("\n--------------------------\n");
}


char top(struct Stack* S){
    if(S->top==-1){return '\0';}
    return S->stack[0];
}

int top_int(struct Stack_int* S){
    if(S->top==-1){return 0;}
    return S->stack[0];
}

struct Stack* push(struct Stack* stack, char val){
    if(stack->top==-1){
        stack->top++;
        stack->stack = (char*)malloc(sizeof(char)*stack->top+1);
        stack->stack[0] = val;
    } else {
        stack->top++;
        char* k = (char*)malloc(sizeof(char)*stack->top+1);
        for(int i = 1;i<=stack->top;i++){
            k[i] = stack->stack[i-1];
        }
        k[0] = val;
        stack->stack = k;
    }
    return stack;
}
struct Stack_int* push_int(struct Stack_int* stack, int val){
    if(stack->top==-1){
        stack->top++;
        stack->stack = (int*)malloc(sizeof(int)*stack->top+1);
        stack->stack[0] = val;
    } else {
        stack->top++;
        int* k = (int*)malloc(sizeof(int)*stack->top+1);
        for(int i = 1;i<=stack->top;i++){
            k[i] = stack->stack[i-1];
        }
        k[0] = val;
        stack->stack = k;
    }
    return stack;
}


struct Stack* pop(struct Stack* S){
    if(S->top == -1){
        return NULL;
    }
    if(S->top == 0){
        S->top--;
        S->stack = NULL;
    } else {
        S->top--;
        char* k = (char*)malloc(sizeof(char)*S->top+1);
        for(int i = 0;i<=S->top;i++){
            k[i] = S->stack[i+1];
        }
        S->stack = k;
    }
    return S;
}

struct Stack_int* pop_int(struct Stack_int* S){
    if(S->top == -1){
        return NULL;
    }
    if(S->top == 0){
        S->top--;
        S->stack = NULL;
    } else {
        S->top--;
        int* k = (int*)malloc(sizeof(int)*S->top+1);
        for(int i = 0;i<=S->top;i++){
            k[i] = S->stack[i+1];
        }
        S->stack = k;
    }
    return S;
}

struct Stack* reverse(struct Stack* S){
    struct Stack* rev = create();
    while(S->top>=0){
        char val = top(S);
        rev = push(rev,val);
        S = pop(S);
    }
    free(S);
    return rev;
}

struct Stack* insert(struct Stack* S, char* exp){
    int i = 0;
    while(exp[i] != '\0'){
        S = push(S,exp[i]);        
        i++;
    }
    S = reverse(S);
    return S;
}
int postfix_eval(struct Stack* S){
    struct  Stack_int* E = create_int();
    while (S->top!=-1)
    {   
        if(top(S) == ','){
            S = pop(S);
        }
        else if(top(S)>='0'&& top(S)<='9'){
            int val = 0;
            while(top(S)>='0'&& top(S)<='9'&&top(S)!=','){
                val *= 10;
                val += top(S)-48;
                S = pop(S);
            }
            E = push_int(E,val);
        } else {
            char operator = top(S);
            S = pop(S);
            int a = (int)(top_int(E));
            E = pop_int(E);
            int b = (int)(top_int(E));
            E = pop_int(E);
            int val = 0;
            printf("%d---%d--|%c\n",a,b,operator);
            switch (operator)
            {
            case '+':
                val = a+b;
                break;
            case '-':
                val = b-a;
                break;
            case '*':
                val = b*a;
                break;
            case '/':
                val = b/a;
                break;
            default:
                break;
            }
            E = push_int(E,val);
        }
        // display_int(E);
        // display(S);
    }
    return top_int(E);
    
}
int main(){
    struct Stack* S = create();
    // S = insert(S,"231*+9-");
    S = insert(S,"21,5,1,-,+,");
    // S = push(S,'1');
    // S = push(S,'2');
    // S = push(S,'3');
    // S = push(S,'4');
    display(S);
    
    // int val = postfix_eval(S);
    // printf("%d",val);
    // printf("%c\n",top(S));
    // S = pop(S);
    // S = reverse(S);
    // display(S);
}
