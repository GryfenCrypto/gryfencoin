#ifndef GRYFENCOIN_ALGO_H
#define GRYFENCOIN_ALGO_H

#include<map>
#include <assert.h>
#include <stddef.h>
#include "uint256.h"


typedef void (*doAlgo) (char*,char*,uint512[],int);


extern std::map<int,doAlgo> algosTable;

void buildAlgosTable();




#endif // GRYFENCOIN_ALGO_H
