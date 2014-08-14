# include "gryfencoin_algo.h"
# include "hashblock.h"

std::map<int,doAlgo> algosTable;


void buildAlgosTable()
{

    int index=0;

    // balke512

    algosTable[index++]=blake;

    // bmw512

    algosTable[index++]=bmw512;

    // groestl512

    algosTable[index++]=groestl512;

    // jh512

    algosTable[index++]=jh512;

    // keccak512

    algosTable[index++]=keccak512;

    // skein512

    algosTable[index++]=skein512;

    // luffa512

    algosTable[index++]=luffa512;

    // cubehash512

    algosTable[index++]=cubehash512;

    // shavite512

    algosTable[index++]=shavite512;

    // simd512

    algosTable[index++]=simd512;

    // echo512

    algosTable[index++]=echo512;

    // hamsi512

    algosTable[index++]=hamsi512;

    // fugue512

    algosTable[index++]=fugue512;

    // shabal512

    algosTable[index++]=shabal512;

    // whirlpool

    algosTable[index++]=whirlpool;

    assert(index==15);
}
