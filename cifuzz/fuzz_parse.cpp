#include <assert.h>
#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>
#include <lexbor/html/html.h>
//#include <../source/lexbor/html/interfaces/document.h>
#include <lexbor/url/url.h>

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {

    lxb_html_document_t *document;
    document = lxb_html_document_create();
    lxb_html_document_parse(document, data, size);
    lxb_html_document_destroy(document);

}
