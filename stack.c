#ifndef STACK
#define STACK
typedef struct stack {
    int value;
    struct stack* prev;
} Stack;

Stack* _top_;

void push(int);
void pop();
int peek();

void init() {
    _top_ = NULL;
}

void push(int value) {
    // printf("push %d ", value);
    Stack* node = (Stack*) malloc(sizeof(Stack));
    node->value = value;
    node->prev = _top_;
    _top_ = node;
}

void pop() {
    // printf("pop  %d ", peek());
    if (_top_ != NULL)
        _top_ = _top_->prev;
}

int peek() {
    if (_top_ == NULL)
        return 0;
    return _top_->value;
}

void npop(int count) {
    int i;
    for (i = 0; i < count; i++)
    {
        pop();
    }
}

int npeek(int offset) {
    Stack* cursor = _top_;
    int i;
    for (i = 0; i < offset; i++)
    {
        if (cursor != NULL)
            cursor = cursor->prev;
        else
            break;
    }

    if (cursor == NULL)
        return 0;
    return cursor->value; 
}
#endif