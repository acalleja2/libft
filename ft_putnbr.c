/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:50:55 by acalleja          #+#    #+#             */
/*   Updated: 2017/11/12 22:48:27 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rec(int n)
{
	if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_rec(n / 10);
		n = n % 10;
		n = n + '0';
		write(1, &n, 1);
	}
}

void			ft_putnbr(int n)
{
	if (n >= 0)
	{
		ft_rec(n);
	}
	else
	{
		if (n == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			write(1, "-", 1);
			ft_rec(-n);
		}
	}
}
