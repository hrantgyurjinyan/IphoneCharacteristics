#include "phone_list.h"

void add_phone(struct PhoneNode **head, struct Phone phone)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(struct PhoneNode));
        (*head)->phone = phone;
        (*head)->next = NULL;
    }
    else
    {
        struct PhoneNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = malloc(sizeof(struct PhoneNode));
        current->next->phone = phone;
        current->next->next = NULL;
    }
}

void free_list(struct PhoneNode *head)
{
    struct PhoneNode *current = head;
    while (current != NULL)
    {
        struct PhoneNode *next = current->next;
        free(current);
        current = next;
    }
}

void print_list(struct PhoneNode *head)
{
    struct PhoneNode *temp = head;

    while(temp != NULL)
    {
        print_phone(temp->phone);
        temp = temp->next;
    }
}

void print_phone(struct Phone phone)
{
    printf("-----------------------------------------------------------------\n");
    printf("|  Iphone Model: %s\n", phone.phone_model);
    printf("|----------------------------------------------------------------\n");
    printf("|  Starting Price ($): %u\n", phone.starting_price);
    printf("|----------------------------------------------------------------\n");
    printf("|  Production year: %u\n", phone.production_year);
    printf("|----------------------------------------------------------------\n");
    printf("|  Sale/first year: %lu\n", phone.sale_first_year);
    printf("|----------------------------------------------------------------\n");
    printf("|  Sales/whole time: %lu\n", phone.sales_whole_time);
    printf("|----------------------------------------------------------------\n");
    printf("|  bill of materials: %u\n", phone.bill_of_materials);
    printf("|----------------------------------------------------------------\n");
    printf("|  Price(infl): %hu\n", phone.price_inflation);
    printf("|----------------------------------------------------------------\n");
    printf("|  bill of materials(infl): %hu\n", phone.bill_of_materials_inflation);
    printf("-----------------------------------------------------------------\n");
    printf("\n");
}