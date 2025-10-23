/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:49:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/12/23 21:49:08 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// Slight modified, if exceed INT_MIN or INT_MAX return 0
int	ft_atoi(char *str)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	result = result * sign;
	if (result < (long long int)INT_MIN || result > (long long int)INT_MAX)
		return (0);
	return (result);
}

/*
int main()
{
	printf("%d\n", ft_atoi("9"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi("4567"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("-9"));
	printf("%d\n", ft_atoi("-4567"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("9"));
	printf("%d\n", ft_atoi("-1302"));
	printf("%d\n", ft_atoi("-1302"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("101010"));
	printf("%d\n", ft_atoi("-5550"));
	printf("%d\n", ft_atoi("-1"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("1"));
	printf("%d\n", ft_atoi("+123a"));
	printf("%d\n", ft_atoi("      +666adsa"));
	
	printf("\n====================================\n");
	
	printf("%d\n", ft_atoi("a123"));
	printf("%d\n", ft_atoi("2147483648"));
	printf("%d\n", ft_atoi("-29999999999999"));
	printf("%d\n", ft_atoi("    ++-+-+hd2147483647dq06ab567 "));
	printf("%d\n", ft_atoi(" \n  \t---+--+1234ab567"));
	printf("%d\n", ft_atoi("-+-+"));
	printf("%d\n", ft_atoi(" -+-+jklfdsj"));
	printf("%d\n", ft_atoi(" -+-+jklfdsj@#$23"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("   -----1"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("--1325632167"));
	printf("%d\n", ft_atoi("- **678u4$"));
	printf("%d\n", ft_atoi("-+$$ 0$"));
}
*/