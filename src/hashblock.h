#ifndef HASHBLOCK_H
#define HASHBLOCK_H

#include "uint256.h"
#include "sph_blake.h"
#include "sph_bmw.h"
#include "sph_groestl.h"
#include "sph_jh.h"
#include "sph_keccak.h"
#include "sph_skein.h"
#include "sph_luffa.h"
#include "sph_cubehash.h"
#include "sph_shavite.h"
#include "sph_simd.h"
#include "sph_echo.h"
#include "sph_hamsi.h"
#include "sph_fugue.h"
#include "sph_shabal.h"
#include "sph_whirlpool.h"
#include "gryfencoin_algo.h"
#include "util.h"



#ifndef QT_NO_DEBUG
#include <string>
#endif

#ifdef GLOBALDEFINED
#define GLOBAL
#else
#define GLOBAL extern
#endif


GLOBAL sph_blake512_context     z_blake;
GLOBAL sph_bmw512_context       z_bmw;
GLOBAL sph_groestl512_context   z_groestl;
GLOBAL sph_jh512_context        z_jh;
GLOBAL sph_keccak512_context    z_keccak;
GLOBAL sph_skein512_context     z_skein;
GLOBAL sph_luffa512_context     z_luffa;
GLOBAL sph_cubehash512_context  z_cubehash;
GLOBAL sph_shavite512_context   z_shavite;
GLOBAL sph_simd512_context      z_simd;
GLOBAL sph_echo512_context      z_echo;
GLOBAL sph_hamsi512_context      z_hamsi;
GLOBAL sph_fugue512_context      z_fugue;
GLOBAL sph_shabal512_context     z_shabal;
GLOBAL sph_whirlpool_context     z_whirlpool;

#define fillz() do { \
    sph_blake512_init(&z_blake); \
    sph_bmw512_init(&z_bmw); \
    sph_groestl512_init(&z_groestl); \
    sph_jh512_init(&z_jh); \
    sph_keccak512_init(&z_keccak); \
    sph_skein512_init(&z_skein); \
    sph_luffa512_init(&z_luffa); \
    sph_cubehash512_init(&z_cubehash); \
    sph_shavite512_init(&z_shavite); \
    sph_simd512_init(&z_simd); \
    sph_echo512_init(&z_echo); \
    sph_hamsi512_init(&z_hamsi); \
    sph_fugue512_init(&z_fugue); \
    sph_shabal512_init(&z_shabal); \
    sph_whirlpool_init(&z_whirlpool); \
} while (0) 


#define ZBLAKE (memcpy(&ctx_blake, &z_blake, sizeof(z_blake)))
#define ZBMW (memcpy(&ctx_bmw, &z_bmw, sizeof(z_bmw)))
#define ZGROESTL (memcpy(&ctx_groestl, &z_groestl, sizeof(z_groestl)))
#define ZJH (memcpy(&ctx_jh, &z_jh, sizeof(z_jh)))
#define ZKECCAK (memcpy(&ctx_keccak, &z_keccak, sizeof(z_keccak)))
#define ZSKEIN (memcpy(&ctx_skein, &z_skein, sizeof(z_skein)))
#define ZHAMSI (memcpy(&ctx_hamsi, &z_hamsi, sizeof(z_hamsi)))
#define ZFUGUE (memcpy(&ctx_fugue, &z_fugue, sizeof(z_fugue)))
#define ZSHABAL (memcpy(&ctx_shabal, &z_shabal, sizeof(z_shabal)))
#define ZWHIRLPOOL (memcpy(&ctx_whirlpool, &z_whirlpool, sizeof(z_whirlpool)))


