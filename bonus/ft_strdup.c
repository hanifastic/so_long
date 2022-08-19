/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:41:00 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/17 00:43:25 by hsisman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*src)
	{
		str[i] = *src;
		src++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
