#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = rand() % 1 + 3;
        for (int i = 0; i < SIZE; i++)
        prices[i] = (double) (rand() % 89999 + 10000)/100.0;
    }
    Chair(int l, double p[]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
        prices[i] = p[i];
    }

    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
        cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double *prices = new double[SIZE];
    prices[0] = 525.25;
    prices[1] = 434.34;
    prices[2] = 252.52;
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    Chair *chair1 = new Chair;
    Chair *chair2 = new Chair;
    Chair *chair3 = new Chair;
    collection[0] = *chair1;
    //collection[0].setLegs(4);
    //collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1] = *chair2;
    //collection[1].setLegs(4);
    //collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2] = *chair3;
    //collection[2].setLegs(4);
    //collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    return 0;
}