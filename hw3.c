
#define IF   1
#define COND 2
#define ELSE 3
#define STMT 4
#define I 10
#define E 11

#include "lex.yy.c"
#include "stack.c"

int yywrap() {

}

void accept() {
    printf("\naccept");
    exit(0);
}

void regect() {
    printf("\nregect");
    exit(0);
}

void reduce() {
    int top;
    while ((top = peek()) == STMT) {
        if (npeek(3) == I && npeek(2) == STMT && npeek(1) == E && npeek(0) == STMT)
        {
            npop(4);
            push(STMT);
            // printf("reduce %d ", peek());
        }
        else
            return;
    }
    // printf("reduce %d ", peek());
}

void reduceAll() {
    int top;
    while ((top = peek()) == STMT) {
        if (npeek(3) == I && npeek(2) == STMT && npeek(1) == E && npeek(0) == STMT)
        {
            npop(4); push(STMT);
            // printf("reduce %d ", peek());
        }
        else if (npeek(1) == I) 
        { 
            npop(2); 
            push(STMT); 
            // printf("reduce %d ", peek());
        }
        else if (npeek(1) == 0) pop();
        else return;
    }
}

void main() {
    int c, top;
    while (c = yylex()) {
        top = peek();
        switch (c) {
        case IF:
            printf("if ");
            switch(top) {
            case 0:             
            case I:     
                case E:     push(IF); break;
                default:    regect(); break;
            }
            break;
        case COND:
            printf("cond ");
            switch(top) {
                case IF:    pop(); push(I); break;
                default:    regect(); break;
            }
            break;
        case ELSE:
            printf("else ");
            switch(top) {
                case STMT:  push(E); break;
                default:    regect(); break;
            }
            break;
        case STMT:
            printf("stmt ");
            switch(top) {
                case I:     push(STMT); break;
                case E:     push(STMT); reduce(); break;
            default:        regect(); break;
            }
            break;
        }
    }
    
    reduceAll();

    if (peek() == 0)
        accept();
    else
        regect();
}
