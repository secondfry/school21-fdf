/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graceful.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 06:30:54 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/01 06:35:53 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graceful.h"

void	graceful(size_t reason, const char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(reason);
}
