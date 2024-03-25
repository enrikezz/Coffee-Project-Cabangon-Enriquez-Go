#include <stdio.h>
#include <ctype.h>
#include <string.h>

//displays list of beverage options user can select.
void display_menu() {
    printf("Menu:\n");
    printf("(1.) ESPRESSO & MORE\n");
    printf("(2.) FRAPUCCINO\n");
    printf("(3.) TEAVANA TEA\n");
}
//displays espresso options
void menu_espresso() {
    printf("\nESPRESSO & MORE \n\n");
    printf("(1.) Espresso Beverages       Tall      Grande      Venti\n");
    printf("(2.) Caffe Americano          130        145         160\n");
    printf("(3.) Cappuccino               140        155         170\n");
    printf("(4.) Caffe Latte              140        155         170\n");
    printf("(5.) Caffe Mocha              165        180         195\n");
    printf("(6.) Caramel Macchiato        165        180         195\n");
    printf("(7.) Flat White               165        180         195\n");
    printf("(8.) White Chocolate Mocha    165        180         195\n");
    printf("(9.) Espresso                 120        130         \n");
    printf("\nPlease enter the number of your drink of choice: \n");
    
}
//displays frapuccino options
void menu_frapuccino() {
    printf("\nFRAPPUCINO \n\n");
    printf("(1.) Blended Coffee           Tall      Grande      Venti\n");
    printf("(2.) Caramel                  165        180         195\n");
    printf("(3.) Mocha                    165        180         195\n");
    printf("(4.) White Mocha              160        175         190\n");
    printf("(5.) Coffee Jelly             170        185         200\n");
    printf("(6.) Java Chip                170        185         200\n");
    printf("(7.) Dark Mocha               180        195         210\n");
    printf("\nBlended Cream\n");
    printf("(8.) Chocolate Cream          150        165         180\n");
    printf("(9.) Vanilla Cream            150        165         180\n");
    printf("(10.) Caramel Cream           155        170         185\n");
    printf("(11.) Chocolate Chip Cream    170        185         200\n");
    printf("(12.) Strawberries & Cream    170        185         200\n");
    printf("(13.) Green Tea Cream         170        185         200\n");
    printf("\nPlease enter the number of your drink of choice: \n");
}

//displays frapuccino customization
void menu_customize() {
    printf("\nCustomize Your Beverage\n");
    printf("ADD\n");
    printf("   - Flavored Syrup  +20\n");
    printf("   - Espresso Shot   +30\n");
    printf("   - White Mocha     +20\n");
    printf("   - Heavy Cream     +20\n");
    printf("   - Cold Foam       +20\n");
    printf("Substitute\n");
    printf("   - Organic Soymilk +20\n");
    printf("   - Breve           +20\n");
}

//displays teavanatea options
void menu_teavanatea() {
    printf("\nTEAVANA TEA \n\n");
    printf("Signiture Tea Beverage                                                Tall      Grande      Venti\n");
    printf("(1.) Iced Shaken Black Tea w/ Ruby Grapefruit & Honey                 140        155         170\n");
    printf("(2.) Iced Shaken  Hibiscus Tea w/ Pomegrate Pearls                    140        155         170\n");
    printf("(3.) Matcha & Espresso Fusion                                         155        170         185\n");
    printf("\nTeavana Iced Shaken Tea\n");
    printf("(4.) Green Iced Shaken                                                125        140         155\n");
    printf("(5.) Black Iced Shaken                                                125        140         155\n");
    printf("(6.) Caffeine-free herbal Iced Shaken                                 125        140         155\n");
    printf("\nTeavana Tea Latte\n");
    printf("(7.) Black Tea Latte                                                  140        155         170\n");
    printf("(8.) Chai Tea Latte                                                   155        170         185\n");
    printf("(9.) Green Tea Latte                                                  155        170         185\n");
    printf("\nTeavana Full-Leaf Brewed Tea\n");
    printf("(10.) Green Full-Leaf                                                 120        135         150\n");
    printf("(11.) White Full-Leaf                                                 125        140         155\n");
    printf("(12.) Black Full-Leaf                                                 125        140         155\n");
    printf("(13.) Caffeine-free Herbal Tea Full-Leaf                              125        140         155\n");
    printf("\nPlease enter the number of your drink of choice: \n");
 
}
    
