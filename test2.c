#include <stdio.h>
#include <errno.h> 
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/ip.h> 
#include <netinet/ip_icmp.h> 

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

int main(){ 

	int sock, optval,test; 
	int i;
	char *packet, *buffer; 

	struct ip *hip; 
	struct icmp * hicmp;

	struct sockaddr_in peer;
	struct sockaddr_in mine;

	packet  = (char *) malloc(sizeof(struct ip) + sizeof(struct icmp) 
			); 
	buffer  = (char *) malloc(sizeof(struct ip) + sizeof(struct icmp) 
			); 

	hip = (struct ip *) packet; 
	hicmp = (struct icmp *) (packet + sizeof(struct ip)); 

	peer.sin_family = AF_INET; 
	peer.sin_addr.s_addr = inet_addr("19.54.154.14"); 

	mine.sin_family=AF_INET;
	mine.sin_addr.s_addr = inet_addr(GetMyIp());
	hip->ip_hl   = 5; 
	hip->ip_v = 4; 
	hip->ip_tos   = 0; 
	hip->ip_len = sizeof(struct ip) + sizeof(struct icmp); 
	hip->ip_id      = htons(getuid()); 
	hip->ip_ttl      = 255;
	hip->ip_src    = peer.sin_addr;
	hip->ip_dst    = mine.sin_addr;

	printf("len : %d\n",hip->ip_len);

	sock = socket(AF_INET,SOCK_RAW,IPPROTO_ICMP); 
	setsockopt(sock,IPPROTO_IP,IP_HDRINCL,&optval,sizeof(int)); 

	hicmp->icmp_type = ICMP_ECHO; 
	hicmp->icmp_code = 0; 
	hicmp->icmp_cksum = 0; 

	hicmp->icmp_cksum = in_cksum((unsigned short *)hicmp,sizeof(struct icmp) 
			); 

	hip->ip_sum    = in_cksum((unsigned short *)hip, sizeof(struct ip)); 

	for ( i=0; i < hip->ip_len;i++)
		printf("%.2X ",*(packet+i));

	test=sendto(sock,packet,hip->ip_len,0,(struct sockaddr *)&peer,sizeof(struct  sockaddr));
	if (test != hip->ip_len)
		printf("A envoyé %d octets au lieu de %d octects
				\n",test,hip->ip_len); 
			if (test <= 0)
				perror("Erreur sendto()");

	test= recvfrom(sock,buffer,sizeof(struct ip)+sizeof(struct icmp),0,(struct sockaddr *)&peer,sizeof(struct  sockaddr)); 
	if (test == (sizeof(struct ip)+sizeof(struct icmp)))    
		printf("Received the ECHO REPLY\n"); 

	for (i = 0; i <=  (sizeof(struct ip)+sizeof(struct icmp));i++)
		printf("%.2X ",*(packet+i));
	printf("\n");

	close(sock);
	free(packet);
	free(buffer);
	return 0;
}
