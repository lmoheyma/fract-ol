/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:05:30 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 16:29:43 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char[4]){b, g, r});
}