//asking of order
void ask_for_order() {
    printf("\nWelcome to AnimoBrew! What's your order? \nEnter the number corresponding to the drink: \n");
}
//size selection
int select_size() {
    int size_choice;
    printf("Select the size:\n(1.) Tall\n(2.) Grande\n(3.) Venti\n");
    scanf("%d", &size_choice);
    return size_choice;
}
//asking wether hot or iced for espresso
char ask_hot_or_iced() {
    char hot_or_iced;
    printf("Would you like it hot or iced? (h for hot, i for iced): ");
    scanf(" %c", &hot_or_iced);
    return hot_or_iced;
}
//asking for add-on for frappucinno
int ask_for_addons() {
    int choice;
    printf("Would you like to have an add-on? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    return choice;
}
//asking the quantity of the order
int ask_for_quantity() {
    int quantity;
    printf("How many would you like? ");
    scanf("%d", &quantity);
    return quantity;
}

//collates information and summarizes order. Also returns final price of order
int order(menu_choice,drink_size,user_order,order_quantity,extra){
    int i,price;
    //prices of espressos arranged respective to their menu order ex: espresso[0][1] corresponds to 145; or a grande[1] caffe americano[0]
    int espresso_prices[8][3] = {{130,145,160},{140,155,170},{140,155,170},{165,180,195},{165,180,195},{165,180,195},{165,180,195},{120,130,0}};
    
    int frappucino_prices[12][3] = {{165,180,195},{165,180,}};
    int frappucino_addons[7] = {20,30,20,20,20,20,20,20};

    int teavana_prices[13][3] = {};
    
    if (menu_choice==1)
    {
        price = (espresso_prices[user_order-1][drink_size-1])*order_quantity; 
    }
    else if (menu_choice==2) //extra in this instance, are the optional add ons the user can add to their order if they choose the frappacino option
    {
        price = ((frappucino_prices[user_order-1][drink_size-1])*order_quantity)+extra;     
    }
    else if (menu_choice==3)//for menu options 1 & 3, extra is set to zero and does not influence its final price(see void(main) as to how these values are set/equated). 
    {
        price = ((teavana_prices[user_order-1][drink_size-1])*order_quantity)+extra;     
    }
    
    return price;

}

void receipt(menu_choice,drink_size,order_quantity,user_order){
}

int main(void) {
    char done[10];
    int menu_choice;
    int drink_size;
    char hot_or_iced;
    int add_on_choice;
    int order_quantity;
    int user_order;
    int extra = 0;
    int order_iteration = 0;
    int all_orders[50][4];
    int i;
    //all orders acts as a index/placeholder for all order information
    //all_orders[n][m], n corresponds to a each order iteration (essentially each order made by the user, first order, second order etc.)
    //all_orders[n][m], m corresponds to each order information
        //all_orders[n][0], 0 correponds to order type either, (0 = menu choice; espresso, frappucino, tea)
        //all_orders[n][1], 1 corresponds to size (tall, grande, venti)
        //all_orders[n][2], 2 corresponds to quantity
        //all_orders[n][3], 3 corresponds to the user order itself.

    do {
        display_menu();
        printf("What type of drink would you like?");
        scanf("%d", &menu_choice);
        order();

        ask_for_order();
        scanf("%d", &menu_choice);
        all_orders[order_iteration][0] = menu_choice;

        drink_size = select_size();
        all_orders[order_iteration][1] = select_size;

        order_quantity = ask_for_quantity();
        all_orders[order_iteration][2] = order_quantity;
        
        if (menu_choice == 1) { // Espresso
            menu_espresso();
            scanf("%i",&user_order);    
            hot_or_iced = ask_hot_or_iced();
            order(menu_choice,drink_size,user_order,order_quantity,extra);
        }
        else if (menu_choice == 2) { // Frappuccino
            menu_frapuccino();
            scanf("%i",&user_order);
            add_on_choice = ask_for_addons();
            order(menu_choice,drink_size,user_order,order_quantity,add_on_choice);   
        }
        else if(menu_choice == 3){
            menu_teavanatea();
            scanf("%i",&user_order);
            order(menu_choice,drink_size,user_order,order_quantity,extra);
        }
        all_orders[order_iteration][3] = user_order;

        printf("\nWould you like to order another drink? (Type 'yes' to add and 'done' to finish): ");
        scanf("%s", done);
        order_iteration++;
    } 
    
    while (strcmp(done, "done") != 0); {
        printf("\nProceeding to payment...\n");
        //print receip
        for (i = 0; i < order_iteration+1; i++)
        {
            /* code */
        }
        
    }

    return 0;
}
