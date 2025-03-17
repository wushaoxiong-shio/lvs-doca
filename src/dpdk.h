#pragma once

#include <rte_eal.h>
#include <doca_error.h>

extern "C"
{

doca_error_t dpdk_init(int argc, char **argv);

};
