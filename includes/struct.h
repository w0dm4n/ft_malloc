/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:01:37 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/17 21:01:38 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum		e_zone_type
{
	TINY = 0,
	SMALL = 1,
	LARGE = 2
}					t_zone_type;

typedef struct		s_data
{
	void			*ptr;
	size_t			allocated_size;
	size_t			real_size;
	int				is_free;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

typedef struct		s_map
{
	struct s_map		*next;
	struct s_map		*prev;
	struct s_data		*data;
	enum e_zone_type	zone_type;
	void				*content;
	void				*content_data;
	void				*last_data;
}					t_map;

#endif
