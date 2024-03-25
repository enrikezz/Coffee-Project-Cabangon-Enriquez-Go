#include <stdio.h>
#include <string.h>

// Module 1: The Order
// Ask whether it’s For Here or To-Go
void ask_for_here_or_to_go() {
    printf("Is this order For Here or To-Go? ");
    // Add code to handle For Here or To-Go
}

// Module 2: Display Menu
int display_menu(void) {
    printf("Menu:");
    printf("\n1. ESPRESSO & MORE\n2. FRAPUCCINO\n3. TEAVANA TEA\n");
    return 0;
}

// Module 3: Order Type
void order_type(int menu_choice) {
    char fullmenu[3][50] = {
        {"Cafe Americano", "Cappucino", "Caffe Latte", "Caffe Mocha", "Caramel Macchiato", "Flat White", "White Chocolate Mocha", "Espresso", "Cold Brew", "Vanilla Sweet Cream Cold Brew", "Cold Foam Iced Espresso"},
        {"Caramel", "Mocha", "White Mocha"},
        {"Iced Shaken Black Tea with Ruby Grapefruit & Honey", "Iced Shaken Hibiscus Tea with Pomegranate Pearls", "Matcha & Espresso Fusion"}
    };

    printf("\nSelect your drink:\n");

    if (menu_choice == 1) {
        for (int i = 0; i < 11; i++) {
            printf("%d. %s\n", i+1, fullmenu[0][i]);
        }
    } else if (menu_choice == 2) {
        for (int i = 0; i < 3; i++) {
            printf("%d. %s\n", i+1, fullmenu[1][i]);
        }
    } else if (menu_choice == 3) {
        for (int i = 0; i < 3; i++) {
            printf("%d. %s\n", i+1, fullmenu[2][i]);
        }
    }
}

// Module 4: Ask Quantity
int ask_quantity() {
    int quantity;
    printf("How many would you like? ");
    scanf("%d", &quantity);
    return quantity;
}

// Module 5: Ask Size
int ask_size() {
    int size_choice;
    printf("Select the size:\n(1) Tall\n(2) Grande\n(3) Venti\n");
    scanf("%d", &size_choice);
    return size_choice;
}

int main(void) {
    int menu_choice;
    int order_quantity;
    int drink_size;
    int order_another;

    do {
        // Module 1: The Order
        ask_for_here_or_to_go();

        // Module 2: Display Menu
        display_menu();

        // Module 3: Order Type
        printf("\nHi! What is your order? ");
        scanf("%d", &menu_choice);
        order_type(menu_choice);

        // Module 4: Ask Quantity
        order_quantity = ask_quantity();

        // Module 5: Ask Size
        drink_size = ask_size();

        // Ask whether they would like to order another drink
        printf("\nWould you like to order another drink? (1 for Yes, 0 for No): ");
        scanf("%d", &order_another);

    } while (order_another == 1);

    // Proceed to payment
    printf("\nProceeding to payment...\n");

    return 0;
}
