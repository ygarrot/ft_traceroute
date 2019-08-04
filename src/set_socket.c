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
	{
		perror("socket");
		ft_exit(SOCKET_ERROR, EXIT_FAILURE);
	}
	if (setsockopt (sock, IPPROTO_IP, IP_HDRINCL, &t, sizeof (t)) == ERROR_CODE)
		printf ("Cannot set HDRINCL!\n");
	return (sock);
}

int		reverse_dns_lookup(t_ping *ping)
{
	char	service[1024] = { 0 };

	if (getnameinfo(ping->host_entity->ai_addr,
		ping->host_entity->ai_addrlen, ping->dns_addr, NI_MAXHOST,
				service, sizeof(service), NI_NAMEREQD))
	{
		printf("connect: Invalid argument\n");
		/* return (ERROR_CODE); */
	}
	return (1);
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
	void		*ptr;
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
	ptr = &((t_sockaddr_in*)ping->host_entity->ai_addr)->sin_addr;
	is_ipv4 = ping->host_entity->ai_family == AF_INET;
	inet_ntop(ping->host_entity->ai_family, ptr,
			ping->host_addr, 100);
	ping->des = ((t_sockaddr_in*)ping->host_entity->ai_addr)->sin_addr.s_addr;
	if (reverse_dns_lookup(ping) == ERROR_CODE)
	{
		ft_printf("reverse dns lookup\n");
		return (ERROR_CODE);
	}
	return (create_socket(ping, is_ipv4));
}
