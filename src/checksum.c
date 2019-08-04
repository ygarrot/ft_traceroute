/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:48:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

unsigned short in_cksum(unsigned short *addr, int len) 
{ 
	register int sum = 0; 
	u_short answer = 0; 
	register u_short *w = addr; 
	register int nleft = len; 

	while (nleft > 1) 
	{ 
		sum += *w++; 
		nleft -= 2; 
	} 
	if (nleft == 1) 
	{ 
		*(u_char *) (&answer) = *(u_char *) w; 
		sum += answer; 
	} 
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	answer = ~sum;
	return (answer);
} 
