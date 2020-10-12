/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhori <mhori@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:04:09 by mhori             #+#    #+#             */
/*   Updated: 2020/07/02 13:19:16 by mhori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*t1;
	const char	*t2;

	t1 = s1;
	t2 = s2;
	if (!t1 && !t2)
		return (NULL);
	while (n--)
		*(t1++) = *(t2++);
	return (s1);
}