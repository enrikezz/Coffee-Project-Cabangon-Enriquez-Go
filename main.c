#include <stdio.h>
#include <ctype.h>
#include <string.h>


//these variables are declared outside the functions - making them global. Meaning they can be accessed by all functions, without having them be declared in the respective function itself.

//prices of espressos arranged respective to their menu order ex: espresso[0][1] corresponds to 145; or a grande[1] caffe americano[0]
int espresso_prices[8][3] = {{130,145,160},{140,155,170},{140,155,170},{165,180,195},{165,180,195},{165,180,195},{165,180,195},{120,130,0}};
char *espressos[50] = {"Caffe Americano","Cappuccino","Caffe Latte","Caffe Mocha","Caramel Macchiato","Flat White","White Chocolate Mocha","Espresso"};

char *frappucino[50] = {"Caramel","Mocha","White Mocha","Coffee Jelly","Java Chip","Dark Mocha","Chocolate Cream","Vanilla Cream","Caramel Cream","Chocolate Chip Cream","Strawberries & Cream","Green Tea Cream"};
int frappucino_prices[12][3] = {{165,180,195},{165,180,195},{160,175,190},{170,185,200},{170,185,200},{180,195,210},{150,165,180},{150,165,180},{155,165,180},{170,185,200},{170,185,200},{170,185,200}};
int frappucino_addons_prices[7] = {20,30,20,20,20,20,20};
char *frappucino_addons[50] = {"Flavored Syrup","Espresso Shot","White Mocha","Heavy Cream","Cold Foam","Organic Soymilk","Breve"};

char *teavanas[50] = {"Ice Shaken Black Tea with Ruby Grapefruit and Honey","Ice Shaken Hibiscus Tea with Pomegranate Pearls",};
int teavana_prices[13][3] = {{140,155,170},{140,155,170},{155,170,185},{125,140,155},{125,140,155},{125,140,155},{140,155,170},{155,170,185},{155,170,185},{120,135,150},{125,140,155},{125,140,155},{125,140,155}};

int all_orders[50][4];
//all orders acts as a index/placeholder for all order information
    //all_orders[n][m], n corresponds to a each order iteration (essentially each order made by the user, first order, second order etc.)
    //all_orders[n][m], m corresponds to each order information
        //all_orders[n][0], 0 correponds to order type either/menu choice (espresso, frappucino, tea)
        //all_orders[n][1], 1 corresponds to size (tall, grande, venti)
        //all_orders[n][2], 2 corresponds to quantity
        //all_orders[n][3], 3 corresponds to the user order itself.




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
    printf("(1.)   - Flavored Syrup  +20\n");
    printf("(2.)   - Espresso Shot   +30\n");
    printf("(3.)   - White Mocha     +20\n");
    printf("(4.)   - Heavy Cream     +20\n");
    printf("(5.)   - Cold Foam       +20\n");
    printf("Substitute\n");
    printf("(6.)   - Organic Soymilk +20\n");
    printf("(7.)   - Breve           +20\n");
    printf("\nPlease enter the number of your addon of choice: \n");
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
    int i;
    int total = 0;

    do {
        display_menu();
        printf("What type of drink would you like?");
        scanf("%d", &menu_choice);
        all_orders[order_iteration][0] = menu_choice;
        //sets column 0 equal to menu choice

        drink_size = select_size();
        all_orders[order_iteration][1] = drink_size;
        //sets row n, column 1 to drink size

        order_quantity = ask_for_quantity();
        all_orders[order_iteration][2] = order_quantity;
        //sets row n, column 2 to order quantity
        
        if (menu_choice == 1) { // Espresso
            menu_espresso();
            scanf("%i",&user_order);    
            hot_or_iced = ask_hot_or_iced();
            all_orders[order_iteration][3] = user_order;
        }
        else if (menu_choice == 2) { // Frappuccino
            menu_frapuccino();
            scanf("%i",&user_order);
            add_on_choice = ask_for_addons();
            all_orders[order_iteration][3] = user_order;
            if (add_on_choice == 1)
            {
                order_iteration++;
                all_orders[order_iteration][0] = 4;
                menu_customize();
                scanf("%i",&user_order);
                all_orders[order_iteration][3] = user_order;
                order_quantity = ask_for_quantity();
                all_orders[order_iteration][2] = order_quantity;
            }
              
        }
        else if(menu_choice == 3){
            menu_teavanatea();
            scanf("%i",&user_order);
            all_orders[order_iteration][3] = user_order;
        }

        printf("\nWould you like to order another drink? (Type 'yes' to add and 'done' to finish): ");
        scanf("%s", done);
        order_iteration++;
    } 
    
    while (strcmp(done, "done") != 0); {
        printf("\nProceeding to payment...\n");
        //print receipt
        printf("Item            Price       Quantity        Subtotal");

        for (i = 0; i < order_iteration+1; i++)
        {
            //printf("\n%i",i);
            if (all_orders[i][0] == 1)
            {
                total = total + ((espresso_prices[all_orders[i][3]][all_orders[i][1]-1])*all_orders[i][2]);
                printf("\n%s     %i         %i           %i",espressos[all_orders[i][3]-1],espresso_prices[all_orders[i][3]][all_orders[i][1]-1],all_orders[i][2],(espresso_prices[all_orders[i][3]][all_orders[i][1]-1])*all_orders[i][2]);  
            }
            else if (all_orders[i][0] == 2)
            {
                total = total + ((frappucino_prices[all_orders[i][3]][all_orders[i][1]-1])*all_orders[i][2]);
                printf("\n%s     %i         %i           %i",frappucino[all_orders[i][3]-1],frappucino_prices[all_orders[i][3]][all_orders[i][1]-1],all_orders[i][2],(frappucino_prices[all_orders[i][3]][all_orders[i][1]-1])*all_orders[i][2]);  
            }
            else if (all_orders[i][0] == 3)
            {
                total = total + ((teavana_prices[all_orders[i][3]][all_orders[i][1]-1])*all_orders[i][2]);
                printf("\n%s     %i         %i           %i",teavanas[all_orders[i][3]-1],teavana_prices[all_orders[i][3]][all_orders[i][1]-1],all_orders[i][2],(teavana_prices[all_orders[i][3]][all_orders[i][1]-1])*all_orders[i][2]);  
            }
            else if (all_orders[i][0] == 4)
            {
                total = total + ((frappucino_addons_prices[all_orders[i][3]])*all_orders[i][2]);
                printf("\n%s     %i         %i           %i",frappucino_addons[all_orders[i][3]-1],frappucino_addons_prices[all_orders[i][3]],all_orders[i][2],(frappucino_addons_prices[all_orders[i][3]])*all_orders[i][2]);  
            }
            
        }
        printf("\nTotal Php                              %i",total);
    }

    return 0;
}
