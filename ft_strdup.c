/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsisman <hsisman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:30:03 by hsisman           #+#    #+#             */
/*   Updated: 2022/08/18 00:30:52 by hsisman          ###   ########.tr       */
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
