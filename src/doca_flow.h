#pragma once

#include <doca_log.h>


extern "C"
{




struct entries_status {
	bool failure;
	int nb_processed;
};

struct flow_resources {
	uint32_t nr_counters;
	uint32_t nr_meters;
};

doca_error_t doca_log_init(void);


};

