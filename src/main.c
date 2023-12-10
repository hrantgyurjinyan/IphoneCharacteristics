#include "csv_reader.h"
#include "phone_list.h"
#include "calc_algorithms.h"

int main(int argc, char** argv) 
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) 
    {
        printf("CSV Filename not given\n");
        exit(1);
    }
    if (argv[1] == NULL) 
    {
        printf("Wrong filename\n");
        exit(1);
    }

    // Initialize the linked list to store phone information
    struct PhoneNode *head = NULL;

    // Read phone information from the CSV file and populate the linked list
    read_phone_list(&head, argv[1]);

    int operation;

    printf("Hi! This program calculates 1 of the 4 options you choose for iPhone phones and their characteristics\n\n");
    printf("1. Most profitable iPhones of the whole time in increasing order\n");
    printf("2. Most profitable iPhones of the first year sales in increasing order\n");
    printf("3. Most money spent on iPhones in increasing order (cheapest for bill)\n");
    printf("4. Most sold iPhone of the whole time in increasing order\n");
    printf("Choose from 1 to 4\n");

    // Get the user's choice for the calculation operation
    int retVal = scanf("%d", &operation);
    if (retVal != 1) 
    {
        printf("Invalid input\n");
        exit(1);
    }
    if (operation < 1 || operation > 4) 
    {
        printf("Invalid choice\n");
        exit(1);
    }

    // Perform the selected calculation operation using merge sort
    switch (operation) 
    {
        case 1:
            mergeSort(&head, most_profitable_of_whole);
            
            printf("*********************************************************************\n");
            printf("*   Most profitable iPhones of the whole time in increasing order   *\n");
            printf("*********************************************************************\n");

            break;

        case 2:
            mergeSort(&head, most_profitable_of_first_year);

            printf("***************************************************************************\n");
            printf("*   Most profitable iPhones of the first year sales in increasing order   *\n");
            printf("***************************************************************************\n");

            break;

        case 3:
            mergeSort(&head, most_money_spent);
            
            printf("***************************************************************************\n");
            printf("*   Most money spent on iPhones in decreasing order (cheapest for bill)   *\n");
            printf("***************************************************************************\n");

            break;

        case 4:
            mergeSort(&head, most_sold_of_whole_time);
            
            printf("**************************************************************\n");
            printf("*   Most sold iPhone of the whole time in increasing order   *\n");
            printf("**************************************************************\n");

            break;
    }

    // Print the sorted list based on the chosen calculation operation
    print_list(head);

    // Free the memory occupied by the linked list
    free_list(head);

    return 0;
}
