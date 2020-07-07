#include <stdio.h>
#include <stdlib.h>
#include "../src/options.h"

int main(int argc, char *argv[])
{
    configuration_t *conf = (configuration_t *)malloc(sizeof(configuration_t));
    parse_cmd_arguments(argc, argv, conf);

    return 0;
}
