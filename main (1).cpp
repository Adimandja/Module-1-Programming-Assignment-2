#include <iostream>
#include <string>
#include "burger.h"
using namespace std;

proteinType chooseProtein() {
    int choice;
    cout << "Please choose a protein from the list.\n1: Beef\n2: Turkey\n3: Chicken Breast\n4: Portabella Mushroom\n5: Veggie\n";
    cin >> choice;
    return static_cast<proteinType>(choice - 1);
}

condimentType chooseCondiment() {
    int choice;
    cout << "Please choose a condiment from the list. Enter -1 to stop adding condiments.\n";
    cout << "1: Ketchup\n2: Mustard\n3: Mayonnaise\n4: Special Sauce\n5: BBQ Sauce\n6: Steak Sauce\n7: Peppercorn Ranch\n8: None\n";
