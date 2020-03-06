/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:21:15 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/06 23:29:29 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

void	ft_ptr_check(void *ptr, char *msg, ...)
{
	va_list	ap;
	void	*tmp;

	if (ptr)
		return ;
	ft_putendl_fd(msg, 2);
	ft_memdel(&ptr);
	va_start(ap, msg);
	while (1)
	{
		tmp = va_arg(ap, void *);
		if (!tmp)
			break ;
		ft_memdel(&tmp);
	}
	va_end(ap);
	exit(ENOMEM);
}
