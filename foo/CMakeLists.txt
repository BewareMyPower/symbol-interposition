add_library(foo SHARED foo.c)
if (EXTRA_LINK_OPTIONS)
    target_link_options(foo PRIVATE ${EXTRA_LINK_OPTIONS})
endif ()
