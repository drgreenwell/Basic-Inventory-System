#include <iostream>
#include <string>
#include <unordered_map>

// Item class to store details of each item
class Item {
public:
    std::string name;
    int quantity;
    double price;

    Item() : name(""), quantity(0), price(0.0) {}

    Item(std::string name, int quantity, double price)
        : name(name), quantity(quantity), price(price) {}
};

// Inventory class to manage the collection of items
class Inventory {
private:
    std::unordered_map<std::string, Item> items;

public:
    void addItem(const std::string& name, int quantity, double price) {
        items[name] = Item(name, quantity, price);
        std::cout << "Item added: " << name << "\n";
    }

    void removeItem(const std::string& name) {
        if (items.erase(name)) {
            std::cout << "Item removed: " << name << "\n";
        } else {
            std::cout << "Item not found: " << name << "\n";
        }
    }

    void updateItem(const std::string& name, int quantity, double price) {
        auto it = items.find(name);
        if (it != items.end()) {
            it->second.quantity = quantity;
            it->second.price = price;
            std::cout << "Item updated: " << name << "\n";
        } else {
            std::cout << "Item not found: " << name << "\n";
        }
    }

    void displayInventory() const {
        std::cout << "Inventory:\n";
        for (const auto& pair : items) {
            std::cout << "Name: " << pair.second.name
                      << ", Quantity: " << pair.second.quantity
                      << ", Price: $" << pair.second.price << "\n";
        }
    }
};

int main() {
    Inventory inventory;
    int choice;
    std::string name;
    int quantity;
    double price;

    do {
        std::cout << "\nInventory Management System\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Remove Item\n";
        std::cout << "3. Update Item\n";
        std::cout << "4. Display Inventory\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item name: ";
                std::cin >> name;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter price: ";
                std::cin >> price;
                inventory.addItem(name, quantity, price);
                break;
            case 2:
                std::cout << "Enter item name to remove: ";
                std::cin >> name;
                inventory.removeItem(name);
                break;
            case 3:
                std::cout << "Enter item name to update: ";
                std::cin >> name;
                std::cout << "Enter new quantity: ";
                std::cin >> quantity;
                std::cout << "Enter new price: ";
                std::cin >> price;
                inventory.updateItem(name, quantity, price);
                break;
            case 4:
                inventory.displayInventory();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}