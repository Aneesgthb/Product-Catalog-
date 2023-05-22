#include <stdio.h>
#include <string.h>

#define PRODUCT_COUNT 3
#define MAX_QUANTITY 100

typedef struct {
    char name[20];
    int price;
    int quantity;
    int isGift;
} Product;

int main() {
    Product catalog[PRODUCT_COUNT] = {
        {"Product A", 20, 0, 0},
        {"Product B", 40, 0, 0},
        {"Product C", 50, 0, 0}
    };
    
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("Enter the quantity of %s: ", catalog[i].name);
        scanf("%d", &catalog[i].quantity);
        printf("Is %s a gift? (0 for No, 1 for Yes): ", catalog[i].name);
        scanf("%d", &catalog[i].isGift);
    }
    
    int subtotal = 0;
    
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        subtotal += catalog[i].price * catalog[i].quantity;
    }
    
    int totalQuantity = 0;
    int maxDiscountAmount = 0;
    char discountName[30];
    
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        totalQuantity += catalog[i].quantity;
        
        if (catalog[i].quantity > 15 && catalog[i].quantity * catalog[i].price * 0.5 > maxDiscountAmount) {
            maxDiscountAmount = catalog[i].quantity * catalog[i].price * 0.5;
            strcpy(discountName, "tiered_50_discount");
        } else if (catalog[i].quantity > 10 && catalog[i].quantity * catalog[i].price * 0.05 > maxDiscountAmount) {
            maxDiscountAmount = catalog[i].quantity * catalog[i].price * 0.05;
            strcpy(discountName, "bulk_5_discount");
        }
    }
    
    if (totalQuantity > 20 && subtotal * 0.1 > maxDiscountAmount) {
        maxDiscountAmount = subtotal * 0.1;
        strcpy(discountName, "bulk_10_discount");
    } else if (subtotal > 200 && 10 > maxDiscountAmount) {
        maxDiscountAmount = 10;
        strcpy(discountName, "flat_10_discount");
    }
    
    int shippingPackages = (totalQuantity + 9) / 10;
    int shippingFee = shippingPackages * 5;
    int giftWrapFee = 0;
    
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        if (catalog[i].isGift) {
            giftWrapFee += catalog[i].quantity;
        }
    }
    
    giftWrapFee *= 1;
    
    int total = subtotal - maxDiscountAmount + shippingFee + giftWrapFee;
    
    printf("\nProduct Details:\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%s: Quantity: %d, Total: $%d\n", catalog[i].name, catalog[i].quantity, catalog[i].price * catalog[i].quantity);
    }
    
    printf("Subtotal: $%d\n", subtotal);
    printf("Discount Applied: %s\n", discountName);
    printf("Shipping Fee: $%d\n", shippingFee);
    printf("Gift Wrap Fee: $%d\n", giftWrapFee);
    printf("Total: $%d\n",total);
}

    
