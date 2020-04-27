#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_printhex(unsigned char n)
{
    char *radix = "0123456789abcdef";
    ft_putchar(radix[n % 16]);
    ft_putchar(radix[n / 16]);
}

void ft_printchars(unsigned char n)
{
    if (n >= 32 && n <= 127)
        ft_putchar(n);
    else
        ft_putchar('.');
}

void print_memory(const void *addr, size_t size)
{
    size_t i = 0;
    size_t j = 0;
    unsigned char *p = (unsigned char *) addr;
    while (i < size)
    {
        j = 0;
        while (j < 16 && i + j < size)
        {
            ft_printhex(p[i + j]);
            if (j % 2)
                ft_putchar(32);
            j++;
        }
        while (j < 16)
        {
            write(1, "  ", 2);
            if (j % 2)
                ft_putchar(32);
            j++;
        }
        j = 0;
        while (j < 16 && i + j < size)
        {
            ft_printchars(p[i + j]);
            j++;
        }
        ft_putchar('\n');
        i += 16;
    }
}
