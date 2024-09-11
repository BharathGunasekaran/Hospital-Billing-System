#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next, *pre;
    char name[30];
    int qty;
    int price;
} *head = NULL, *tail = NULL;

void add_item() {
    char pro_name[30];
    int pro_qty, pro_price;
    printf("\nEnter The Product Name: ");
    scanf("%s", pro_name);
    printf("\nEnter The Quantity Of The Product: ");
    scanf("%d", &pro_qty);
    printf("\nEnter The Price Of The Product: ");
    scanf("%d", &pro_price);
    printf("\n");
    pro_price = pro_qty * pro_price;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->name, pro_name);
    newnode->qty = pro_qty;
    newnode->price = pro_price;
    newnode->next = newnode->pre = NULL;

    if (head == NULL) {
        head = tail = newnode;
        printf("\n%s Successfully Added\n\n", pro_name);
    } else {
        tail->next = newnode;
        tail = newnode;
        printf("\n%s Successfully Added\n\n", pro_name);
    }
}

void display() {
    int k = 1;
    if (head == NULL) {
        printf("No Product Added\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d---", k);
            printf("%s ---", temp->name);
            printf("%d ---", temp->qty);
            printf("%d \n", temp->price);
            temp = temp->next;
            k++;
        }
    }
}

void del() {
    int k = 1, del_pos, g = 0;
    if (head == NULL) {
        printf("No Products Added\n");
        g++;
    } else {
        printf("\n**\n");
        display();
        printf("Enter the serial number to be deleted: ");
        scanf("%d", &del_pos);

        if (k == del_pos) {
            struct node *temp = head;
            head = head->next;
            free(temp);
            printf("%d Successfully Removed\n", del_pos);
            g++;
        } else {
            k++;
            struct node *temp = head->next, *last = head;
            while (temp != NULL) {
                if (k == del_pos) {
                    last->next = temp->next;
                    free(temp);
                    printf("%d Successfully Removed\n", del_pos);
                    g++;
                    break;
                } else {
                    k++;
                    last = temp;
                    temp = temp->next;
                }
            }
        }
    }
    if (g == 0) {
        printf("Invalid Position");
    }
    printf("\n**\n");
}
void change_qty() {
    int k = 1, change_q,qty,pri, g = 0;
    if (head == NULL) {
        printf("No Products Added\n");
        g++;
    } else {
        printf("\n\n****\n");
        display();
        printf("Enter The Serial Number To Be Changed The Quantity: ");
        scanf("%d", &change_q);

        if (k == change_q) {
            printf("Enter The New Quantity:");
            scanf("%d",&qty);
            printf("Enter The Price:");
            scanf("%d",&pri);
            head->qty=qty;
            head->price=pri*qty;
            printf("Quantity Changed %d Successfully\n",qty);
            g++;
        } 
        else {
            k++;
            struct node *temp = head->next;
            while (temp != NULL) {
                if (k == change_q) {
                    printf("Enter The New Quantity:");
                    scanf("%d",&qty); 
                    printf("Enter The Price:");
                    scanf("%d",&pri);
                    head->qty=qty;
                    head->price=pri*qty;
                    printf("Quantity Changed %d Successfully\n",qty);
                    g++;
                    break;
                } 
                else {
                    k++;
                    temp = temp->next;
                }
            }
        }
    }
    if (g == 0) {
        printf("Invalid Position");
    }
    printf("\n**\n");
}

int total() {
    struct node *temp = head;
    int a = 0;
    while (temp != NULL) {
        a = temp->price + a;
        temp = temp->next;
    }
    return a;
}

void display1() {
    int c = 1,g=0;
    int age;
    long int phone;
    char name[30];
    printf("Enter The Name Of Patient :");
    scanf("%s",name);
    printf("Enter The Age :");
    scanf("%d",&age);
    printf("Enter The Phone Number :");
    scanf("%ld",&phone);
    struct node *temp = head;
    printf("\n\n");
    for (int i = 0; i < 18; i++) {
        printf("*");
    }
    printf("Hospital Name");
    for (int i = 0; i < 19; i++) {
        printf("*");
    }
    printf("\n");
    printf("Dr.NAME(M.B.B.S)                ");
    printf("Dr.no : 1234567890");
    printf("\n");
    printf("Name : %s",name);
    for(int i=0;i<25-strlen(name);i++){
        printf(" ");
    }
    printf("Ph.no : %ld \n",phone);
    printf("Age  : %d\n",age);
    for (int i = 0; i < 50; i++) {
        printf("*");
    }
    printf("\n");
    printf("S.no  ");
    printf("Product name                   ");
    printf("Qty    ");
    printf("Price  \n");
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n");
    while (temp != NULL) {
        int a, k, b;
        if (c < 10)
            k = 0;
        else if (c > 9 && c < 100)
            k = 1;
        a = 5 - k;
        printf("%d", c);
        c++;
        for (int l = 0; l < a; l++) {
            printf(" ");
        }
        
        k = strlen(temp->name) - 1;
        a = 30 - k;
        g++;
        printf("%s", temp->name);
        for (int l = 0; l < a; l++) {
            printf(" ");
        }
        b = temp->qty;
        if (b < 10)
            k = 0;
        else if (b > 9 && b < 100)
            k = 1;
        a = 5 - k;
        printf("%d", b);
        for (int l = 0; l < a + 1; l++) {
            printf(" ");
        }
        b = temp->price;
        if (b < 10)
            k = 0;
        else if (b > 9 && b < 100)
            k = 1;
        else if (b > 99 && b < 1000)
            k = 2;
        a = 5 - k;
        printf("%d", b);
        for (int l = 0; l < a + 1; l++) {
            printf(" ");
        }
        printf("\n");
        temp = temp->next;
    }
    if(g==0){
        printf("            ##### NO Items Added #####            \n");
    }
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 36; i++) {
        printf(" ");
    }
    printf("Total :");
    int tot;
    tot = total();
    printf(" %d\n", tot);
    for (int i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n\n");
    printf("*****Stay healthy and Stay Safe!*****\n\n");
}

int main() {
    int choice;
    while (choice != 4&&choice !=5) {
        for (int i = 0; i < 18; i++) {
            printf("*");
        }
        printf("Hospital Name");
        for (int i = 0; i < 19; i++) {
            printf("*");
        }
        printf("\n");
        printf("1. Add Product\n2. Remove Product\n3. Change Quantity\n4. Display The Prescription\n5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                del();
                break;
            case 3:
                change_qty();
                break;
            case 4:
                display1();
                break;
            case 5:
                printf("Exiting The Program\n");
                break;
            default:
                printf("Invalid Choice\n\n");
                break;
        }
    }
    return 0;
}