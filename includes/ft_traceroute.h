/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:15:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/05 11:19:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include "../libft/includes/libft.h"

# include <stdio.h>
# include <netdb.h>
# include <arpa/inet.h>

# include <netinet/ip.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>

# include <sys/uio.h>
# include <sys/socket.h>
# include <sys/mman.h>
# include <sys/time.h>

# define PING_BAD_COUNT "ping: bad number of packets to transmit."
# define SOCKET_ERROR "socket error"
# define DEFAULT_TIMEOUT 3
# define TTL_DEFAULT 64
# define ERROR_CODE -1
# define PORT_TMP 12
# define OPT_STR "fmqtw?"

# define RECV_PACKET_SIZE (sizeof(struct ip) * 2 + sizeof(struct icmphdr) * 2)
# define SENT_PACKET_SIZE (sizeof(struct ip) + sizeof(struct icmphdr))
# define MAX_TTL 30
# define MAX_TRIES 3

enum {
	FIRS_TTL = (1 << 0),
	MAX_TTL_OPT = (1 << 1),
	MAX_TRIES_OPT = (1 << 2),
	TOS = (1 << 3),
	TIMEOUT = (1 << 4),
	HELP = (1 << 5)
};

typedef struct timeval		t_timeval;
typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct icmphdr		t_icmphdr;
typedef struct addrinfo		t_addrinfo;

typedef struct	s_route
{
	t_timeval	*tries;
	bool		*done;
	char		*addr;
}				t_route;

typedef struct	s_option
{
	int			first_ttl;
	int			ttl;
	int			max_ttl;

	int			tries;
	int			max_tries;

	int			tos;
	int			timeout;
	t_timeval	time;
}				t_option;

typedef struct	s_ping
{
	t_sockaddr	*sockaddr;
	t_addrinfo	*host_entity;
	t_route		*route;
	t_option	env;
	in_addr_t	des;

	char		packet[SENT_PACKET_SIZE];
	char		*opt_tab[HELP + 1];
	int			opt;
	char		*host_addr;
	char		dns_addr[NI_MAXHOST];
	char		*host_name;
	int			socket;
	int			sockaddr_len;
	int			port;
	int			last_ttl;
	bool		done;
	int			timedout;
}				t_ping;

int				print_foreach(t_ping *ping);
unsigned short	in_cksum(unsigned short *addr, int len);
double			timeval_to_double(t_timeval last_time);
double			intervale(void);

void			stop_loop(int signal);
void			ping_ctor(t_ping *ping);
void			ping_dtor(t_ping *ping);
void			func_tab(t_ping *ping);

/*
**   option
*/

void			set_ttl(t_ping *ping, char *value);
void			set_max_ttl(t_ping *ping, char *value);
void			set_max_tries(t_ping *ping, char *value);
void			set_tos(t_ping *ping, char *value);
void			set_timeout(t_ping *ping, char *value);
void			display_help(t_ping *ping, char *value);

int				print_ping(t_ping *ping);
int				print_stat(t_ping *ping);
int				ping_send(int socket, t_ping *ping);
int				set_packet(t_ping *ping);
int				set_socket(int is_ipv4);
int				ping_receive(int sockfd, t_ping *ping);
int				ping_loop(t_ping *ping);
int				check_addr(t_ping *ping);
int				print_summary(t_ping *ping);
int				reverse_dns_lookup(t_ping *ping);
void			free_routes(t_route *route, int ttl);

#endif
