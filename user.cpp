#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class User {
public:
    std::string Name;
    std::string Email;
    std::string PhoneNumber;

    void AddUser(std::vector<User>& users) {
        User newUser;
        std::cout << "***************************************\n";
        std::cout << "Enter your Name: ";
        std::getline(std::cin, newUser.Name);
        std::cout << "Enter your Email: ";
        std::getline(std::cin, newUser.Email);
        std::cout << "Enter your Phone Number: ";
        std::getline(std::cin, newUser.PhoneNumber);

        users.push_back(newUser);
        std::cout << "*************************\n";
        std::cout << "The name is " << newUser.Name << "\n";
        std::cout << "The Email is " << newUser.Email << "\n";
        std::cout << "The Phone Number is " << newUser.PhoneNumber << "\n";
    }

    void UpdateUser(std::vector<User>& users) {
        std::cout << "Enter Phone Number to update: ";
        std::string phoneNum;
        std::getline(std::cin, phoneNum);
        auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
            return user.PhoneNumber == phoneNum;
        });

        if (it != users.end()) {
            std::cout << "Choose number for update\n1 - Name\n2 - Email\n3 - Phone Number\n";
            int choice;
            std::cin >> choice;
            std::cin.ignore(); // Clear newline from the input buffer

            if (choice == 1) {
                std::cout << "Enter New Name: ";
                std::getline(std::cin, it->Name);
            } else if (choice == 2) {
                std::cout << "Enter New Email: ";
                std::getline(std::cin, it->Email);
            } else if (choice == 3) {
                std::cout << "Enter New Phone Number: ";
                std::getline(std::cin, it->PhoneNumber);
            } else {
                std::cout << "Invalid option\n";
            }
            std::cout << "Updated Name: " << it->Name << "\n";
            std::cout << "Updated Email: " << it->Email << "\n";
            std::cout << "Updated Phone Number: " << it->PhoneNumber << "\n";
        } else {
            std::cout << "User not found.\n";
        }
    }

    void DeleteUser(std::vector<User>& users) {
        std::cout << "Enter Phone Number to delete: ";
        std::string phoneNum;
        std::getline(std::cin, phoneNum);
        auto it = std::remove_if(users.begin(), users.end(), [&](const User& user) {
            return user.PhoneNumber == phoneNum;
        });

        if (it != users.end()) {
            std::cout << "Deleted user: " << it->Name << "\n";
            users.erase(it, users.end());
        } else {
            std::cout << "User not found.\n";
        }
    }

    void PrintAllUsers(const std::vector<User>& users) {
        if (users.empty()) {
            std::cout << "No users to display.\n";
            return;
        }

        int count = 1;
        for (const auto& user : users) {
            std::cout << "User " << count << ":\n";
            std::cout << "Name: " << user.Name << "\n";
            std::cout << "Email: " << user.Email << "\n";
            std::cout << "Phone Number: " << user.PhoneNumber << "\n";
            count++;
        }
    }
};

int main() {
    std::vector<User> users;
    User userManager;
    bool running = true;

    while (running) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add User\n";
        std::cout << "2. Update User\n";
        std::cout << "3. Delete User\n";
        std::cout << "4. Print All Users\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from the input buffer

        switch (choice) {
            case 1:
                userManager.AddUser(users);
                break;
            case 2:
                userManager.UpdateUser(users);
                break;
            case 3:
                userManager.DeleteUser(users);
                break;
            case 4:
                userManager.PrintAllUsers(users);
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}