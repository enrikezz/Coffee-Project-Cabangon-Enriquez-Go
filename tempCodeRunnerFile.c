#include <stdio.h>
#include <string.h>

// Module 1: Display Menu
void display_menu() {
    printf("Menu:\n");
    printf("1. ESPRESSO & MORE\n");
    printf("2. FRAPUCCINO\n");
    printf("3. TEAVANA TEA\n");
}

// Module 2: Ask for Order
void ask_for_order() {
    printf("\nHi! What's your order? Enter the number corresponding to the drink: ");
}

// Module 3: Select Size
int select_size() {
    int size_choice;
    printf("Select the size:\n(1) Tall\n(2) Grande\n(3) Venti\n");
    scanf("%d", &size_choice);
    return size_choice;
}

// Module 4: Ask for Hot or Iced
char ask_hot_or_iced() {
    char hot_or_iced;
    printf("Would you like it hot or iced? (h for hot, i for iced): ");
    scanf(" %c", &hot_or_iced);
    return hot_or_iced;
}

// Module 5: Ask for Add-ons
int ask_for_addons() {
    int choice;
    printf("Would you like to have an add-on? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    return choice;
}

// Module 6: Ask for Quantity
int ask_for_quantity() {
    int quantity;
    printf("How many would you like? ");
    scanf("%d", &quantity);
    return quantity;
}

int main(void) {
    char done[10];
    int menu_choice;
    int drink_size;
    char hot_or_iced;
    int add_on_choice;
    int order_quantity;

    do {
        // Module 1: Display Menu
        display_menu();

        // Module 2: Ask for Order
        ask_for_order();
        scanf("%d", &menu_choice);

        // Module 3: Select Size
        drink_size = select_size();

        if (menu_choice == 1) { // Espresso
            // Module 4: Ask for Hot or Iced
            hot_or_iced = ask_hot_or_iced();
        } else if (menu_choice == 2) { // Frappuccino
            // Module 5: Ask for Add-ons
            add_on_choice = ask_for_addons();
        }

        // Module 6: Ask for Quantity
        order_quantity = ask_for_quantity();

        printf("\nWould you like to order another drink? (Type 'done' to finish): ");
        scanf("%s", done);
    } while (strcmp(done, "done") != 0);

    // Proceed to payment
    printf("\nProceeding to payment...\n");

    return 0;
}
