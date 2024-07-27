#include "burger.h"
#include <string>
using namespace std;

string proteinToString(proteinType protein) {
    switch (protein) {
        case BEEF: return "Beef";
        case TURKEY: return "Turkey";
        case CHICKEN: return "Chicken Breast";
        case MUSH: return "Portabella Mushroom";
        case VEGGIE: return "Veggie";
    }
    return "";
}

string condimentToString(condimentType condiment) {
    switch (condiment) {
        case KETCHUP: return "Ketchup";
        case MUSTARD: return "Mustard";
        case MAYO: return "Mayonnaise";
        case SPECIAL: return "Special Sauce";
        case BBQ: return "BBQ Sauce";
        case STEAK: return "Steak Sauce";
        case PEPPERCORN: return "Peppercorn Ranch";
        case NOCOND: return "None";
    }
    return "";
}

string toppingToString(toppingType topping) {
    switch (topping) {
        case GRILLONION: return "Grilled Onion";
        case RAWONION: return "Raw Onion";
        case TOMATO: return "Tomato";
        case LETTUCE: return "Lettuce";
        case BACON: return "Bacon";
        case MUSHROOM: return "Grilled Mushroom";
        case PICKLE: return "Pickle";
        case NOTOP: return "None";
    }
    return "";
}

string bunToString(bunType bun) {
    switch (bun) {
        case BRIOCHE: return "Brioche";
        case WHEAT: return "Wheat";
        case SESAME: return "Sesame";
        case ONION: return "Onion";
        case RYE: return "Rye Bread";
        case NOBUN: return "None";
        case GLUTENFREE: return "Gluten Free";
    }
    return "";
}

string cheeseToString(cheeseType cheese) {
    switch (cheese) {
        case CHEDDAR: return "Cheddar";
        case AMERICAN: return "American";
        case PEPPERJACK: return "Pepper Jack";
        case SWISS: return "Swiss";
        case COLBYJACK: return "Colby Jack";
        case NOCHEESE: return "None";
    }
    return "";
}

Burger::Burger(proteinType p, condimentType c[], int nc, toppingType t[], int nt, bunType b, cheeseType ch, int np)
    : protein(p), bun(b), cheese(ch), numPatties(np), numCondiments(nc), numToppings(nt) {
    for (int i = 0; i < nc; ++i) {
        condiments[i] = c[i];
    }
    for (int i = 0; i < nt; ++i) {
        toppings[i] = t[i];
    }
    updateVegStatus();
}

proteinType Burger::getProtein() const { return protein; }

string Burger::getCondiments() const {
    string result;
    for (int i = 0; i < numCondiments; ++i) {
        result += condimentToString(condiments[i]);
        if (i < numCondiments - 1) result += ", ";
    }
    return result;
}

string Burger::getToppings() const {
    string result;
    for (int i = 0; i < numToppings; ++i) {
        result += toppingToString(toppings[i]);
        if (i < numToppings - 1) result += ", ";
    }
    return result;
}

bunType Burger::getBun() const { return bun; }

cheeseType Burger::getCheese() const { return cheese; }

bool Burger::isVegetarian() const { return isVeg; }

int Burger::getNumPatties() const { return numPatties; }

double Burger::getPrice() const {
    double price = 0.0;
    switch (protein) {
        case BEEF: price = 3.5; break;
        case TURKEY: price = 4.0; break;
        case CHICKEN: price = 4.0; break;
        case MUSH: price = 4.5; break;
        case VEGGIE: price = 4.5; break;
    }
    price *= numPatties;
    price += numToppings * 0.5;
    price += numCondiments * 0.25;
    if (cheese != NOCHEESE) price += 0.10;
    return price;
}

void Burger::setProtein(proteinType p) { protein = p; updateVegStatus(); }

void Burger::setCondiments(condimentType c[], int nc) {
    numCondiments = nc;
    for (int i = 0; i < nc; ++i) {
        condiments[i] = c[i];
    }
}

void Burger::setToppings(toppingType t[], int nt) {
    numToppings = nt;
    for (int i = 0; i < nt; ++i) {
        toppings[i] = t[i];
    }
    updateVegStatus();
}

void Burger::setBun(bunType b) { bun = b; }

void Burger::setCheese(cheeseType ch) { cheese = ch; }

void Burger::setNumPatties(int np) { numPatties = np; }

string Burger::toString() const {
    string result = "Protein: " + proteinToString(protein) + "\n";
    result += "Number of patties: " + to_string(numPatties) + "\n";
    result += "Bun Type: " + bunToString(bun) + "\n";
    result += "Cheese: " + cheeseToString(cheese) + "\n";
    result += "Condiments: " + getCondiments() + "\n";
    result += "Toppings: " + getToppings() + "\n";
    if (isVegetarian()) result += "This is a vegetarian burger.\n";
    return result;
}

void Burger::updateVegStatus() {
    isVeg = (protein == MUSH || protein == VEGGIE);
    for (int i = 0; i < numToppings; ++i) {
        if (toppings[i] == BACON) {
            isVeg = false;
            break;
        }
    }
}
