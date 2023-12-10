#include "csv_reader.h"

int skip_line(int fd)
{
    char symbol = 'a';
    ssize_t read_bytes;

    while((read_bytes = read(fd, &symbol, 1)) > 0)
    {
        if (symbol == '\n')
        {
            break;
        }
    }

    if (read_bytes == -1)
    {
        perror("read");
        exit(1);
    }
    else if (read_bytes == 0)
    {
        return -1;
    }

    return 0;
}

int read_string(int fd, char *buf)
{
    char symbol = 'a';
    uint8_t i = 0;
    ssize_t read_bytes;

    while((read_bytes = read(fd, &symbol, 1)) > 0)
    {
        if (symbol == ',' || symbol == '\n' || i == 19)
        {
            break;
        }
        else if (symbol == '\r')
        {
            read_bytes = read(fd, &symbol, 1);
            break;
        }
        buf[i++] = symbol;
    }

    if (read_bytes == -1)
    {
        perror("read");
        exit(1);
    }
    else if (read_bytes == 0)
    {
        return -1;
    }

    return 0;
}

int read_number(int fd, uint64_t *number)
{
    char symbol = 'a';
    ssize_t read_bytes;

    while((read_bytes = read(fd, &symbol, 1)) > 0)
    {
        if (symbol == ',' || symbol == '\n')
        {
            break;
        }
        else if (symbol == '\r')
        {
            read_bytes = read(fd, &symbol, 1);
            break;
        }
        *number = *number * 10 + (symbol - '0');
    }

    if (read_bytes == -1)
    {
        perror("read");
        exit(1);
    }
    else if (read_bytes == 0)
    {
        return -1;
    }

    return 0;
}

void read_phone_list(struct PhoneNode **head, char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    skip_line(fd);

    struct Phone phone;

    for (;;)
    {
        phone = (struct Phone) {0};

        if (read_string(fd, phone.phone_model) == -1)
        {
            printf("read_string: phone_model\n");
            break;
        }
        if(read_number(fd, (uint64_t *) &phone.starting_price) == -1)
        {
            printf("read_number: starting_price\n");
            break;
        }
        if (read_number(fd, (uint64_t *) &phone.production_year) == -1)
        {
            printf("read_number: production_year\n");
            break;
        }
        if (read_number(fd, (uint64_t *) &phone.sale_first_year) == -1)
        {
            printf("read_number: sale_first_year\n");
            break;
        }
        if (read_number(fd, (uint64_t *) &phone.sales_whole_time) == -1)
        {
            printf("read_number: sales_whole_time\n");
            break;
        }
        if (read_number(fd, (uint64_t *) &phone.bill_of_materials) == -1)
        {
            printf("read_number: bill_of_materials\n");
            break;
        }
        if (read_number(fd, (uint64_t *) &phone.price_inflation) == -1)
        {
            printf("read_number: price_inflation\n");
            break;
        }
        if (read_number(fd, (uint64_t *) &phone.bill_of_materials_inflation) == -1)
        {
            printf("read_number: bill_of_materials_inflation\n");
            add_phone(head, phone);
            break;
        }

        add_phone(head, phone);
    }

    if (close(fd) == -1)
    {
        perror("close");
        exit(1);
    }

   // print_list(*head);
}