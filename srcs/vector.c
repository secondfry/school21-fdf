/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <secondfry+school21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:11:58 by oadhesiv          #+#    #+#             */
/*   Updated: 2020/03/07 01:17:05 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



typedef struct	s_vector {
	float x;
	float y;
	float z;
	float w;
	struct s_vector	*(*new)(t_vertex *, ...);
}				t_vector;


