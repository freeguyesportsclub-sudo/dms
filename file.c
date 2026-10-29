==================================================
DSU (22317) - PRACTICAL SLIPS - SOLUTIONS
Data Structures using 'C'  |  CO3K  |  2025-26 (ODD Sem)
==================================================
All programs are complete, compile with gcc, and have been
corrected for edge cases (bounds checks, empty list/stack/queue,
missing display() functions, memory leaks, int main).


//==================== SLIP 1 ====================
// Write a program to insert an element in one dimensional array
#include <stdio.h>
#define MAX 10

int main(){
    int arr[MAX] = {21, 12, 36, 45, 4}; // Array of capacity 10 and current elements 5(n)
    int key = 0, pos;
    int n = 5; // Could be user defined

    printf("Enter key: ");
    scanf("%d", &key);
    printf("\nEnter index to be inserted: ");
    scanf("%d", &pos);

    if(n == MAX){
        printf("\nArray is full, cannot insert.");
        return 0;
    }
    if(pos < 0 || pos > n){
        printf("\nInvalid index.");
        return 0;
    }

    printf("\nYour original array: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]); // Display original array
    }

    n += 1; // Increasing array size
    for(int i = n-2; i>=pos; i--){ // Starting from 2nd last pos so i+1 means last pos gets updated
        arr[i+1] = arr[i]; // Shifting elements
    }

    arr[pos] = key; // Inserting new element

    printf("\nUpdated array: ");
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]); // Displaying updated array
    }
    return 0;
}


//==================== SLIP 2 ====================
// Write a program to delete an element in one dimensional array
#include <stdio.h>
#define MAX 10

