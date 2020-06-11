/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graceful.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 06:12:20 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/06/06 21:46:12 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRACEFUL_H
# define GRACEFUL_H

# include <stdlib.h>
# include "libft.h"

# define ERR_OPEN "Provide map file argument, please. Can't open this one."
# define ERR_CLOSE "Close failed!"
# define ERR_MAP_INVALID "Provide valid map, please."

void	graceful(size_t reason, const char *msg);

#endif
