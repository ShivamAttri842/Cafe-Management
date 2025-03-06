#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} MenuItem;

typedef struct {
    int id;
    char name[50];
    int quantity;
    float total;
} Order;

void display_menu(MenuItem menu[], int size) {
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

void take_order(MenuItem menu[], int menu_size, Order orders[], int *order_size) {
    int id;
    printf("\nEnter the item number you would like to order: ");
    scanf("%d", &id);
    for (int i = 0; i < menu_size; i++) {
        if (menu[i].id == id) {
            int quantity;
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            orders[*order_size].id = id;
            strcpy(orders[*order_size].name, menu[i].name);
            orders[*order_size].quantity = quantity;
            orders[*order_size].total = menu[i].price * quantity;
            (*order_size)++;
            return;
        }
    }
    printf("Invalid item number. Please try again.\n");
    take_order(menu, menu_size, orders, order_size);
}

void display_orders(Order orders[], int size) {
    printf("\nOrders:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Quantity: %d - Total: $%.2f\n", orders[i].id, orders[i].name, orders[i].quantity, orders[i].total);
    }
}

float calculate_bill(Order orders[], int size) {
    float total = 0.0;
    for (int i = 0; i < size; i++) {
        total += orders[i].total;

    }
    return total;
}

int main() {
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    MenuItem menu[100];
    int menu_size = 0;

    while (1) {
        int id;
        char name[50];
        float price;
        if (fscanf(file, "%d%s%f", &id, name, &price) == EOF) {
            break;
            
        }
        menu[menu_size].id = id;
        strcpy(menu[menu_size].name, name);
        menu[menu_size].price = price;
        menu_size++;
    }

    fclose(file);

    Order orders[10];
    int order_size = 0;

    int choice;
    while (1) {
        printf("Heyy welcome To Our cafe");
        printf("\n1. Display Menu\n2. Take Order\n3. Display Orders\n4. Calculate Bill\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_menu(menu, menu_size);
                break;
            case 2:
                take_order(menu, menu_size, orders, &order_size);
                break;
            case 3:
                display_orders(orders, order_size);
                break;
            case 4:
                printf("Total Bill: $%.2f\n", calculate_bill(orders, order_size));
                break;
            case 5:
                exit("0");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}