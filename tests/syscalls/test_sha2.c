#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

#include <setjmp.h>
#include <cmocka.h>

#include "nist_cavp.h"
#include "utils.h"

#include "cx.h"
#include "cx_hash.h"
#include "emulate.h"

void test_sha256_short_msg(void **state __attribute__((unused))) {
  test_cavp_short_msg(TESTS_PATH "cavp/sha256_short_msg.data", CX_SHA256);
}

void test_sha256_short_msg_single(void **state __attribute__((unused))) {
  test_cavp_short_msg_with_single(TESTS_PATH "cavp/sha256_short_msg.data",
                                  sys_cx_hash_sha256, 32);
}

void test_sha256_long_msg(void **state __attribute__((unused))) {
  test_cavp_long_msg(TESTS_PATH "cavp/sha256_long_msg.data", CX_SHA256);
}

void test_sha256_monte(void **state __attribute__((unused))) {
  uint8_t initial_seed[] = {0x6d, 0x1e, 0x72, 0xad, 0x03, 0xdd, 0xeb, 0x5d,
                            0xe8, 0x91, 0xe5, 0x72, 0xe2, 0x39, 0x6f, 0x8d,
                            0xa0, 0x15, 0xd8, 0x99, 0xef, 0x0e, 0x79, 0x50,
                            0x31, 0x52, 0xd6, 0x01, 0x0a, 0x3f, 0xe6, 0x91};
  const uint8_t expected_seed[] = {
      0x6a, 0x91, 0x2b, 0xa4, 0x18, 0x83, 0x91, 0xa7, 0x8e, 0x6f, 0x13,
      0xd8, 0x8e, 0xd2, 0xd1, 0x4e, 0x13, 0xaf, 0xce, 0x9d, 0xb6, 0xf7,
      0xdc, 0xbf, 0x4a, 0x48, 0xc2, 0x4f, 0x3d, 0xb0, 0x27, 0x78};

  test_cavp_monte(CX_SHA256, initial_seed, expected_seed);
}

void test_sha224_short_msg(void **state __attribute__((unused))) {
  test_cavp_short_msg(TESTS_PATH "cavp/sha224_short_msg.data", CX_SHA224);
}

void test_sha224_long_msg(void **state __attribute__((unused))) {
  test_cavp_long_msg(TESTS_PATH "cavp/sha224_long_msg.data", CX_SHA224);
}

void test_sha224_monte(void **state __attribute__((unused))) {
  uint8_t initial_seed[] = {0xed, 0x2b, 0x70, 0xd5, 0x75, 0xd9, 0xd0,
                            0xb4, 0x19, 0x6a, 0xe8, 0x4a, 0x03, 0xee,
                            0xd9, 0x40, 0x05, 0x7e, 0xa8, 0x9c, 0xdd,
                            0x72, 0x9b, 0x95, 0xb7, 0xd4, 0xe6, 0xa5};

  const uint8_t expected_seed[] = {0x27, 0x03, 0x3d, 0x2d, 0x89, 0x32, 0x9b,
                                   0xa9, 0xd2, 0xa3, 0x9c, 0x02, 0x92, 0x55,
                                   0x2a, 0x5f, 0x1f, 0x94, 0x5c, 0x11, 0x5d,
                                   0x5a, 0xbf, 0x20, 0x64, 0xe9, 0x37, 0x54};
  test_cavp_monte(CX_SHA224, initial_seed, expected_seed);
}

void test_sha384_short_msg(void **state __attribute__((unused))) {
  test_cavp_short_msg(TESTS_PATH "cavp/sha384_short_msg.data", CX_SHA384);
}

void test_sha384_long_msg(void **state __attribute__((unused))) {
  test_cavp_long_msg(TESTS_PATH "cavp/sha384_long_msg.data", CX_SHA384);
}

