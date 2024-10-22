# quriousbit
# Shopping Cart System

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Product Catalog](#product-catalog)
- [Available Discounts](#available-discounts)
- [Currency Conversion](#currency-conversion)


## Overview
This is a C++ program that simulates an online shopping cart. Users can add products to a cart, view cart contents, apply discounts, and checkout. The checkout process includes discount application and optional currency conversion.

## Features
- **Add to Cart**: Add products to the shopping cart by specifying product ID and quantity.
- **Remove from Cart**: Remove a specified quantity of a product from the cart.
- **View Cart**: Display all products in the cart with their quantities, prices, and the total cost.
- **List Discounts**: Show the available discounts.
- **Checkout**: Apply discounts, show the final total, and convert the total into different currencies (optional).


## Usage
Once the program starts, you can use the following commands:

1. **add_to_cart**: Add a product to the cart by specifying the product ID and quantity.
    ```bash
    add_to_cart <productID> <quantity>
    ```
    Example:
    ```bash
    add_to_cart P001 2
    ```

2. **remove_from_cart**: Remove a specified quantity of a product from the cart.
    ```bash
    remove_from_cart <productID> <quantity>
    ```
    Example:
    ```bash
    remove_from_cart P001 1
    ```

3. **view_cart**: View the current contents of the shopping cart, including product quantities, prices, and the total cost before discounts.
    ```bash
    view_cart
    ```

4. **list_discounts**: View the available discounts.
    ```bash
    list_discounts
    ```

5. **checkout**: Proceed to checkout, apply available discounts, and view the final total. You can also convert the total to different currencies (EUR, GBP).
    ```bash
    checkout
    ```

After the checkout is complete, the program will exit.

## Product Catalog
Here are the predefined products available for purchase:

| Product ID | Name    | Price (USD) | Category    |
|------------|---------|-------------|-------------|
| P001       | Laptop  | 1000.00     | Electronics |
| P002       | Phone   | 500.00      | Electronics |
| P003       | T-Shirt | 20.00       | Fashion     |

## Available Discounts
- **Electronics**: 10% discount on all electronics products.
- **Fashion**: Buy 1 Get 1 Free on fashion items (for quantities of 2 or more).

## Currency Conversion
During checkout, users can choose to convert the final total into the following currencies:
- **EUR** (Euro): Conversion rate is 1 USD = 0.85 EUR.
- **GBP** (British Pound): Conversion rate is 1 USD = 0.75 GBP.


