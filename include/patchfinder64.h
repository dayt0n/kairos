#pragma once
#ifndef PATCHFINDER64_H_
#define PATCHFINDER64_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int init_kernel(uint64_t base, const char *filename);
void term_kernel(void);

enum { SearchInCore, SearchInPrelink, SearchInPPL };

typedef uint64_t addr_t;

uint64_t find_register_value(uint64_t where, int reg);
uint64_t find_reference(uint64_t to, int n, int prelink);
uint64_t find_strref(const char *string, int n, int prelink);
uint64_t find_gPhysBase(void);
uint64_t find_ptov_table(void);
uint64_t find_kernel_pmap(void);
uint64_t find_amfiret(void);
uint64_t find_ret_0(void);
uint64_t find_amfi_memcmpstub(void);
uint64_t find_sbops(void);
uint64_t find_lwvm_mapio_patch(void);
uint64_t find_lwvm_mapio_newj(void);

uint64_t find_entry(void);
const unsigned char *find_mh(void);

uint64_t find_cpacr_write(void);
uint64_t find_str(const char *string);
uint64_t find_amfiops(void);
uint64_t find_sysbootnonce(void);
uint64_t find_trustcache(void);
uint64_t find_amficache(void);
uint64_t find_allproc(void);
uint64_t find_cache(int dynamic);

uint64_t find_add_x0_x0_0x40_ret(void);
uint64_t find_vnode_lookup(void);
uint64_t find_vnode_put(void);
uint64_t find_vfs_context_current(void);
uint64_t find_rootvnode(void);
uint64_t find_zone_map_ref(void);

uint64_t find_pmap_initialize_legacy_static_trust_cache_ppl(void);
uint64_t find_trust_cache_ppl(void);

// removed static declarations of these functions for use elsewhere
unsigned char* boyermoore_horspool_memmem(const unsigned char* haystack, size_t hlen, const unsigned char* needle,   size_t nlen);
addr_t step64(const uint8_t *buf, addr_t start, size_t length, uint32_t what, uint32_t mask);
addr_t step64_back(const uint8_t *buf, addr_t start, size_t length, uint32_t what, uint32_t mask);
addr_t bof64(const uint8_t *buf, addr_t start, addr_t where);
addr_t xref64(const uint8_t *buf, addr_t start, addr_t end, addr_t what);
addr_t calc64(const uint8_t *buf, addr_t start, addr_t end, int which);
addr_t calc64mov(const uint8_t *buf, addr_t start, addr_t end, int which);
addr_t find_call64(const uint8_t *buf, addr_t start, size_t length);
addr_t follow_call64(const uint8_t *buf, addr_t call);
addr_t follow_cbz(const uint8_t *buf, addr_t cbz);
addr_t xref64code(const uint8_t *buf, addr_t start, addr_t end, addr_t what);

#endif
