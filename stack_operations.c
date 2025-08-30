#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

// Push operation
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d to stack.\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("Popped %d from stack.\n", stack[top--]);
    }
}

void peep() {
    if (isEmpty()) {
        printf("Stack is empty. Nothing to peep.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peep\n4. Display\n5. Check Empty\n6. Check Full\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 6:
                if (isFull())
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 0:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
