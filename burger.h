#ifndef BURGER_H
#define BURGER_H

#include <string>

enum proteinType { BEEF, TURKEY, CHICKEN, MUSH, VEGGIE };
enum condimentType { KETCHUP, MUSTARD, MAYO, SPECIAL, BBQ, STEAK, PEPPERCORN, NOCOND };
enum toppingType { GRILLONION, RAWONION, TOMATO, LETTUCE, BACON, MUSHROOM, PICKLE, NOTOP };
enum bunType { BRIOCHE, WHEAT, SESAME, ONION, RYE, NOBUN, GLUTENFREE };
enum cheeseType { CHEDDAR, AMERICAN, PEPPERJACK, SWISS, COLBYJACK, NOCHEESE };

class Burger {
private:
    proteinType protein;
    condimentType condiments[7];
    toppingType toppings[7];
    bunType bun;
    cheeseType cheese;
    int numPatties;
    bool isVeg;
    int numCondiments;
    int numToppings;

    void updateVegStatus();

public:
    Burger(proteinType p, condimentType c[], int nc, toppingType t[], int nt, bunType b, cheeseType ch, int np);

    proteinType getProtein() const;
    std::string getCondiments() const;
    std::string getToppings() const;
    bunType getBun() const;
    cheeseType getCheese() const;
    bool isVegetarian() const;
    int getNumPatties() const;
    double getPrice() const;

    void setProtein(proteinType p);
    void setCondiments(condimentType c[], int nc);
    void setToppings(toppingType t[], int nt);
    void setBun(bunType b);
    void setCheese(cheeseType ch);
    void setNumPatties(int np);

    std::string toString() const;
};

std::string proteinToString(proteinType protein);
std::string condimentToString(condimentType condiment);
std::string toppingToString(toppingType topping);
std::string bunToString(bunType bun);
std::string cheeseToString(cheeseType cheese);

#endif // BURGER_H
