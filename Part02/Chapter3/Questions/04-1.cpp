#include <iostream>

using namespace std;

class FruitSeller {
    private :
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public :
        void InitMembers(int price, int num, int money) {
            APPLE_PRICE = price;
            numOfApples = num;
            myMoney = money;
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
    void InitMembers(int money) {
        myMoney = money;
        numOfApples = 0;
    }

    bool BuyApples(FruitSeller &seller, int money) {
        // Limit parameter money less than 0
        if (money < 0) {
            cout << "You can't give less than 0" << endl << endl;
            return false;
        }
        numOfApples += seller.SaleApples(money);
        myMoney -= money;

        return true;
    }

    void ShowBuyResult() const {
        cout << "Current Balance: " << myMoney << endl;
        cout << "Number of Apple: " << numOfApples << endl;
    }
};

int main(void) {
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(50000);
    
    buyer.BuyApples(seller, 2000);

    cout << "Current State of Fruit Seller" << endl;
    seller.ShowSalesResult();
    cout << "Current State of Fruit Buyer" << endl;
    buyer.ShowBuyResult();

    return 0;
}