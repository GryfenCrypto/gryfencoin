#ifndef GRYFENCOIN_ALGO_H
#define GRYFENCOIN_ALGO_H
// gryfencrypto
#include<map>
#include <assert.h>
#include <stddef.h>
// gryfencrypto

// gryfencrypto
struct AlgoContainer
{
    void (*init)(void*);
    void (*apply)(void *, const void *, size_t);
    void (*close)(void *, void *);
};

extern std::map<int,AlgoContainer> algosTable;

void buildAlgosTable();

// gryfencrypto


#endif // GRYFENCOIN_ALGO_H
