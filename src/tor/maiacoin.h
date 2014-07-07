/* Copyright (c) 2014, Maiacoin Developers */
/* See LICENSE for licensing information */

/**
 * \file maiacoin.h
 * \brief Headers for maiacoin.cpp
 **/

#ifndef TOR_MAIACOIN_H
#define TOR_MAIACOIN_H

#ifdef __cplusplus
extern "C" {
#endif

    char const* maiacoin_tor_data_directory(
    );

    char const* maiacoin_service_directory(
    );

    int check_interrupted(
    );

    void set_initialized(
    );

    void wait_initialized(
    );

#ifdef __cplusplus
}
#endif

#endif

