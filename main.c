#include "ascii_art.h"
#include <locale.h>

const char *chararr_hhf = "HIJ";
const char hhf_ascii[] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38,
    0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x38, 0x38,
    0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x0A, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38,
    0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20,
    0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20,
    0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20,
    0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38,
    0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20,
    0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38,
    0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x38, 0x38, 0x20, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38,
    0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x38, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x0A, 0x0
};

const char *chararr_fun = "ABCD";
const char fun_ascii[] = {
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C,
    0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x2E, 0x2E, 0x2E, 0x2E, 0x28, 0x5C, 0x5F, 0x2F, 0x29, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x5E, 0x40,
    0x20, 0x20, 0x20, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x2E, 0x2E, 0x2E, 0x28, 0x20, 0x27,
    0x5F, 0x27, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x5E, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x28, 0x5C, 0x5F, 0x2F, 0x29, 0x20, 0x3C, 0x7B, 0x52, 0x69, 0x62, 0x62, 0x69, 0x74, 0x7C, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x28, 0x6F, 0x29, 0x20, 0x28, 0x6F, 0x29, 0x20, 0x7C, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x2E, 0x2E, 0x2F, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x5C, 0x3D, 0x3D, 0x3D, 0x3D,
    0x3D, 0x3D, 0x7C, 0x7C, 0x20, 0x20, 0x7C, 0x20, 0x54, 0x52, 0x55, 0x43, 0x4B, 0x21, 0x21, 0x21, 0x21, 0x21, 0x21, 0x27,
    0x27, 0x7C, 0x27, 0x27, 0x27, 0x3B, 0x2E, 0x2E, 0x2C, 0x5F, 0x5F, 0x5F, 0x2E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2F, 0x2F, 0x20, 0x5C, 0x5C, 0x20, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x2E, 0x20, 0x20,
    0x20, 0x20, 0x7C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x2F, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27, 0x27,
    0x27, 0x27, 0x27, 0x27, 0x27, 0x5C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7C, 0x5F, 0x2E, 0x5F, 0x2E, 0x5F, 0x5F, 0x5F, 0x5F,
    0x5F, 0x5F, 0x3D, 0x3D, 0x3D, 0x7C, 0x3D, 0x20, 0x5F, 0x7C, 0x5F, 0x5F, 0x7C, 0x2E, 0x2C, 0x20, 0x5D, 0x20, 0x7C, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3C, 0x5C, 0x5C, 0x20, 0x2F, 0x2F, 0x3E, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x20,
    0x20, 0x5C, 0x5F, 0x2F, 0x20, 0x20, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x20, 0x5C, 0x5F, 0x40, 0x5F, 0x40, 0x5F, 0x40, 0x5F, 0x40, 0x5F,
    0x40, 0x5F, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x27, 0x28, 0x40, 0x20,
    0x29, 0x27, 0x28, 0x40, 0x20, 0x29, 0x27, 0x27, 0x27, 0x27, 0x2A, 0x7C, 0x28, 0x40, 0x29, 0x28, 0x40, 0x20, 0x29, 0x2A,
    0x2A, 0x2A, 0x2A, 0x2A, 0x28, 0x40, 0x29, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x4F, 0x20, 0x40, 0x20, 0x40,
    0x20, 0x4F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x5C, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x2F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0A, 0x0A, 0x0,
};

int main(int argc, char *argv[])
{
   AsciiArt *art3  = iAsciiArt.Create();
   AsciiArt *art4 = iAsciiArt.Create();

   printf("\n\n================PRINT Nancyj VERTICAL=================\n\n");
   iAsciiArt.Load(art3, "./Nancyj.art");
   iAsciiArt.render(art3, "EaABc", NULL);

   iAsciiArt.setFont(art4, FONTNAME_COLOSSAL);
   iAsciiArt.render(art4, "EaABc", NULL);

   iAsciiArt.map(art3, art4, "aAc", "1Xc");
   printf("\nMAPPING: a===>1    A===>X   c===>3 \n\n");

   printf("\nRendering 'EaABc'\n");
   iAsciiArt.render(art3, "EaABc", NULL); /* should render art3's "EaABc". */
   /*
     下面这句请在Terminal下运行
     iAsciiArt.render(art3, "EaABc", "8"); // should render art3's "EaABc".
   */


   /* Should render art3's E & B,and art4's 1,X & 3. */
   printf("\nRendering 'E1XB3'\n");
   iAsciiArt.mapRender(art3, art4, "EaABc", NULL);
   /*
    下面这句请在Terminal下运行
    iAsciiArt.mapRender(art3, art4, "EaABc", "14,12,8,4,9");
   */

   printf("\nRendering 'EaABc'\n");
   iAsciiArt.clearMap(art3);
   iAsciiArt.mapRender(art3, art4, "EaABc", NULL); /* should render art3's "EaABc". */

   iAsciiArt.setFont(art3, FONTNAME_COLOSSAL);
   iAsciiArt.render(art3, "XMbe23", NULL);

   iAsciiArt.setFont(art3, FONTNAME_UNIVERS);
   iAsciiArt.render(art3, "XMbe23", NULL);

   printf("\n\n================PRINT Beauty HORIZONTAL=================\n\n");
   iAsciiArt.Load(art3, "./beauty.art");
   iAsciiArt.render(art3, NULL, NULL);

   printf("\n\n================PRINT Beauty HORIZONTAL=================\n\n");
   iAsciiArt.Load(art3, "./beauty_vertical.art");
   iAsciiArt.render(art3, NULL, NULL);

   iAsciiArt.Load(art3, "./Blocks.art");
   iAsciiArt.render(art3, "HJ2W", NULL);

   iAsciiArt.setFont(art3, FONTNAME_BUBBLE);
   iAsciiArt.render(art3, "HJ2W@]", NULL);

   iAsciiArt.setFont(art3, FONTNAME_BLOCKS);
   iAsciiArt.render(art3, "H2W]", NULL);

   iAsciiArt.Load(art3, "./3D-ASCII.art");
   iAsciiArt.render(art3, "PJ2W]", NULL);
   /*
    下面这句请在Terminal下运行
    iAsciiArt.render(art3, "PJ2W]", "10, 12, 0, 12");
   */
   iAsciiArt.Load(art3, "./artist.art");
   iAsciiArt.render(art3, "BD", NULL);

   iAsciiArt.Load(art3, "./horse.art");
   iAsciiArt.render(art3, NULL, NULL);

   iAsciiArt.setFont(art3, FONTNAME_BUBBLE);
   iAsciiArt.render(art3, "XH2W(]", NULL);

   iAsciiArt.registFont(art3, 13, 35, 0, chararr_hhf, hhf_ascii);
   iAsciiArt.render(art3, NULL, NULL);  // 显示"黄海峰"
   iAsciiArt.render(art3, "HI", NULL);  // 显示"黄海"
    /*
    下面这句请在Terminal下运行
   iAsciiArt.render(art3, NULL, "14,10,12, 18");  // show all
   */

   /* do not forget this */
   iAsciiArt.Finalize(art3);
   iAsciiArt.Finalize(art4);

   printf("\n\n");
   return 0;
}
