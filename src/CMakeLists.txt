

SET(SRC 
    main.cc
    dpdk.cc
    doca_flow.cc
    doca_argp.cc
)

add_executable(lvs-doca ${SRC})

target_link_libraries(lvs-doca 
    ${DOCA_COMMON_LIBRARIES}
    ${DOCA_FLOW_LIBRARIES}
    ${DOCA_ARGP_LIBRARIES}
    ${DPDK_LIBRARIES}
)
