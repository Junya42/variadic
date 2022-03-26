/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:29:43 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/26 03:17:26 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	*vSGcc(unsigned char	*str)
{	
	int	i;

	i = -1;
	while (--i)
		if (str[i - 1] == 0x0)
			return (str + i);
	return (0);
}

unsigned char	*vSClang(unsigned char	*str)
{	
	int	i;

	i = 0;
	while (str[i++])
		if (str[i] == 0x0)
			return (str + i + 1);
	return (0);
}

void	ft_putstr(unsigned char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print(int n, char *str, ...)
{ 
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (--n + 1)
	{
		ft_putstr(ptr);
		ptr = vSGcc(ptr);
		if (*(ptr + 1) == 0x0)
			ptr = vSGcc(ptr);
	}
}

int main(void)
{
	ft_print(4, "hello ", "world\n", " vString", " ", "fun!\n");
	return (0);
}
