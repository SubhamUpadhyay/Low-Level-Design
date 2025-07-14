#include <iostream>
#include <string>
using namespace std;

// The final product
class Burger {
private:
    string bun;
    string patty;
    string sauce;

    // Only builder can access private members
    Burger() {}

    friend class BurgerBuilder;

public:
    void showBurger() {
        cout << "Burger with " << bun << ", " << patty << ", and " << sauce << "." << endl;
    }
};

// The Builder class
class BurgerBuilder {
private:
    Burger b;

public:
    BurgerBuilder& setBun(const string& bunType) {
        b.bun = bunType;
        return *this;
    }

    BurgerBuilder& setPatty(const string& pattyType) {
        b.patty = pattyType;
        return *this;
    }

    BurgerBuilder& setSauce(const string& sauceType) {
        b.sauce = sauceType;
        return *this;
    }

    Burger build() {
        return b;
    }
};

// The Director class
class BurgerDirector {
public:
    // Pre-defined burger recipe
    static Burger createVegBurger() {
        return BurgerBuilder()
            .setBun("Whole Wheat Bun")
            .setPatty("Veggie Patty")
            .setSauce("Tomato Sauce")
            .build();
    }

    static Burger createChickenBurger() {
        return BurgerBuilder()
            .setBun("Regular Bun")
            .setPatty("Chicken Patty")
            .setSauce("Mayo")
            .build();
    }
};

int main() {
    // Custom burger using builder
    Burger custom = BurgerBuilder()
        .setBun("Gluten-Free Bun")
        .setPatty("Paneer Patty")
        .setSauce("Mint Sauce")
        .build();

    custom.showBurger();

    cout << "\nUsing Director:\n";

    // Predefined burgers using director
    Burger veg = BurgerDirector::createVegBurger();
    veg.showBurger();

    Burger chicken = BurgerDirector::createChickenBurger();
    chicken.showBurger();
}
