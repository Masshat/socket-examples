
#include "packetErrorSendTo.h"

#ifndef PACKETERRORSENDTO_H
#define PACKETERRORSENDTO_H

#include <stdio.h>

static unsigned char rand;

ssize_t packetErrorSendTo(int sockfd, const void *buf, size_t len, int flags,
			const struct sockaddr *dest_addr, socklen_t addrlen)
{
	rand++;
	if (rand & 0x4 && rand & 0x2)  /* 1/4 error, burst of 2 */
		return len; /* drop packet, but indicate it was sent */
	else
		return sendto(sockfd, buf, len, flags, dest_addr, addrlen);
}

#endif /* PACKETERRORSENDTO_H */
