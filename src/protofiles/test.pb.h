/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.9.1 */

#ifndef PB_SRC_PROTOFILES_TEST_PB_H_INCLUDED
#define PB_SRC_PROTOFILES_TEST_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _TestMessage {
    int32_t test_number;
    int32_t test_number2;
    int32_t test_number3;
    pb_callback_t test_string;
} TestMessage;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define TestMessage_init_default                 {0, 0, 0, {{NULL}, NULL}}
#define TestMessage_init_zero                    {0, 0, 0, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define TestMessage_test_number_tag              1
#define TestMessage_test_number2_tag             2
#define TestMessage_test_number3_tag             3
#define TestMessage_test_string_tag              4

/* Struct field encoding specification for nanopb */
#define TestMessage_FIELDLIST(X, a) \
X(a, STATIC,   REQUIRED, INT32,    test_number,       1) \
X(a, STATIC,   REQUIRED, INT32,    test_number2,      2) \
X(a, STATIC,   REQUIRED, INT32,    test_number3,      3) \
X(a, CALLBACK, REQUIRED, STRING,   test_string,       4)
#define TestMessage_CALLBACK pb_default_field_callback
#define TestMessage_DEFAULT NULL

extern const pb_msgdesc_t TestMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define TestMessage_fields &TestMessage_msg

/* Maximum encoded size of messages (where known) */
/* TestMessage_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