inline void blake(char* pbegin, char* pend,uint512 hash[],int index)
{

    sph_blake512_context     ctx_blake;
    sph_blake512_init(&ctx_blake);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_blake512 (&ctx_blake, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_blake512_close(&ctx_blake, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_blake512 (&ctx_blake, static_cast<const void*>(&hash[index-1]), 64);
        sph_blake512_close(&ctx_blake,  static_cast<void*>(&hash[index]));
    }
}

inline void bmw512(char* pbegin, char* pend,uint512 hash[], int index)
{
    sph_bmw512_context       ctx_bmw;
    sph_bmw512_init(&ctx_bmw);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_bmw512 (&ctx_bmw, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_bmw512_close(&ctx_bmw, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_bmw512 (&ctx_bmw, static_cast<const void*>(&hash[index-1]), 64);
        sph_bmw512_close(&ctx_bmw, static_cast<void*>(&hash[index]));
    }
}


inline void groestl512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_groestl512_context   ctx_groestl;
    sph_groestl512_init(&ctx_groestl);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_groestl512 (&ctx_groestl, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_groestl512_close(&ctx_groestl, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_groestl512 (&ctx_groestl, static_cast<const void*>(&hash[index-1]), 64);
        sph_groestl512_close(&ctx_groestl, static_cast<void*>(&hash[index]));
    }


}

inline void jh512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_jh512_context        ctx_jh;
    sph_jh512_init(&ctx_jh);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_jh512 (&ctx_jh, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_jh512_close(&ctx_jh, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_jh512 (&ctx_jh, static_cast<const void*>(&hash[index-1]), 64);
        sph_jh512_close(&ctx_jh, static_cast<void*>(&hash[index]));
    }



}

inline void keccak512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_keccak512_context    ctx_keccak;
    sph_keccak512_init(&ctx_keccak);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_keccak512 (&ctx_keccak, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_keccak512_close(&ctx_keccak, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_keccak512 (&ctx_keccak, static_cast<const void*>(&hash[index-1]), 64);
        sph_keccak512_close(&ctx_keccak, static_cast<void*>(&hash[index]));
    }

}
inline void skein512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_skein512_context     ctx_skein;
    sph_skein512_init(&ctx_skein);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_skein512 (&ctx_skein, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_skein512_close(&ctx_skein, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_skein512 (&ctx_skein, static_cast<const void*>(&hash[index-1]), 64);
        sph_skein512_close(&ctx_skein, static_cast<void*>(&hash[index]));
    }

}


inline void luffa512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_luffa512_context     ctx_luffa;
    sph_luffa512_init(&ctx_luffa);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_luffa512 (&ctx_luffa, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_luffa512_close(&ctx_luffa, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_luffa512 (&ctx_luffa, static_cast<void*>(&hash[index-1]), 64);
        sph_luffa512_close(&ctx_luffa, static_cast<void*>(&hash[index]));
    }


}

inline void cubehash512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_cubehash512_context  ctx_cubehash;
    sph_cubehash512_init(&ctx_cubehash);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_cubehash512 (&ctx_cubehash, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_cubehash512_close(&ctx_cubehash, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_cubehash512 (&ctx_cubehash, static_cast<const void*>(&hash[index-1]), 64);
        sph_cubehash512_close(&ctx_cubehash, static_cast<void*>(&hash[index]));
    }



}

inline void shavite512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_shavite512_context   ctx_shavite;
    sph_shavite512_init(&ctx_shavite);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_shavite512 (&ctx_shavite, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_shavite512_close(&ctx_shavite, static_cast<void*>(&hash[0]));
    }
    else
    {

        sph_shavite512(&ctx_shavite, static_cast<const void*>(&hash[index-1]), 64);
        sph_shavite512_close(&ctx_shavite, static_cast<void*>(&hash[index]));
    }

}

inline void simd512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_simd512_context      ctx_simd;
    sph_simd512_init(&ctx_simd);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_simd512 (&ctx_simd, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_simd512_close(&ctx_simd, static_cast<void*>(&hash[0]));
    }
    else
    {

        sph_simd512 (&ctx_simd, static_cast<const void*>(&hash[index-1]), 64);
        sph_simd512_close(&ctx_simd, static_cast<void*>(&hash[index]));
    }


}

inline void echo512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_echo512_context      ctx_echo;
    sph_echo512_init(&ctx_echo);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_echo512 (&ctx_echo, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_echo512_close(&ctx_echo, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_echo512 (&ctx_echo, static_cast<const void*>(&hash[index-1]), 64);
        sph_echo512_close(&ctx_echo, static_cast<void*>(&hash[index]));
    }

}

inline void hamsi512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_hamsi512_context      ctx_hamsi;
    sph_hamsi512_init(&ctx_hamsi);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_hamsi512 (&ctx_hamsi, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_hamsi512_close(&ctx_hamsi, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_hamsi512 (&ctx_hamsi, static_cast<const void*>(&hash[index-1]), 64);
        sph_hamsi512_close(&ctx_hamsi, static_cast<void*>(&hash[index]));
    }

}

inline void fugue512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_fugue512_context      ctx_fugue;
    sph_fugue512_init(&ctx_fugue);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_fugue512 (&ctx_fugue, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_fugue512_close(&ctx_fugue, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_fugue512 (&ctx_fugue, static_cast<const void*>(&hash[index-1]), 64);
        sph_fugue512_close(&ctx_fugue, static_cast<void*>(&hash[index]));
    }



}

