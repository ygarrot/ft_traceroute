/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:21:09 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/07 14:44:46 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int		set_socket(int is_ipv4)
{
	int			sock;

	(void)is_ipv4;
	/* if ((sock = socket(is_ipv4 ? AF_INET */
	/* 				: AF_INET6, SOCK_RAW, IPPROTO_ICMP)) < -1) */
	/* 	ft_exit(SOCKET_ERROR, EXIT_FAILURE); */
	if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < -1)
		ft_exit(SOCKET_ERROR, EXIT_FAILURE);
	return (sock);
}

int		reverse_dns_lookup(t_ping *ping)
{
	char	service[1024];

	ft_bzero(service, sizeof(service));
	if (getnameinfo(ping->host_entity->ai_addr,
				ping->host_entity->ai_addrlen, ping->dns_addr, NI_MAXHOST,
				service, sizeof(service), NI_NAMEREQD))
	{
		printf("connect: Invalid argument\n");
		return (ERROR_CODE);
	}
	return (1);
}

int		create_socket(t_ping *ping, int is_ipv4)
{
	int				sock;
	/* int				reuseaddr; */
	t_sockaddr_in6	sin2;
	t_sockaddr_in	sin;

	/* reuseaddr = 1; */
	ft_bzero(&sin2, sizeof(sin2));
	ft_bzero(&sin, sizeof(sin));
	sock = set_socket(is_ipv4);
	/* setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO */
			/* | ((ping->opt & DEBUG) * SO_DEBUG), &reuseaddr, sizeof(reuseaddr)); */
	ping->sockaddr = ping->host_entity->ai_addr;
	ping->sockaddr_len = ping->host_entity->ai_addrlen;
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
	t_addrinfo	tmp;
	void		*ptr;
	int			is_ipv4;

	ft_bzero(&tmp, sizeof(tmp));
	tmp.ai_family = PF_UNSPEC;
	tmp.ai_socktype = SOCK_RAW;
	tmp.ai_flags |= AI_CANONNAME;
	if (getaddrinfo(ping->host_name, NULL,
				&tmp, &ping->host_entity) != 0)
	{
		printf("ping: Name or Service not known\n");
		return (ERROR_CODE);
	}
	ptr = &((t_sockaddr_in*)ping->host_entity->ai_addr)->sin_addr;
	is_ipv4 = ping->host_entity->ai_family == PF_INET;
	inet_ntop(ping->host_entity->ai_family, ptr,
			ping->host_addr, 100);
	if (reverse_dns_lookup(ping) == ERROR_CODE)
		return (ERROR_CODE);
	return (create_socket(ping, is_ipv4));
}
