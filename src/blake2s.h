/*
   BLAKE2 reference source code package - optimized C implementations

   Written in 2012 by Samuel Neves <sneves@dei.uc.pt>

   To the extent possible under law, the author(s) have dedicated all copyright
   and related and neighboring rights to this software to the public domain
   worldwide. This software is distributed without any warranty.

   You should have received a copy of the CC0 Public Domain Dedication along with
   this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/
#pragma once
#ifndef __BLAKE2S_H__
#define __BLAKE2S_H__

#include <stddef.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#elif defined(_MSC_VER) && !defined(inline)
#define inline __inline
#endif

  enum blake2s_constant
  {
    BLAKE2S_BLOCKBYTES = 64,
    BLAKE2S_OUTBYTES   = 32,
    BLAKE2S_KEYBYTES   = 32,
    BLAKE2S_SALTBYTES  = 8,
    BLAKE2S_PERSONALBYTES = 8
  };

#pragma pack(push, 1)
  typedef struct __blake2s_param
  {
    uint8_t  digest_length; // 1
    uint8_t  key_length;    // 2
    uint8_t  fanout;        // 3
    uint8_t  depth;         // 4
    uint32_t leaf_length;   // 8
    uint8_t  node_offset[6];// 14
    uint8_t  node_depth;    // 15
    uint8_t  inner_length;  // 16
    // uint8_t  reserved[0];
    uint8_t  salt[BLAKE2S_SALTBYTES]; // 24
    uint8_t  personal[BLAKE2S_PERSONALBYTES];  // 32
  } blake2s_param;

  typedef struct __blake2s_state
  {
    uint32_t h[8];
    uint32_t t[2];
    uint32_t f[2];
    uint8_t  buf[2 * BLAKE2S_BLOCKBYTES];
    uint32_t buflen;
    uint8_t  outlen;
    uint8_t  last_node;
  } blake2s_state;

#pragma pack(pop)

  // Streaming API
  int blake2s_init( blake2s_state *S, size_t outlen );
  int blake2s_init_key( blake2s_state *S, size_t outlen, const void *key, size_t keylen );
  int blake2s_init_param( blake2s_state *S, const blake2s_param *P );
  int blake2s_update( blake2s_state *S, const uint8_t *in, size_t inlen );
  int blake2s_final( blake2s_state *S, uint8_t *out, size_t outlen );

  // Simple API
  int blake2s( uint8_t *out, const void *in, const void *key, size_t outlen, size_t inlen, size_t keylen );

#if defined(__cplusplus)
}
#endif

#endif
