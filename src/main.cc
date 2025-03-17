#include <iostream>

#include "dpdk.h"
#include "doca_flow.h"
#include "doca_argp.h"

DOCA_LOG_REGISTER(MAIN::MAIN);

int main(int argc, char *argv[])
{
    doca_error_t ret = doca_log_init();
    if (ret != DOCA_SUCCESS)
    {
        printf("doca_log_init faild!\n");
        exit(-1);
    }

    ret = doca_argp_initd(argc, argv);
    if (ret != DOCA_SUCCESS)
    {
        DOCA_LOG_ERR("dpdk init faild!\n");
        exit(-2);
    }
    
    std::cout << "SHIO:" << std::endl;
    return 0;
}