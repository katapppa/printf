/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:50:37 by fallard           #+#    #+#             */
/*   Updated: 2019/11/28 16:00:04 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !s)
		return (NULL);
	if (s > d)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		s = s + n;
		d = d + n;
		while (n--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	return (dest);
}
