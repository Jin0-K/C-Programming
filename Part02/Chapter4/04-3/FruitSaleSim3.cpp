#include <iostream>

using namespace std;

class FruitSeller {
    private :
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public :
        FruitSeller(int price, int num, int money)
            : APPLE_PRICE(price), numOfApples(num), myMoney(money) {
        }

        int SaleApples(int money) {
            int num = money / APPLE_PRICE;
            numOfApples -= num;
            myMoney += money;
            return num;
        }

        void ShowSalesResult() const {
            cout << "Apples Left: " << numOfApples << endl;
            cout << "Sales Benefit: " << myMoney << endl;
        }
};

class FruitBuyer {
    int myMoney;    // private :
    int numOfApples;    // private :
public :
    FruitBuyer(int money)
        : myMoney(money), numOfApples(0) {
    }

    void BuyApples(FruitSeller &seller, int money) {
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }

    void ShowBuyResult() const {
        cout << "Current Balance: " << myMoney << endl;
        cout << "Number of Apple: " << numOfApples << endl;
    }
};

int main(void) {
    FruitSeller seller(1000, 20, 0);
    FruitBuyer buyer(5000);
    
    buyer.BuyApples(seller, 2000);

    cout << "Current State of Fruit Seller" << endl;
    seller.ShowSalesResult();
    cout << "Current State of Fruit Buyer" << endl;
    buyer.ShowBuyResult();

    return 0;
}