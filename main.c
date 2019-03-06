#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

int ft_printf(char *, ...);
char* convert (unsigned int, int);

int main()
{
	ft_printf("testingshit %d %p", 29, 26);
	return 0;
}

char *convert(unsigned int num, int base)
{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}while(num != 0);

	return(ptr);
}

char hex_digit(int v) {
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here
}

void print_address_hex(void* p0) {
    int i;
    uintptr_t p = (uintptr_t)p0;

	ft_putchar('0');
	ft_putchar('x');
	i = (sizeof(p) << 3);
	while (i > 0)
	{
		ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
//    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
//        ft_putchar(hex_digit((p >> i) & 0xf));
//    }
}

int ft_printf(char *format, ...)
{
	char *traverse;
	unsigned int i;
	char *s;

	va_list(arg);
	va_start(arg, format);

	traverse = format;
	while(*traverse != '\0')
	{
		while(*traverse != '%')
		{
			ft_putchar(*traverse);
			traverse++;
		}
	traverse++;

	if(*traverse == 'c')
	{
		i = va_arg(arg, int);
		ft_putchar(i);
	}
	else if(*traverse =='d')
	{
		i = va_arg(arg, int);
		if(i < 0)
		{
			i = -i;
			ft_putchar('-');
		}
		ft_putstr(convert(i, 10));
	}
	else if(*traverse == 's')
	{
		s = va_arg(arg, char *);
		ft_putstr(s);
	}
	else if(*traverse == 'p')
	{
		i = va_arg(arg, int);
		print_address_hex((void*) &i);
	}
	traverse++;
	}
	va_end(arg);
	return 0;
}
