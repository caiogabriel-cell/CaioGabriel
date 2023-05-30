#include <stdio.h>
#include "tinyexpr.h"

int main(void) {
    printf("%.2f\n", te_interp("7! + 9!", 0));
    return 0;
}