#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

class Product
{
public:
    string id;
    string productName;
    float unitPrice;
    string categoryType;

    Product(string productId, string name, float price, string category)
    {
        id = productId;
        productName = name;
        unitPrice = price;
        categoryType = category;
    }
};

class CartItem
{
public:
    Product productDetail;
    int quantityOrdered;

    CartItem(Product product, int quantity) : productDetail(product), quantityOrdered(quantity) {}
};

class Cart
{
private:
    vector<CartItem> cartItems;
    unordered_map<string, float> discountRates;

public:
    Cart()
    {
        discountRates["Electronics"] = 0.10;
        discountRates["Fashion"] = 0.50;
    }

    void addProductToCart(Product product, int quantity)
    {
        for (auto &item : cartItems)
        {
            if (item.productDetail.id == product.id)
            {
                item.quantityOrdered += quantity;
                return;
            }
        }
        cartItems.push_back(CartItem(product, quantity));
    }

    void removeProductFromCart(string productId, int quantity)
    {
        for (auto it = cartItems.begin(); it != cartItems.end(); ++it)
        {
            if (it->productDetail.id == productId)
            {
                it->quantityOrdered -= quantity;
                if (it->quantityOrdered <= 0)
                    cartItems.erase(it);
                return;
            }
        }
        cout << "Item not found in the cart!" << endl;
    }

    void displayCart()
    {
        float totalCost = 0;
        cout << "Your Cart:" << endl;
        for (auto &item : cartItems)
        {
            float cost = item.productDetail.unitPrice * item.quantityOrdered;
            cout << item.productDetail.productName << " - Quantity: " << item.quantityOrdered
                 << ", Price: " << fixed << setprecision(2) << item.productDetail.unitPrice
                 << " USD, Total: " << cost << " USD" << endl;
            totalCost += cost;
        }
        cout << "Total (before discounts): " << totalCost << " USD" << endl;
    }

    void showDiscounts()
    {
        cout << "Available Discounts:" << endl;
        cout << "1. 10% Off on Electronics" << endl;
        cout << "2. Buy 1 Get 1 Free on Fashion" << endl;
    }

    void processCheckout()
    {
        float totalCost = 0, totalDiscount = 0;
        cout << "Applying discounts..." << endl;
        for (auto &item : cartItems)
        {
            float itemCost = item.productDetail.unitPrice * item.quantityOrdered;
            float itemDiscount = 0;

            if (item.productDetail.categoryType == "Fashion" && item.quantityOrdered > 1)
            {
                int freeItems = item.quantityOrdered / 2;
                itemDiscount = freeItems * item.productDetail.unitPrice;
                cout << "Buy 1 Get 1 Free on " << item.productDetail.productName << " applied." << endl;
            }
            else if (item.productDetail.categoryType == "Electronics")
            {
                itemDiscount = itemCost * discountRates["Electronics"];
                cout << "10% off on " << item.productDetail.productName << " applied." << endl;
            }

            totalDiscount += itemDiscount;
            totalCost += itemCost;
        }

        float finalAmount = totalCost - totalDiscount;
        cout << "Final Total in USD: " << finalAmount << endl;

        string convertCurrency;
        cout << "Would you like to view it in a different currency? (yes/no): ";
        cin >> convertCurrency;
        if (convertCurrency == "yes")
        {
            string currencyCode;
            cout << "Available Currencies: EUR, GBP" << endl;
            cout << "Enter currency: ";
            cin >> currencyCode;

            if (currencyCode == "EUR")
                cout << "Final Total in EUR: " << finalAmount * 0.85 << endl;
            else if (currencyCode == "GBP")
                cout << "Final Total in GBP: " << finalAmount * 0.75 << endl;
        }
    }
};

int main()
{
    vector<Product> productCatalog = {
        Product("P001", "Laptop", 1000.00, "Electronics"),
        Product("P002", "Phone", 500.00, "Electronics"),
        Product("P003", "T-Shirt", 20.00, "Fashion")};

    Cart myCart;
    string userCommand;

    while (true)
    {
        cout << "Enter command: ";
        cin >> userCommand;

        if (userCommand == "add_to_cart")
        {
            string productId;
            int quantity;
            cin >> productId >> quantity;

            bool found = false;
            for (auto &product : productCatalog)
            {
                if (product.id == productId)
                {
                    myCart.addProductToCart(product, quantity);
                    found = true;
                    break;
                }
            }
            if (found == 0)
            {
                cout << "Product not found!" << endl;
            }
        }
        else if (userCommand == "remove_from_cart")
        {
            string productId;
            int quantity;
            cin >> productId >> quantity;
            myCart.removeProductFromCart(productId, quantity);
        }
        else if (userCommand == "view_cart")
        {
            myCart.displayCart();
        }
        else if (userCommand == "list_discounts")
        {
            myCart.showDiscounts();
        }
        else if (userCommand == "checkout")
        {
            myCart.processCheckout();
            break;
        }
        else
        {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}

