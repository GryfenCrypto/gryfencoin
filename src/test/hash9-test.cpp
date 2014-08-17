
#ifdef UTEST
#include <boost/foreach.hpp>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "init.h"
#include "wallet.h"
#include "walletdb.h"
#include "uint256_t.h"
#include "miner.h"
#include "main.h"
#include "hashblock.h"


TEST_CASE( "GetProofOfWorkReward", "[GetProofOfWorkReward]" ) {

   CBlock* block = new CBlock();

    REQUIRE(block != NULL);

    block->nVersion=1234;
    block->hashPrevBlock=0x000090e81cd08;
    block->hashMerkleRoot=0x278fbe92605a;
    block->nTime=1407524404;
    block->nBits=0x1f00ffff;
    block->nNonce=316534;

    CBlock* block2 = new CBlock();
    (*block2) = (*block);


    uint256 hash = block->GetHash();
    uint256 hash2 = block2->GetHash();

    cout << "hash:" << hash.ToString() << endl;
    cout << "hash2:" << hash2.ToString() << endl;
    REQUIRE(hash==hash2);
    delete block; delete block2;
}
#endif
