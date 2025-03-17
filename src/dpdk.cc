#include "dpdk.h"

#include <doca_log.h>
#include <doca_error.h>

extern "C"
{

DOCA_LOG_REGISTER(DPDK::MAIN);

doca_error_t dpdk_init(int argc, char **argv)
{
    int result;

    result = rte_eal_init(argc, argv);
    if (result < 0) {
        DOCA_LOG_ERR("EAL initialization failed\n");
        return DOCA_ERROR_DRIVER;
    }
    return DOCA_SUCCESS;
}

};
