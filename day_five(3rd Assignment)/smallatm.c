#include <stdio.h>

int main() {
    char pass = 123, pin, tries = 0;
    short bal = 5, amt;
    char opt = 0;

    while (tries < 3) {
        printf("PIN: ");
        scanf("%hhd", &pin);

        if (pin == pass) {
            while (opt != 5) {
                printf("\n1.Bal 2.W 3.D 4.Exit\n");
                scanf("%hhd", &opt);

                if (opt == 1)
                    printf("B:%d\n", bal);
                else if (opt == 2) {
                    printf("W?: ");
                    scanf("%hd", &amt);
                    if (amt > 0 && amt <= bal) bal -= amt;
                    else printf("Err\n");
                }
                else if (opt == 3) {
                    printf("D?: ");
                    scanf("%hd", &amt);
                    if (amt > 0) bal += amt;
                    else printf("Err\n");
                }
                else if (opt == 4 || opt == 5)
                    printf("Bye\n");
                else
                    printf("Inv\n");
            }
            return 0;
        } else {
            tries++;
            printf("Bad\n");
        }
    }

    printf("LOCKED\n");
    return 0;
}
