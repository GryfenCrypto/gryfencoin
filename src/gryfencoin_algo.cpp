# include "gryfencoin_algo.h"
#include "hashblock.h"

std::map<int,AlgoContainer> algosTable;


void buildAlgosTable()
{
    AlgoContainer ac;
    int index=0;

    // balke512
    ac.apply=sph_blake512;
    ac.close=sph_blake512_close;
    ac.init=sph_blake512_init;
    algosTable[index++]=ac;

    // bmw512
    ac.apply=sph_bmw512;
    ac.close=sph_bmw512_close;
    ac.init=sph_bmw512_init;
    algosTable[index++]=ac;

    // groestl512
    ac.apply=sph_groestl512;
    ac.close=sph_groestl512_close;
    ac.init=sph_groestl512_init;
    algosTable[index++]=ac;

    // jh512
    ac.apply=sph_jh512;
    ac.close=sph_jh512_close;
    ac.init=sph_jh512_init;
    algosTable[index++]=ac;

    // keccak512
    ac.apply=sph_keccak512;
    ac.close=sph_keccak512_close;
    ac.init=sph_keccak512_init;
    algosTable[index++]=ac;

    // skein512
    ac.apply=sph_skein512;
    ac.close=sph_skein512_close;
    ac.init=sph_skein512_init;
    algosTable[index++]=ac;

    // luffa512
    ac.apply=sph_luffa512;
    ac.close=sph_luffa512_close;
    ac.init=sph_luffa512_init;
    algosTable[index++]=ac;

    // cubehash512
    ac.apply=sph_cubehash512;
    ac.close=sph_cubehash512_close;
    ac.init=sph_cubehash512_init;
    algosTable[index++]=ac;

    // shavite512
    ac.apply=sph_shavite512;
    ac.close=sph_shavite512_close;
    ac.init=sph_shavite512_init;
    algosTable[index++]=ac;

    // simd512
    ac.apply=sph_simd512;
    ac.close=sph_simd512_close;
    ac.init=sph_simd512_init;
    algosTable[index++]=ac;

    // echo512
    ac.apply=sph_echo512;
    ac.close=sph_echo512_close;
    ac.init=sph_echo512_init;
    algosTable[index++]=ac;

    // hamsi512
    ac.apply=sph_hamsi512;
    ac.close=sph_hamsi512_close;
    ac.init=sph_hamsi512_init;
    algosTable[index++]=ac;

    // fugue512
    ac.apply=sph_fugue512;
    ac.close=sph_fugue512_close;
    ac.init=sph_fugue512_init;
    algosTable[index++]=ac;

    // shabal512
    ac.apply=sph_shabal512;
    ac.close=sph_shabal512_close;
    ac.init=sph_shabal512_init;
    algosTable[index++]=ac;

    // whirlpool
    ac.apply=sph_whirlpool;
    ac.close=sph_whirlpool_close;
    ac.init=sph_whirlpool_init;
    algosTable[index++]=ac;

    assert(index==15);
}
