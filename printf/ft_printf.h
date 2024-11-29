/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:59:55 by kricci-d          #+#    #+#             */
/*   Updated: 2024/11/29 14:56:15 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_print_int(char spec, va_list arg, int *len);
void	ft_print_char(char spec, va_list arg, int *len);
void	ft_print_hex(char spec, va_list arg, int *len);
void	ft_print_ptr(va_list arg, int *len);

#endif
