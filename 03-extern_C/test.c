//
//  test.c
//  03-extern_C
//
//  Created by XFB on 2021/4/28.
//

#include <stdio.h>
#include "math.h"

void test() {
    sum(10, 20);

    printf("test - %d", sum(10, 20));
}