int main(){
    int arr[MAX] = {10, 20, 30, 40, 50}; // n=5
    int n = 5, idx;  // n can be user defined

    printf("\nOriginal array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nEnter index of element to be deleted: ");
    scanf("%d", &idx);

    if(idx < 0 || idx >= n){
        printf("\nInvalid index.");
        return 0;
    }

    for(int i=idx; i<n-1; i++){ // Loop goes till idx 3 (40), so that idx 4 (50) shifts via i+1
        arr[i] = arr[i+1];
    }
    n -= 1; // Reduce array size

    printf("\nUpdated array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}


//==================== SLIP 3 ====================
// Write a C program to find minimum and maximum element in an array
#include <stdio.h>
#define MAX 10

int main(){
    int arr[MAX] = {10, 20, 30, 40, 50}; // n=5
    int n = 5;
    int min = arr[0], max = arr[0];

    printf("Your array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    for(int i=0; i<n; i++){ // Checking min and max elements
        if(arr[i] < min){
            min = arr[i];
        }

        if(arr[i] > max){
            max = arr[i];
        }
    }

    printf("\n\nMin element: %d", min);
    printf("\nMax element: %d", max);
    return 0;
}


//==================== SLIP 4 ====================
// Write a C program to search a specific element in an array
#include <stdio.h>
#define MAX 10

int main(){
    int arr[MAX] = {10, 20, 30, 40, 50};
    int key, idx = -1, flag = 0;
    int n = 5;

    printf("\nYour array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nEnter key to be searched: ");
    scanf("%d", &key);
    for(int i=0; i<n; i++){ // Linear search
        if(arr[i] == key){
            flag = 1;
            idx = i;
            break; // don't break if multiple keys are to be found
        }
    }

    if(flag == 1)
        printf("\n\nKey %d found at index %d", key, idx);
    else
        printf("\n\nKey not found");
    return 0;
}


//==================== SLIP 5 ====================
// Write a program to search the data from the given array of numbers using linear search
#include <stdio.h>
#define MAX 10

int main(){
    int arr[MAX] = {10, 20, 30, 40, 50};
    int key, idx = -1, flag = 0;
    int n = 5;

    printf("\nYour array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nEnter key to be searched: ");
    scanf("%d", &key);
    for(int i=0; i<n; i++){ // Linear search
        if(arr[i] == key){
            flag = 1;
            idx = i;
            break; // don't break if multiple keys are to be found
        }
    }

    if(flag == 1)
        printf("\n\nKey %d found at index %d", key, idx);
    else
        printf("\n\nKey not found");
    return 0;
}


//==================== SLIP 6 ====================
// Write a program to search the data from the given array of numbers using binary search
#include <stdio.h>
#define MAX 10

void display(int a[], int n);

int main(){
    int arr[MAX] = {10, 20, 30, 40, 50}; // Array always needs to be sorted for binary search
    int n = 5;
    int beg = 0, mid = 0, end = n-1, key, flag = 0;

    printf("\nYour array is: ");
    display(arr, n);

    printf("\nEnter key to search: ");
    scanf("%d", &key);

    while(beg <= end){ // Binary search
        mid = (beg+end)/2;

        if(arr[mid] == key){
            flag = 1;
            break;
        }
        else if(arr[mid] < key)
            beg = mid+1;
        else
            end = mid-1;
    }

    if(flag == 1)
        printf("\n\nElement found at index %d", mid);
    else
        printf("\n\nElement not found");
    return 0;
}

void display(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d", a[i]);
        if(i != n-1)
            printf(", ");
    }
}


//==================== SLIP 7 ====================
// Write a program to search the data from the given array of String using linear search
#include <stdio.h>
#include <string.h>
#define MAX 10

void display(char a[][20], int n);

int main(){
    int n = 5, flag = 0, idx = -1;
    char arr[MAX][20]; // MAX is arr size, 20 is max string length
    char key[20];

    printf("\nEnter strings: \n");
    for(int i=0; i<n; i++){
        printf("String %d: ", i+1);
        scanf("%19s", arr[i]);
    }

    printf("\nYour array is: ");
    display(arr, n);
    printf("\nEnter key to search: ");
    scanf("%19s", key);

    for(int i=0; i<n; i++){ // Linear search
        if(strcmp(arr[i], key) == 0){
            flag = 1;
            idx = i;
            break;
        }
    }

    if(flag == 1)
        printf("\n\nElement found at index %d", idx);
    else
        printf("\n\nElement not found");
    return 0;
}

void display(char a[][20], int n){
    for(int i=0; i<n; i++){
        printf("%s", a[i]); // no need for internal j loop since %s prints the whole string
        if(i != n-1)
            printf(", ");
    }
}


//==================== SLIP 8 ====================
// Write a program to search the data from the given array of String using binary search
#include <stdio.h>
#include <string.h>
#define MAX 10

void display(char a[][20], int n);

int main(){
    char arr[MAX][20]; // MAX is number of elements, 20 is string length
    char key[20];
    int n = 5, beg = 0, end = n-1, mid = 0, flag = 0;

    printf("\nENTER ELEMENTS (in ascending/sorted order)\n");
    for(int i=0; i<n; i++){ // Accept elements (array needs to be sorted for binary search)
        printf("Element %d: ", i+1);
        scanf("%19s", arr[i]);
    }
    printf("\nYour array is: ");
    display(arr, n); // Same as used in linear search

    printf("\nEnter key to be searched: ");
    scanf("%19s", key);

    while(beg <= end){ // Binary search
        mid = (beg+end)/2;

        if(strcmp(arr[mid], key) == 0){
            flag = 1;
            break;
        }
        else if(strcmp(arr[mid], key) > 0) // Mid is greater than key
            end = mid - 1;
        else
            beg = mid + 1; // Mid is lesser than key
    }

    if(flag == 1)
        printf("\n\nKey found at index %d", mid);
    else
        printf("\n\nElement not found");
    return 0;
}

void display(char a[][20], int n){
    for(int i=0; i<n; i++){
        printf("%s", a[i]);
        if(i != n-1)
            printf(", ");
    }
}


//==================== SLIP 9 ====================
// Write a program to sort an array of numbers using bubble sort Method
#include <stdio.h>
#define MAX 10

void display(int a[], int n);

int main(){
    int arr[MAX] = {20, 10, 30, 61, 3}; // n = 5;
    int n = 5, temp;

    printf("\nUnsorted array: ");
    display(arr, n);

    for(int i=0; i<n-1; i++){ // No of passes = n-1
        for(int j=0; j < n-i-1; j++){ // n-i-1 so we reach the second last element and compare the last using arr[j+1]
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("\nPass %d: ", i+1);
        display(arr, n);
    }

    printf("\n\nSorted array: ");
    display(arr, n);
    return 0;
}

void display(int a[], int n){
    for(int i=0; i<n; i++){
        if(i == 0)
            printf("{");

        printf("%d", a[i]);

        if(i != n-1)
            printf(", ");
        else
            printf("}");
    }
}


//==================== SLIP 10 ====================
// Write a program to sort an array of string using bubble sort Method
#include <stdio.h>
#include <string.h>
#define MAX 10

void display(char a[][20], int n);

int main(){
    char arr[MAX][20], temp[20];
    int n = 5;

    printf("\nEnter array elements\n");
    for(int i=0; i<n; i++){
        printf("String %d: ", i+1);
        scanf("%19s", arr[i]);
    }
    printf("\nUnsorted array: ");
    display(arr, n);

    for(int i=0; i<n-1; i++){
        for(int j=0; j < n-i-1; j++){
            if(strcmp(arr[j], arr[j+1]) > 0){ // i.e. arr[j] > arr[j+1]
                strcpy(temp, arr[j]);         // temp = arr[j]
                strcpy(arr[j], arr[j+1]);     // arr[j] = arr[j+1]
                strcpy(arr[j+1], temp);       // arr[j+1] = temp
            }
        }
        printf("\nPass %d: ", i+1);
        display(arr, n);
    }

    printf("\n\nSorted array: ");
    display(arr, n);
    return 0;
}

void display(char a[][20], int n){
    for(int i=0; i<n; i++){
        if(i == 0)
            printf("{");

        printf("%s", a[i]);

        if(i != n-1)
            printf(", ");
        else
            printf("}");
    }
}


//==================== SLIP 11 ====================
// Write a program to sort an array of numbers using insertion sort Method
#include <stdio.h>
#define MAX 10

void display(int a[], int n);

int main(){
    int arr[MAX] = {20, 10, 40, 50, 30}, n = 5;
    int j, key;

    printf("\nUnsorted array: ");
    display(arr, n);

    // Insertion sort
    for(int i=1; i<n; i++){
        key = arr[i]; // element from where unsorted part starts
        j = i-1;      // index where sorted part ends

        while(j >= 0 && key < arr[j]){ // Shift elements right as long as key is smaller than arr[j]
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key; // insert key after shifting is complete

        printf("\nPass %d: ", i);
        display(arr, n);
    }

    printf("\n\nSorted array: ");
    display(arr, n);
    return 0;
}

void display(int a[], int n){
    for(int i=0; i<n; i++){
        if(i == 0)
            printf("{");

        printf("%d", a[i]);

        if(i != n-1)
            printf(", ");
        else
            printf("}");
    }
}


//==================== SLIP 12 ====================
// Write a program to sort an array of numbers using selection sort Method
#include <stdio.h>
#define MAX 10

void display(int a[], int n);

int main(){
    int arr[MAX] = {20, 10, 40, 50, 30}, n = 5;
    int minindex, temp;

    printf("\nUnsorted array: ");
    display(arr, n);

    // Selection Sort
    for(int i=0; i<n-1; i++){ // n-1 so the minindex goes till the second last element
        minindex = i;

        for(int j=i+1; j<n; j++){ // compare all elements ahead of minindex
            if(arr[j] < arr[minindex]) // if smaller element found, set its index as minindex
                minindex = j;
        }
        if(minindex != i){ // if minindex has changed, then swap
            temp = arr[minindex];
            arr[minindex] = arr[i];
            arr[i] = temp;
        }

        printf("\nPass %d: ", i+1);
        display(arr, n);
    }

    printf("\n\nSorted array: ");
    display(arr, n);
    return 0;
}

void display(int a[], int n){
    for(int i=0; i<n; i++){
        if(i == 0)
            printf("{");

        printf("%d", a[i]);

        if(i != n-1)
            printf(", ");
        else
            printf("}");
    }
}


//==================== SLIP 13 ====================
// Write a menu-driven program to implement stack using push, pop and display operation
#include <stdio.h>
#define MAX 3

int arr[MAX], top = -1;

void push();
void pop();
void display();

int main(){
    int ch;

    printf("\nMenu: ");
    printf("\t0.Exit  1.Push  2.Pop  3.Display");

    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void push(){
    int val;

    if(top == MAX-1){ // Checking stack overflow condition
        printf("\nStack full");
        return;
    }

    printf("\nEnter value to push: ");
    scanf("%d", &val);
    top += 1;
    arr[top] = val;
}

void pop(){
    int val;

    if(top == -1){ // Check stack underflow condition
        printf("\nStack is empty");
        return;
    }

    val = arr[top];
    top -= 1;
    printf("\n%d popped from top", val);
}

void display(){
    if(top == -1){ // Check stack empty condition
        printf("\nStack is empty");
        return;
    }

    printf("\nYour stack is: \n");
    for(int i=0; i<=top; i++){
        printf("%d", arr[i]);
        if(i != top)
            printf(", ");
        else
            printf(" |\n"); // Marks top of the stack
    }
}


//==================== SLIP 14 ====================
// Write a menu driven program to implement linear queue using insert, delete and display operation
#include <stdio.h>
#define MAX 3

int queue[MAX], front = -1, rear = -1; // Global vars

void insert();
void del();
void display();

int main(){
    int ch;

    printf("\nMenu: ");
    printf("\t0.Exit  1.Insert  2.Delete  3.Display");

    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void insert(){ // We insert from rear
    int val;

    if(rear == MAX-1){
        printf("\nQueue full");
        return;
    }

    printf("\nEnter value to insert: ");
    scanf("%d", &val);
    rear += 1;
    if(front == -1)
        front += 1; // so front = 0
    queue[rear] = val;
}

void del(){ // Delete from front
    int val;

    if(front == -1 && rear == -1){
        printf("\nQueue empty");
        return;
    }

    val = queue[front];
    front += 1;
    printf("\n%d deleted from queue", val);

    if(front > rear){ // queue became empty, reset
        front = -1;
        rear = -1;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("\nQueue empty");
        return;
    }

    printf("\nYour queue is: ");
    for(int i=front; i<=rear; i++){
        printf("%d", queue[i]);
        if(i != rear)
            printf(", ");
        else
            printf(" |");
    }
}


//==================== SLIP 15 ====================
// Write a menu driven program to implement circular queue using insert, delete, display operation
#include <stdio.h>
#define MAX 3

int queue[MAX], front = -1, rear = -1; // Global vars

void insert();
void del();
void display();

int main(){
    int ch;

    printf("\nMenu: ");
    printf("\t0.Exit  1.Insert  2.Delete  3.Display");

    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: insert();
                    break;
            case 2: del();
                    break;
            case 3: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void insert(){ // Insert at rear (wraps around using modulo)
    int val;

    if((front == 0 && rear == MAX-1) || (front == rear+1)){ // Circular queue full condition
        printf("\nQueue full");
        return;
    }

    printf("\nEnter value to insert: ");
    scanf("%d", &val);

    if(front == -1){ // First element
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % MAX;

    queue[rear] = val;
}

void del(){ // Delete from front
    int val;

    if(front == -1){ // Empty condition
        printf("\nQueue empty");
        return;
    }

    val = queue[front];
    printf("\n%d deleted from queue", val);

    if(front == rear){ // Only one element was present, queue is now empty
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAX;
}

void display(){
    int i;

    if(front == -1){
        printf("\nQueue empty");
        return;
    }

    printf("\nYour queue is: ");
    i = front;
    while(1){
        printf("%d", queue[i]);
        if(i == rear)
            break;
        printf(", ");
        i = (i + 1) % MAX;
    }
    printf(" |");
}


//==================== SLIP 16 ====================
// Write a program to perform multiplication of two numbers using recursion
#include <stdio.h>

int multiply(int a, int b){
    if(b == 0)
        return 0;

    return a + multiply(a, (b-1));
}

int main(){
    int x = 5, y = 3;

    printf("\nProduct of %d x %d = %d", x, y, multiply(x, y));
    return 0;
}


//==================== SLIP 17 ====================
// Write a program to create and display linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *start = NULL;   // *start is a pointer to struct node, not an actual node
    struct node *ptr = NULL;     // *ptr is a pointer to struct node, not an actual node
    struct node *newnode = NULL; // *newnode is a pointer to struct node, not an actual node
    int n, val;

    printf("\nEnter number of nodes to be inserted: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
    return 0;
}


//==================== SLIP 18 ====================
// Write a program to create and insert node at beginning in the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;   // *start is a pointer to struct node, not an actual node
struct node *ptr = NULL;
struct node *newnode = NULL;

void display();
void insert_beg();

int main(){
    int ch, n, val;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nMenu: ");
    printf("\t0.Exit  1.Insert at beginning  2.Display");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: insert_beg();
                    break;
            case 2: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void insert_beg(){
    int val;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for new node: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = start; // new node points to old first node
    start = newnode;       // new node becomes the first node
}

void display(){
    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 19 ====================
// Write a program to create and insert node at middle in the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr = NULL;
struct node *newnode = NULL;

void display();
void insert_mid();

int main(){
    int ch, n, val;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nMenu: ");
    printf("\t0.Exit  1.Insert at mid  2.Display");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: insert_mid();
                    break;
            case 2: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void insert_mid(){ // Inserts new node AFTER the node having the given key
    int val, key, flag = 0;

    printf("\nEnter key (new node will be inserted after this node): ");
    scanf("%d", &key);

    ptr = start; // traverse list until key is found
    while(ptr != NULL){
        if(ptr->data == key){
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }

    if(flag == 0){
        printf("\nKey not found, hence element can't be inserted.");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data for new node: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = ptr->next; // set next pointer for newnode
    ptr->next = newnode;       // set next pointer for key node
}

void display(){
    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 20 ====================
// Write a program to create and insert node at end in the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr = NULL;
struct node *newnode = NULL;

void display();
void insert_end();

int main(){
    int ch, n, val;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nMenu: ");
    printf("\t0.Exit  1.Insert at end  2.Display");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: insert_end();
                    break;
            case 2: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void insert_end(){
    int val;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter data for new node: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL; // we keep this NULL as the newnode will be inserted at end

    if(start == NULL){ // list is empty, newnode becomes first node
        start = newnode;
        return;
    }

    ptr = start;
    while(ptr->next != NULL){ // traverse list until last node
        ptr = ptr->next;
    }
    ptr->next = newnode; // next pointer of the last node is changed from NULL to newnode
}

void display(){
    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 21 ====================
// Write a program to create and delete a node from beginning of the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr = NULL;
struct node *newnode = NULL;

void display();
void del_beg();

int main(){
    int ch, n, val;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nMenu: ");
    printf("\t0.Exit  1.Delete at beginning  2.Display");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: del_beg();
                    break;
            case 2: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void del_beg(){
    if(start == NULL){
        printf("\nList is empty.");
        return;
    }

    ptr = start;
    start = ptr->next; // set start to 2nd node using ptr->next
    printf("\n%d deleted from beginning", ptr->data);
    free(ptr);         // free up memory allocated to the original start node
}

void display(){
    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 22 ====================
// Write a program to create and delete a node from middle of the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr = NULL;
struct node *ptr2 = NULL;
struct node *newnode = NULL;

void display();
void del_mid();

int main(){
    int ch, n, val;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nMenu: ");
    printf("\t0.Exit  1.Delete at mid  2.Display");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: del_mid();
                    break;
            case 2: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void del_mid(){
    int key, flag = 0;

    if(start == NULL){
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter node to be deleted: ");
    scanf("%d", &key);

    if(start->data == key){ // key is in the first node
        ptr = start;
        start = start->next;
        free(ptr);
        return;
    }

    ptr = start;           // ptr trails one node behind ptr2
    ptr2 = start->next;

    while(ptr2 != NULL){
        if(ptr2->data == key){
            flag = 1;
            break;
        }
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }

    if(flag == 0)
        printf("\nNode not found.");
    else{
        ptr->next = ptr2->next; // unlink the node
        free(ptr2);             // free its memory
    }
}

void display(){
    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 23 ====================
// Write a program to create and delete a node from end of the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr = NULL;
struct node *ptr2 = NULL;
struct node *newnode = NULL;

void display();
void del_end();

int main(){
    int ch, n, val;

    printf("\nEnter number of nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){ // Creating nodes
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nMenu: ");
    printf("\t0.Exit  1.Delete at end  2.Display");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){ // Menu driven program
            case 0: printf("\n\nExiting...");
                    break;
            case 1: del_end();
                    break;
            case 2: display();
                    break;
            default: printf("\nInvalid input");
        }
    }while(ch != 0);
    return 0;
}

void del_end(){
    if(start == NULL){
        printf("\nList is empty.");
        return;
    }

    if(start->next == NULL){ // only one node in the list
        free(start);
        start = NULL;
        return;
    }

    ptr = start;
    ptr2 = start->next;

    while(ptr2->next != NULL){ // move until ptr2 is the last node
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }

    ptr->next = NULL; // second last node points to NULL, i.e. it's now the last node
    free(ptr2);       // we free the original last node
}

void display(){
    ptr = start;
    printf("\n\nLinked list: ");
    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){ // Displaying linked list
        printf("%d", ptr->data);
        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 24 ====================
// Write a program to create singly linked list and search a node from the singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *ptr = NULL;
struct node *newnode = NULL;

void display();

int main(){
    int n, val, key, pos = 1, flag = 0;

    printf("\nEnter nodes to be created: ");
    scanf("%d", &n);
    printf("\n");
    for(int i=0; i<n; i++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &val);

        newnode->data = val;
        newnode->next = NULL;

        if(start == NULL){
            start = newnode;
            ptr = newnode;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    printf("\nYour linked list is: ");
    display();

    printf("\nEnter key to be searched: ");
    scanf("%d", &key);
    ptr = start;
    while(ptr != NULL){
        if(ptr->data == key){
            flag = 1;
            break;
        }
        ptr = ptr->next;
        pos += 1;
    }

    if(flag == 0)
        printf("\nNode not found.");
    else
        printf("\nNode %d found at position %d", key, pos);
    return 0;
}

void display(){
    ptr = start;

    if(ptr == NULL)
        printf("empty");
    while(ptr != NULL){
        printf("%d", ptr->data);

        if(ptr->next != NULL)
            printf(" -> ");
        else
            printf(" -> NULL");

        ptr = ptr->next;
    }
}


//==================== SLIP 25 ====================
// Write a program to create tree and display by preorder, inorder, postorder
#include <stdio.h>
#include <stdlib.h>

// TREE WORKS PRIMARILY ON CONCEPT OF RECURSION

struct node{
    int data;
    struct node *left;  // pointer to a struct node
    struct node *right;
};

struct node* create(){ // means the func will return a pointer pointing at a struct node
    int val;
    struct node *newnode;

    printf("\nEnter value for new node (-1 for no node): ");
    scanf("%d", &val);
    if(val == -1)
        return NULL; // marks that no node exists

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    printf("\nEnter val for left child of %d: ", val);
    newnode->left = create();

    printf("\nEnter val for right child of %d: ", val);
    newnode->right = create(); // if both left and right child = -1, then the current node is leaf node

    return newnode;
}

void preorder(struct node *root){
    if(root == NULL)
        return;

    // Root -> Left -> Right
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL)
        return;

    // Left -> Root -> Right
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL)
        return;

    // Left -> Right -> Root
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    struct node *root;

    printf("\nCREATE TREE");
    root = create();

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nInorder: ");
    inorder(root);
    return 0;
  }
