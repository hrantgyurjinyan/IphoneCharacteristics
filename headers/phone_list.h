#ifndef PHONE_LIST_H
#define PHONE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Represents information about a phone.
 */
struct Phone
{
    char phone_model[50]; /**< The model name of the phone. */
    uint16_t starting_price; /**< The initial price of the phone. */
    uint16_t production_year; /**< The year the phone was produced. */
    uint64_t sale_first_year; /**< The total sales in the first year. */
    uint64_t sales_whole_time; /**< The total sales over the entire period. */
    uint16_t bill_of_materials; /**< The cost of the phone's bill of materials. */
    uint16_t price_inflation; /**< The inflation rate applied to the phone's price. */
    uint16_t bill_of_materials_inflation; /**< The inflation rate applied to the bill of materials. */
};

/**
 * @brief Represents a node in the phone list.
 */
struct PhoneNode
{
    struct Phone phone; /**< The phone information stored in the node. */
    struct PhoneNode *next; /**< Pointer to the next node in the list. */
};

/**
 * @brief Adds a phone to the linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param phone The phone to be added to the list.
 */
void add_phone(struct PhoneNode **head, struct Phone phone);

/**
 * @brief Frees the memory occupied by the entire linked list.
 *
 * @param head The head of the linked list.
 */
void free_list(struct PhoneNode *head);

/**
 * @brief Prints information about a phone.
 *
 * @param phone The phone to be printed.
 */
void print_phone(struct Phone phone);

/**
 * @brief Prints the entire linked list of phones.
 *
 * @param head The head of the linked list.
 */
void print_list(struct PhoneNode *head);

#endif // PHONE_LIST_H
