#include <stdio.h>

int main() {
    const int correct_pin = 123;
    int entered_pin, balance = 5, amount;
    int attempts = 0, choice = 0;
    int last_withdraw = 0, last_deposit = 0;

    // Login loop (max 3 attempts)
    while (attempts < 3) {
        printf("Enter your PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == correct_pin) {
            // Successful login
            do {
                printf("\n==== ATM MENU ====\n");
                printf("1. Check Balance\n");
                printf("2. Withdraw\n");
                printf("3. Deposit\n");
                printf("4. Mini Statement\n");
                printf("5. Exit\n");
                printf("Choose an option: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Your balance is: %d\n", balance);
                        break;

                    case 2:
                        printf("Enter amount to withdraw: ");
                        scanf("%d", &amount);
                        if (amount > 0 && amount <= balance) {
                            balance -= amount;
                            last_withdraw = amount;
                            printf("Withdrawal successful. New balance: %d\n", balance);
                        } else {
                            printf("Invalid amount or insufficient balance.\n");
                        }
                        break;

                    case 3:
                        printf("Enter amount to deposit: ");
                        scanf("%d", &amount);
                        if (amount > 0) {
                            balance += amount;
                            last_deposit = amount;
                            printf("Deposit successful. New balance: %d\n", balance);
                        } else {
                            printf("Invalid deposit amount.\n");
                        }
                        break;

                    case 4:
                        printf("Mini Statement:\n");
                        printf("Last Withdraw: %d\n", last_withdraw);
                        printf("Last Deposit: %d\n", last_deposit);
                        printf("Current Balance: %d\n", balance);
                        break;

                    case 5:
                        printf("Thank you for using the ATM.\n");
                        break;

                    default:
                        printf("Invalid option. Please choose again.\n");
                }

            } while (choice != 5);

            return 0;  // Exit program after successful session
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts left: %d\n", 3 - attempts);
        }
    }

    // If max attempts reached
    printf("Too many incorrect attempts. Account locked.\n");
    return 0;
}
