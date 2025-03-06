# Café Management System

## Introduction

The Café Management System is a simple C program that allows users to view a menu, place orders, review their orders, and calculate the total bill. The menu items are loaded from a file (`menu.txt`), and users can interact through a command-line interface.

## Features

- Load menu items from `menu.txt`
- Display the menu
- Take customer orders
- Show ordered items
- Calculate the total bill

## Prerequisites

To compile and run this program, you need:

- A C compiler (such as GCC)
- A `menu.txt` file with menu items formatted as follows:
  ```
  1 Coffee 50
  2 Tea 20
  3 Sandwich 70
  4 Cake 180
  5 Juice 60
  6 Salad 30
  7 Pizza 250
  8 Burger 50
  ```
  Each line consists of an item ID, name, and price.

## How to Compile and Run

1. Compile the program using GCC:
   ```sh
   gcc cafe_management.c -o cafe_management
   ```
2. Run the executable:
   ```sh
   ./cafe_management
   ```

## Usage

Upon running the program, users can choose from the following options:

1. Display Menu – View available items.
2. Take Order – Select an item and specify quantity.
3. Display Orders – Show all items ordered so far.
4. Calculate Bill – Get the total bill amount.
5. Exit – Quit the program.

## Potential Improvements

- Save orders to a file for record-keeping.
- Allow multiple customers to order.
- Implement an admin mode to modify the menu.

## Issues

- The program expects a properly formatted `menu.txt` file.
- If an invalid item number is entered, the program recursively calls `take_order`, which may lead to stack overflow in extreme cases.

## License

This project is open-source and can be modified as needed.