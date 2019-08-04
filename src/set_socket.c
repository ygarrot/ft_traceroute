/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:21:09 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/02 11:59:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		set_socket(int is_ipv4)
{
	int			sock;
	int			t;

	(void)is_ipv4;
	t = 1;
	if ((sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP)) == ERROR_CODE)
		ft_exit(SOCKET_ERROR, EXIT_FAILURE);
	if (setsockopt (sock, IPPROTO_IP, IP_HDRINCL, &t, sizeof (t)) == ERROR_CODE)
		printf ("Cannot set HDRINCL!\n");
	return (sock);
}

int		create_socket(t_ping *ping, int is_ipv4)
{
	int				sock;

	sock = set_socket(is_ipv4);
	ping->sockaddr = ping->host_entity->ai_addr;
	ping->sockaddr_len = ping->host_entity->ai_addrlen;
	if (sock == ERROR_CODE)
		ft_printf("socket failed\n");
	return (sock);
}

/*
**	struct addrinfo {
**        int              ai_flags;
**        int              ai_family;
**        int              ai_socktype;
**        int              ai_protocol;
**        socklen_t        ai_addrlen;
**        struct sockaddr *ai_addr;
**        char            *ai_canonname;
**        struct addrinfo *ai_next;
**     };
*/

int		check_addr(t_ping *ping)
{
	int		is_ipv4;
	t_addrinfo	tmp = (t_addrinfo){
		.ai_family = AF_INET,
		.ai_socktype = SOCK_RAW,
		.ai_flags = AI_CANONNAME,
	};

	if (getaddrinfo(ping->host_name, NULL,
				&tmp, &ping->host_entity) != 0)
	{
		printf("ping: Name or Service not known\n");
		return (ERROR_CODE);
	}
	is_ipv4 = ping->host_entity->ai_family == AF_INET;
	ping->host_addr = inet_ntoa(((t_sockaddr_in*)ping->host_entity->ai_addr)->sin_addr);
	ping->des = ((t_sockaddr_in*)ping->host_entity->ai_addr)->sin_addr.s_addr;
	return (create_socket(ping, is_ipv4));
}
