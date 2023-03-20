//QUEUE USING TWO STACKS..
#include <iostream>
using namespace std;
struct queue {
    int info;
    struct queue* next;
};
//Define two stacks by pointers
struct queue* top1 = NULL; //stack 1
struct queue* top2 = NULL; //stack 2
bool isEmpty(struct queue* top) {
    if (top == NULL) return true;
    else return false;
}
//In push function should determine the stack for adding..
void push(struct queue** top, int item) {
    struct queue* newNode = new (queue);
    newNode->info = item;
    newNode->next = *top;
    *top = newNode;
}
//In pop function should determine the stack for removing..
int pop(struct queue** top) {
    struct queue* temp = *top;
    int item = (*top)->info;
    *top = (*top)->next;
    delete temp;
    return item;
}
//EnQueue function will add item to stack 1..
void enQueue(int item) {
    push(&top1, item);
}
//DeQueue function will remove an item depending on Empty of stacks..
int deQueue() {
    if (isEmpty(top2)) {
        int item;
        do {
            item = pop(&top1);
            push(&top2, item);
        } while (!isEmpty(top1));
    }
    int item = top2->info;
    pop(&top2);
    return item;
}

//traverse function should print all elements either on stack 1 or stack 2
void traverse() {
    if (isEmpty(top1) && isEmpty(top2)) {
        cout << "UNDERFLOW";return;
    }
    if (!isEmpty(top1)) {
        cout << "\nThe elements in Stack 1: \n";
        struct queue* temp = top1;
        while (temp != NULL) {
            cout << temp->info << " -> ";
            temp = temp->next;
        }
    }
    if (!isEmpty(top2)) {
        cout << "\nThe elements in Stack 2: \n";
        struct queue* tem = top2;
        while (tem != NULL) {
            cout << tem->info << " -> ";
            tem = tem->next;
        }
    }
}
int main() {

    int item, a;
    //let the user pick an operation
    while (1) {
        cout << "\n\n QUEUE OPERATION \n";
        cout << " 1: EnQueue \n 2: DeQueue \n 3: traverse \n 4: exit";
        cout << "\n\n SELECT A CHOICE: ";
        cin >> a;
        switch (a) {
            case 1: {
                cout << "\nenter element to add: ";
                cin >> item;
                enQueue(item);
                break;
            }
            case 2: 
                if (isEmpty(top1) && isEmpty(top2)) {
                    cout << "UNDERFLOW";
                }
                else {
                    cout << "the element that has been deleted = " << deQueue();
                }
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "\nInvalid choice. Pick a number ONLY from 1 to 4 ";
        }
    }
}