void test_sha384_monte(void **state __attribute__((unused))) {
  uint8_t initial_seed[] = {
      0xed, 0xff, 0x07, 0x25, 0x5c, 0x71, 0xb5, 0x4a, 0x9b, 0xea, 0xe5, 0x2c,
      0xdf, 0xa0, 0x83, 0x56, 0x9a, 0x08, 0xbe, 0x89, 0x94, 0x9c, 0xbb, 0xa7,
      0x3d, 0xdc, 0x8a, 0xcf, 0x42, 0x93, 0x59, 0xca, 0x5e, 0x5b, 0xe7, 0xa6,
      0x73, 0x63, 0x3c, 0xa0, 0xd9, 0x70, 0x98, 0x48, 0xf5, 0x22, 0xa9, 0xdf
  };

  const uint8_t expected_seed[] = {
      0xcc, 0xde, 0x43, 0x59, 0xf2, 0x3e, 0x64, 0x57, 0x9c, 0x5c, 0x03, 0x80,
      0xdf, 0x83, 0x7e, 0xe9, 0x50, 0x92, 0x8a, 0xa8, 0x29, 0x37, 0xa2, 0xd2,
      0xed, 0x33, 0xd2, 0x16, 0xe7, 0x07, 0xc4, 0x6d, 0x84, 0x7e, 0xfa, 0x5c,
      0xa5, 0x2d, 0xcb, 0xda, 0x55, 0x11, 0x45, 0xe1, 0x64, 0xfb, 0xd5, 0x94
  };
  test_cavp_monte(CX_SHA384, initial_seed, expected_seed);
}

void test_sha512_short_msg(void **state __attribute__((unused))) {
  test_cavp_short_msg(TESTS_PATH "cavp/sha512_short_msg.data", CX_SHA512);
}

void test_sha512_short_msg_single(void **state __attribute__((unused))) {
  test_cavp_short_msg_with_single(TESTS_PATH "cavp/sha512_short_msg.data",
                                  sys_cx_hash_sha512, 64);
}

void test_sha512_long_msg(void **state __attribute__((unused))) {
  test_cavp_long_msg(TESTS_PATH "cavp/sha512_long_msg.data", CX_SHA512);
}

void test_sha512_monte(void **state __attribute__((unused))) {
  uint8_t initial_seed[] = {
      0x5c, 0x33, 0x7d, 0xe5, 0xca, 0xf3, 0x5d, 0x18, 0xed, 0x90, 0xb5,
      0xcd, 0xdf, 0xce, 0x00, 0x1c, 0xa1, 0xb8, 0xee, 0x86, 0x02, 0xf3,
      0x67, 0xe7, 0xc2, 0x4c, 0xcc, 0xa6, 0xf8, 0x93, 0x80, 0x2f, 0xb1,
      0xac, 0xa7, 0xa3, 0xda, 0xe3, 0x2d, 0xcd, 0x60, 0x80, 0x0a, 0x59,
      0x95, 0x9b, 0xc5, 0x40, 0xd6, 0x32, 0x37, 0x87, 0x6b, 0x79, 0x92,
      0x29, 0xae, 0x71, 0xa2, 0x52, 0x6f, 0xbc, 0x52, 0xcd};

  const uint8_t expected_seed[] = {
      0x4a, 0xa7, 0xda, 0xd7, 0x4e, 0xb5, 0x1d, 0x09, 0xa6, 0xae, 0x77,
      0x35, 0xc4, 0xb7, 0x95, 0xb0, 0x78, 0xf5, 0x1c, 0x31, 0x4f, 0x14,
      0xf4, 0x2a, 0x0d, 0x63, 0x07, 0x1e, 0x13, 0xbd, 0xc5, 0xfd, 0x9f,
      0x51, 0x61, 0x2e, 0x77, 0xb3, 0x6d, 0x44, 0x56, 0x75, 0x02, 0xa3,
      0xb5, 0xeb, 0x66, 0xc6, 0x09, 0xec, 0x01, 0x7e, 0x51, 0xd8, 0xdf,
      0x93, 0xe5, 0x8d, 0x1a, 0x44, 0xf3, 0xc1, 0xe3, 0x75};
  test_cavp_monte(CX_SHA512, initial_seed, expected_seed);
}

int main(void) {
  const struct CMUnitTest tests[] = {cmocka_unit_test(test_sha224_short_msg),
                                     cmocka_unit_test(test_sha224_long_msg),
                                     cmocka_unit_test(test_sha224_monte),
                                     cmocka_unit_test(test_sha256_short_msg),
                                     cmocka_unit_test(test_sha256_short_msg_single),
                                     cmocka_unit_test(test_sha256_long_msg),
                                     cmocka_unit_test(test_sha256_monte),
                                     cmocka_unit_test(test_sha384_short_msg),
                                     cmocka_unit_test(test_sha384_long_msg),
                                     cmocka_unit_test(test_sha384_monte),
                                     cmocka_unit_test(test_sha512_short_msg),
                                     cmocka_unit_test(test_sha512_short_msg_single),
                                     cmocka_unit_test(test_sha512_long_msg),
                                     cmocka_unit_test(test_sha512_monte)};
  return cmocka_run_group_tests(tests, NULL, NULL);
}
