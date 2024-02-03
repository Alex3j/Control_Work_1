#include <iostream>
#include <vector>
#include <string>

struct Account {
    std::string username;
    std::string password;
    int id;
};

std::vector<Account> accounts;

void addAccount() {
    Account newAccount;
    std::cout << "Enter username:";
    std::cin >> newAccount.username;
    std::cout << "Enter password:";
    std::cin >> newAccount.password;
    newAccount.id = accounts.size() + 1;
    accounts.push_back(newAccount);
}

void deleteAccount() {
    int id;
    std::cout << "Enter account ID to delete:";
    std::cin >> id;

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->id == id) {
            accounts.erase(it);
            break;
        }
    }
}

void updateAccount() {
    int id;
    std::cout << "Enter account ID to update:";
    std::cin >> id;

    for (auto& acc : accounts) {
        if (acc.id == id) {
            std::cout << "Enter new username:";
            std::cin >> acc.username;
            std::cout << "Enter new password:";
            std::cin >> acc.password;
            break;
        }
    }
}

void displayAccount(const Account& acc) {
    std::cout << "ID:" << acc.id << "Username:" << acc.username << "Password:" << acc.password << std::endl;
}

void displayAllAccounts() {
    for (const auto& acc : accounts) {
        displayAccount(acc);
    }
}

int main() {
    int choice;

    void (*funcPtrArr[])() = {addAccount, deleteAccount, updateAccount, displayAllAccounts};

    while (true) {
        std::cout << "1. Add account\n2. Delete account\n3. Update account\n4. Display all accounts\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            break;
        }

        if (choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        funcPtrArr[choice - 1]();
    }

    return 0;
}
