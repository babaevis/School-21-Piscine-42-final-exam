#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char *result;
	char *radix = "0123456789ABCDEF";
	int sign = 0;
	int i = 0;
	int k;
	if (value == 0)
		return 0;
	if (value == -2147483648)
		return "-2147483648";
	if (value < 0 && base != 10)
		value = -value;
	if (value < 0)
	{
		value = -value;
		sign += 1;
	}
	k = value;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	result = malloc(sizeof(char) * i + 1 + sign);
	if (sign > 0)
		result[0] = '-';
	i = i - 1 + sign;
	while (k > 0)
	{
		result[i] = radix[k % base];
		i--;
		k /= base;
	}
	return result;
}

