/*
 * Copyright (c) 2018, Unisoc Communications Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _OS_ADAPTER_H_
#define _OS_ADAPTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <posix/pthread.h>
#include <posix/semaphore.h>
#include <posix/mqueue.h>

#include <misc/slist.h>

#include <logging/sys_log.h>

#include <net/net_if.h>
#include <net/wifi_mgmt.h>

/*
 * Copied from include/linux/...
 */

#undef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({				\
	void *__mptr = (void *)(ptr);					\
	((type *)(__mptr - offsetof(type, member))); })

#define malloc(size)		k_malloc(size)
#define free(ptr)		k_free(ptr)

#if !defined(CONFIG_NATIVE_POSIX_STDOUT_CONSOLE)
#define fflush(...) { ; }
#endif

#define wifimgr_slist_init(list)		sys_slist_init(list)
#define wifimgr_slist_peek_head(list)		sys_slist_peek_head(list)
#define wifimgr_slist_peek_next(node)		sys_slist_peek_next(node)
#define wifimgr_slist_prepend(list, node)	sys_slist_prepend(list, node)
#define wifimgr_slist_append(list, node)	sys_slist_append(list, node)
#define wifimgr_slist_remove_first(list)	sys_slist_get(list)
#define wifimgr_slist_remove(list, node)	sys_slist_find_and_remove(list, node)

typedef sys_snode_t wifimgr_snode_t;
typedef sys_slist_t wifimgr_slist_t;

/**
 * is_zero_ether_addr - Determine if give Ethernet address is all zeros.
 * @addr: Pointer to a six-byte array containing the Ethernet address
 *
 * Return true if the address is all zeroes.
 */
static inline bool is_zero_ether_addr(const char *addr)
{
	return (addr[0] | addr[1] | addr[2] | addr[3] | addr[4] | addr[5]) == 0;
}

#endif
