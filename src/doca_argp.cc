#pragma once

#include "doca_argp.h"
#include "dpdk.h"

extern "C"
{

DOCA_LOG_REGISTER(DOCA_ARGP::MAIN);

doca_error_t doca_argp_initd(int argc, char **argv)
{
    doca_error_t ret;

    ret = doca_argp_init("doca_flow_modify_header", NULL);
	if (ret != DOCA_SUCCESS) {
		DOCA_LOG_ERR("Failed to init ARGP resources: %s", doca_error_get_descr(ret));
		return ret;
	}
	doca_argp_set_dpdk_program(dpdk_init);
	ret = doca_argp_start(argc, argv);
	if (ret != DOCA_SUCCESS) {
		DOCA_LOG_ERR("Failed to parse sample input: %s", doca_error_get_descr(ret));
		doca_argp_destroy();;
	}

    return ret;
}

};