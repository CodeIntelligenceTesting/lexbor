#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <lexbor/encoding/encoding.h>

FUZZ_TEST_SETUP() {
    // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {
    lxb_status_t status;
    const lxb_char_t *start, *end;
    const lxb_encoding_data_t *encoding;

    lxb_codepoint_t cp[32];
    lxb_encoding_decode_t decode = {0};
    lxb_encoding_t encoding_type = (lxb_encoding_t) (data[0] % 0x2b);

    encoding = lxb_encoding_data(encoding_type);

    status  = lxb_encoding_decode_init(&decode, encoding, cp, sizeof(cp) / sizeof(lxb_codepoint_t));

    start = (lxb_char_t *) data;
    end = start + size;

    encoding->decode(&decode, &start, end);
}