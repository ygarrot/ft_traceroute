/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/02 12:01:35 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "../libft/includes/libft.h"

# include <stdio.h>
# include <netdb.h>
# include <sys/socket.h>
# include <sys/types.h>

# include <sys/uio.h>

# include <signal.h>

# include <unistd.h>

# include <sys/mman.h>

# include <sys/time.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>

# define PING_BAD_COUNT "ping: bad number of packets to transmit."
# define SOCKET_ERROR "socket error"
# define BUFF_S 1500
# define PACKET_SIZE_DEFAULT 64
# define DEFAULT_TIMEOUT 1
# define DEFAULT_DELAY 1.0
# define TTL_DEFAULT 64
# define ERROR_CODE -1
# define PORT_TMP 12
# define OPT_STR "cdinqsStTvwWh"

# define PAYLOAD_SIZE 32
# define SENT_PACKET_SIZE (sizeof(struct ip) + sizeof(struct icmphdr) + PAYLOAD_SIZE)
/* # define FT_PACKET_SIZE sizeof(struct ip) + sizeof(struct icmphdr) */

enum {
	COUNT = (1 << 0),
	DEBUG = (1 << 1),
	INTERVALE = (1 << 2),
	NUMERIC = (1 << 3),
	QUIET = (1 << 4),
	PACKET_SIZE = (1 << 5),
	SNDBUFF = (1 << 6),
	TTL = (1 << 7),
	TIMESTAMP = (1 << 8),
	VERBOSE = (1 << 9),
	DEADLINE = (1 << 10),
	TIMEOUT = (1 << 11),
	HELP = (1 << 12)
};

typedef struct timeval		t_timeval;
typedef struct timezone		t_timezone;
typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr6	t_sockaddr6;
typedef struct sockaddr_in6	t_sockaddr_in6;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct protoent		t_protoent;
typedef struct ip			t_ip;
typedef struct tcphdr		t_tcphdr;
typedef struct icmphdr		t_icmphdr;
typedef struct hostent		t_hostent;
typedef struct addrinfo		t_addrinfo;
int				ip_version(const char *src);

typedef struct	s_packet_stat
{
	int		size;
	int		send;
	int		rcv;
	int		count;
	int		count_max;
	int		sndbuff;
}				t_packet_stat;

typedef struct	s_time_stat
{
	t_timeval			start;
	t_timeval			current;
	long double			intervale;
	long double			delay;
	long double			min;
	long double			avg;
	long double			max;
	long double			mdev;
	int					ttl;
	long double			all;
	int					count;
	int					deadline;
	int					timeout;
}				t_time_stat;

typedef struct	s_ping
{
	t_sockaddr		*sockaddr;
	t_addrinfo		*host_entity;
	t_packet_stat	pstat;
	t_time_stat		tstat;
	int32_t des;
	char		packet[SENT_PACKET_SIZE];
	char			*opt_tab[HELP + 1];
	int				opt;
	char			host_addr[100];
	char			dns_addr[NI_MAXHOST];
	char			*host_name;
	int				socket;
	int				sockaddr_len;
	int				port;

	int queries;
	int ttl;
}				t_ping;

# define __unused				__attribute__((unused))
# define __noreturn				__attribute__((noreturn))
# define __warn_unused_result	__attribute__((warn_unused_result))

/* uint16_t		in_cksum(__unused const void *buffer, __unused size_t size); */
unsigned short		checksum(void *b, int len);
unsigned short in_cksum(unsigned short *addr, int len);
double			timeval_to_double(t_timeval last_time, t_timeval current_time);
double			intervale(void);

void			stop_loop(int signal);
void			ping_ctor(t_ping *ping);
void			ping_dtor(t_ping *ping);
void			func_tab(t_ping *ping);
void			set_intervale(t_ping *ping, char *value);
void			set_timeout(t_ping *ping, char *value);
void			set_deadline(t_ping *ping, char *value);
void			set_packetsize(t_ping *ping, char *value);
void			set_countmax(t_ping *ping, char *value);
void			set_sndbuff(t_ping *ping, char *value);
void			set_ttl(t_ping *ping, char *value);
void			display_help(t_ping *ping, char *value);

int				set_time_stat(t_ping *ping);
int				print_ping(t_ping *ping);
int				print_stat(t_ping *ping);
int				ping_send(int socket, t_ping *ping);
int				set_packet(t_ping *ping);
int				set_socket(int is_ipv4);
int				ping_receive(int sockfd, t_ping *ping);
int				ping_loop(t_ping *ping);
int				check_addr(t_ping *ping);
int				wait_for (double sec);
int				print_summary(t_ping *ping);
int				reverse_dns_lookup(t_ping *ping);


extern t_ping *g_ping;
#endif
