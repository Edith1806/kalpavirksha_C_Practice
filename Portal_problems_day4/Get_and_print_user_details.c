#include<stdio.h>
#include<string.h>

struct User
{
    char name[30];
    int age;
    int product_quantity;
    float price;
};

void get_user_details(struct User *user_details)
{
    fgets(user_details->name, sizeof(user_details->name), stdin);
    user_details->name[strcspn(user_details->name, "\n")] = '\0';
    scanf("%d",&user_details->age);
    scanf("%d",&user_details->product_quantity);
    scanf("%f",&user_details->price);
}
int main(void)
{
    struct User user_details;
    get_user_details(&user_details);
    printf("Name:  %s\nAge:  %d\nProduct Quantity:  %d\nPrice:  %.2f",user_details.name, user_details.age, user_details.product_quantity, user_details.price);
    return 0;
}