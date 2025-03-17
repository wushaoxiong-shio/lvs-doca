#include "doca_flow.h"
#include "dpdk.h"

#include <doca_argp.h>
#include <doca_error.h>

extern "C"
{

DOCA_LOG_REGISTER(DOCA_FLOW::MAIN);

struct doca_log_backend *sdk_log;


doca_error_t doca_log_init(void)
{
    doca_error_t ret;
    ret = doca_log_backend_create_standard();
	if (ret != DOCA_SUCCESS)
		return ret;

	ret = doca_log_backend_create_with_file_sdk(stderr, &sdk_log);
	if (ret != DOCA_SUCCESS)
        return ret;

	ret = doca_log_backend_set_sdk_level(sdk_log, DOCA_LOG_LEVEL_WARNING);
	if (ret != DOCA_SUCCESS)
        return ret;

	DOCA_LOG_INFO("DOCA_SUCCESS The doca_log_init");
    return ret;
}














};
