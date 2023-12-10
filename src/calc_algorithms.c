#include "calc_algorithms.h"

size_t most_profitable_of_whole(struct Phone phone) 
{
    return phone.sales_whole_time * phone.price_inflation - phone.sales_whole_time * phone.bill_of_materials_inflation;
}


size_t most_profitable_of_first_year(struct Phone phone) 
{
    return phone.sale_first_year * phone.starting_price - phone.sale_first_year * phone.bill_of_materials;
}

size_t most_money_spent(struct Phone phone) 
{
    return phone.bill_of_materials_inflation * phone.sales_whole_time;
}
size_t most_sold_of_whole_time(struct Phone phone) 
{
    return phone.sales_whole_time;
}

// Function to merge two sorted linked lists
struct PhoneNode* merge(struct PhoneNode* left, struct PhoneNode* right, size_t (*func_ptr)(struct Phone)) 
{
    if (left == NULL) 
    {
        return right;
    }
    if (right == NULL) 
    {
        return left;
    }

    struct PhoneNode* result = NULL;
    if (func_ptr(left->phone) <= func_ptr(right->phone)) 
    {
        result = left;
        result->next = merge(left->next, right, func_ptr);
    } else 
    {
        result = right;
        result->next = merge(left, right->next, func_ptr);
    }

    return result;
}

// Function to perform merge sort on a linked list
void mergeSort(struct PhoneNode** headRef, size_t (*func_ptr)(struct Phone)) 
{
    struct PhoneNode* head = *headRef;
    struct PhoneNode* left;
    struct PhoneNode* right;

    // Base case: If the list is empty or has only one element, it is already sorted
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    // Split the list into two halves
    struct PhoneNode* slow = head;
    struct PhoneNode* fast = head->next;

    while (fast != NULL) 
    {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    left = head;
    right = slow->next;
    slow->next = NULL;

    // Recursively sort the two halves
    mergeSort(&left, func_ptr);
    mergeSort(&right, func_ptr);

    // Merge the sorted halves
    *headRef = merge(left, right, func_ptr);
}