inline void shabal512(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_shabal512_context     ctx_shabal;
    sph_shabal512_init(&ctx_shabal);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_shabal512 (&ctx_shabal, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_shabal512_close(&ctx_shabal, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_shabal512 (&ctx_shabal, static_cast<const void*>(&hash[index-1]), 64);
        sph_shabal512_close(&ctx_shabal, static_cast<void*>(&hash[index]));
    }


}

inline void whirlpool(char* pbegin, char* pend,uint512 hash[],int index)
{
    sph_whirlpool_context     ctx_whirlpool;
    sph_whirlpool_init(&ctx_whirlpool);
    if(index==0)
    {
        static unsigned char pblank[1];
        sph_whirlpool (&ctx_whirlpool, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
        sph_whirlpool_close(&ctx_whirlpool, static_cast<void*>(&hash[0]));
    }
    else
    {
        sph_whirlpool (&ctx_whirlpool, static_cast<const void*>(&hash[index-1]), 64);
        sph_whirlpool_close(&ctx_whirlpool, static_cast<void*>(&hash[index]));
    }
}






// gryfencrypto: 4 random picked algorithms generate the hash
template<typename T1>
inline uint256 Hash9(const T1 pbegin, const T1 pend)

{
//    sph_blake512_context     ctx_blake;
//    sph_bmw512_context       ctx_bmw;
//    sph_groestl512_context   ctx_groestl;
//    sph_jh512_context        ctx_jh;
//    sph_keccak512_context    ctx_keccak;
//    sph_skein512_context     ctx_skein;
//    sph_luffa512_context     ctx_luffa;
//    sph_cubehash512_context  ctx_cubehash;
//    sph_shavite512_context   ctx_shavite;
//    sph_simd512_context      ctx_simd;
//    sph_echo512_context      ctx_echo;
//    sph_hamsi512_context      ctx_hamsi;
//    sph_fugue512_context      ctx_fugue;
//    sph_shabal512_context     ctx_shabal;
//    sph_whirlpool_context     ctx_whirlpool;
//    static unsigned char pblank[1];


#ifndef QT_NO_DEBUG
    //std::string strhash;
    //strhash = "";
#endif
    
    uint512 hash[8];

    // choose 4 random algos
    for(int i=0;i<4; i++)
    {
        int rndIndex = GetRandInt(14);
        algosTable[rndIndex](pbegin,pend,hash,i);


    }
    return hash[3].trim256();
//    uint512 hash[17];

//    sph_blake512_init(&ctx_blake);
//    sph_blake512 (&ctx_blake, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
//    sph_blake512_close(&ctx_blake, static_cast<void*>(&hash[0]));
    
//    sph_bmw512_init(&ctx_bmw);
//    sph_bmw512 (&ctx_bmw, static_cast<const void*>(&hash[0]), 64);
//    sph_bmw512_close(&ctx_bmw, static_cast<void*>(&hash[1]));

//    sph_groestl512_init(&ctx_groestl);
//    sph_groestl512 (&ctx_groestl, static_cast<const void*>(&hash[1]), 64);
//    sph_groestl512_close(&ctx_groestl, static_cast<void*>(&hash[2]));

//    sph_skein512_init(&ctx_skein);
//    sph_skein512 (&ctx_skein, static_cast<const void*>(&hash[2]), 64);
//    sph_skein512_close(&ctx_skein, static_cast<void*>(&hash[3]));
    
//    sph_jh512_init(&ctx_jh);
//    sph_jh512 (&ctx_jh, static_cast<const void*>(&hash[3]), 64);
//    sph_jh512_close(&ctx_jh, static_cast<void*>(&hash[4]));
    
//    sph_keccak512_init(&ctx_keccak);
//    sph_keccak512 (&ctx_keccak, static_cast<const void*>(&hash[4]), 64);
//    sph_keccak512_close(&ctx_keccak, static_cast<void*>(&hash[5]));

//    sph_luffa512_init(&ctx_luffa);
//    sph_luffa512 (&ctx_luffa, static_cast<void*>(&hash[5]), 64);
//    sph_luffa512_close(&ctx_luffa, static_cast<void*>(&hash[6]));
    
//    sph_cubehash512_init(&ctx_cubehash);
//    sph_cubehash512 (&ctx_cubehash, static_cast<const void*>(&hash[6]), 64);
//    sph_cubehash512_close(&ctx_cubehash, static_cast<void*>(&hash[7]));
    
//    sph_shavite512_init(&ctx_shavite);
//    sph_shavite512(&ctx_shavite, static_cast<const void*>(&hash[7]), 64);
//    sph_shavite512_close(&ctx_shavite, static_cast<void*>(&hash[8]));
        
//    sph_simd512_init(&ctx_simd);
//    sph_simd512 (&ctx_simd, static_cast<const void*>(&hash[8]), 64);
//    sph_simd512_close(&ctx_simd, static_cast<void*>(&hash[9]));

//    sph_echo512_init(&ctx_echo);
//    sph_echo512 (&ctx_echo, static_cast<const void*>(&hash[9]), 64);
//    sph_echo512_close(&ctx_echo, static_cast<void*>(&hash[10]));

//    sph_hamsi512_init(&ctx_hamsi);
//    sph_hamsi512 (&ctx_hamsi, static_cast<const void*>(&hash[10]), 64);
//    sph_hamsi512_close(&ctx_hamsi, static_cast<void*>(&hash[11]));

//    sph_fugue512_init(&ctx_fugue);
//    sph_fugue512 (&ctx_fugue, static_cast<const void*>(&hash[11]), 64);
//    sph_fugue512_close(&ctx_fugue, static_cast<void*>(&hash[12]));

//    sph_shabal512_init(&ctx_shabal);
//    sph_shabal512 (&ctx_shabal, static_cast<const void*>(&hash[12]), 64);
//    sph_shabal512_close(&ctx_shabal, static_cast<void*>(&hash[13]));

//    sph_whirlpool_init(&ctx_whirlpool);
//    sph_whirlpool (&ctx_whirlpool, static_cast<const void*>(&hash[13]), 64);
//    sph_whirlpool_close(&ctx_whirlpool, static_cast<void*>(&hash[14]));


//    return hash[14].trim256();
}






#endif // HASHBLOCK_H
