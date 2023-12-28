#include <stdio.h>

struct Account {
    int accountNumber;
    char holderName[50];
    float balance;
};

struct Account accounts[1000];
int accountCount = 0;

void createAccount() {
    printf("Enter account holder's name: ");
    scanf("%s", accounts[accountCount].holderName);

    accounts[accountCount].accountNumber = 1000 + accountCount; 
    accounts[accountCount].balance = 0;

    printf("Account created successfully. Account Number: %d\n", accounts[accountCount].accountNumber);
    accountCount++;
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = -1;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter deposit amount: ");
        scanf("%f", &amount);

        accounts[index].balance += amount;
        printf("Deposit successful. New balance: %.2f\n", accounts[index].balance);
    } else {
        printf("Account not found.\n");
    }
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = -1;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Enter withdrawal amount: ");
        scanf("%f", &amount);

        if (amount <= accounts[index].balance) {
            accounts[index].balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", accounts[index].balance);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Account not found.\n");
    }
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = -1;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Account Holder: %s\n", accounts[index].holderName);
        printf("Balance: %.2f\n", accounts[index].balance);
    } else {
        printf("Account not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n------------------------------------------ATM BANKING MANAGEMENT SYSTEM----------------------------------------");
        printf("\n\t 1. Create Account");
        printf("\n\t 2. Deposit Amount");
        printf("\n\t 3. Withdrawl Amount");
        printf("\n\t 4. Check Balance");
        printf("\n\t 5. Exit");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}