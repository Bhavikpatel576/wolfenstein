/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:46:01 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/25 17:12:07 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	void			c_to_b_r(unsigned char byte, char *byte_represent)
{
	int					decimal_byte;
	int					highest_bit;
	int					current_bit;
	int					i;

	decimal_byte = byte;
	highest_bit = 128;
	current_bit = highest_bit;
	i = 0;
	while (current_bit > 0)
	{
		if (decimal_byte >= current_bit)
		{
			byte_represent[i] = '1';
			decimal_byte -= current_bit;
		}
		else
			byte_represent[i] = '0';
		current_bit /= 2;
		i++;
	}
}

static	unsigned char	convert_to_char_represent(char *byte_represent)
{
	unsigned char		decimal_byte;
	int					highest_bit;
	int					current_bit;
	int					i;

	decimal_byte = 0;
	highest_bit = 128;
	current_bit = highest_bit;
	i = 0;
	while (i < 8)
	{
		if (byte_represent[i] == '1')
			decimal_byte += current_bit;
		current_bit /= 2;
		i++;
	}
	return (decimal_byte);
}

static	void			flip_byte(char *byte_represent)
{
	int					i;

	i = 0;
	while (i < 8)
	{
		if (byte_represent[i] == '0')
			byte_represent[i] = '1';
		else
			byte_represent[i] = '0';
		i++;
	}
}

unsigned char			ft_reverse_bits(unsigned char byte)
{
	char				byte_represent[9];

	c_to_b_r(byte, byte_represent);
	flip_byte(byte_represent);
	return (convert_to_char_represent(byte_represent));
}
