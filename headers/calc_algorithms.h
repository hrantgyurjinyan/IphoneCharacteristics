#ifndef CALC_ALGORITHMS_H
#define CALC_ALGORITHMS_H

#include "phone_list.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculate the most profitable phone of the whole time based on a specific criterion.
 *
 * @param phone The phone to analyze.
 * @return The result of the calculation.
 */
size_t most_profitable_of_whole(struct Phone phone);

/**
 * @brief Calculate the most profitable phone of the first year based on a specific criterion.
 *
 * @param phone The phone to analyze.
 * @return The result of the calculation.
 */
size_t most_profitable_of_first_year(struct Phone phone);

/**
 * @brief Calculate the phone with the highest cost based on a specific criterion.
 *
 * @param phone The phone to analyze.
 * @return The result of the calculation.
 */
size_t most_money_spent(struct Phone phone);

/**
 * @brief Calculate the phone with the highest sales of the whole time based on a specific criterion.
 *
 * @param phone The phone to analyze.
 * @return The result of the calculation.
 */
size_t most_sold_of_whole_time(struct Phone phone);

/**
 * @brief Merge two linked lists based on a specific comparison function.
 *
 * @param left The left linked list.
 * @param right The right linked list.
 * @param func_ptr Pointer to the comparison function.
 * @return The merged linked list.
 */
struct PhoneNode* merge(struct PhoneNode* left, struct PhoneNode* right, size_t (*func_ptr)(struct Phone));

/**
 * @brief Perform merge sort on a linked list based on a specific comparison function.
 *
 * @param headRef Pointer to the head of the linked list.
 * @param func_ptr Pointer to the comparison function.
 */
void mergeSort(struct PhoneNode** headRef, size_t (*func_ptr)(struct Phone));

#endif // CALC_ALGORITHMS_H
