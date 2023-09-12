
#include <stdio.h>

struct Account {
    int accountNumber;
    int pin;
    double balance;
};



void displayBalance(struct Account *account) {
    printf("Account Balance: $%.2lf\n", account->balance);
}

void deposit(struct Account *account, double amount) {
    account->balance += amount;
    printf("Deposited $%.2lf into the account.\n", amount);
}


void withdraw(struct Account *account, double amount) {
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn $%.2lf from the account.\n", amount);
    } else {
        printf("Insufficient balance. Withdrawal failed.\n");
    }
}


int main() {
    struct Account userAccount;
    userAccount.accountNumber = 12345;
    userAccount.pin = 1234;
    userAccount.balance = 1000.00;

    int option;
    double amount;

    printf("Welcome to the ATM Banking System\n");
    printf("Please enter your account number: ");
    int enteredAccount;
    scanf("%d", &enteredAccount);

    if (enteredAccount != userAccount.accountNumber) {
        printf("Invalid account number. Exiting...\n");
        return 1;
    }

    printf("Please enter your PIN: ");
    int enteredPin;
    scanf("%d", &enteredPin);


    if (enteredPin != userAccount.pin) {
        printf("Incorrect PIN. Exiting...\n");
        return 1;
    }

    printf("Login successful.\n");

    do {
        printf("\nOptions:\n");
        printf("1. Display Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayBalance(&userAccount);
                break;
            case 2:
                printf("Enter the amount to deposit: $");
                scanf("%lf", &amount);
                deposit(&userAccount, amount);
                break;
            case 3:
                printf("Enter the amount to withdraw: $");
                scanf("%lf", &amount);
                withdraw(&userAccount, amount);
                break;
            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}
