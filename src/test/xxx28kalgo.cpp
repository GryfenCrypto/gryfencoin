#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>


using namespace std;
using namespace boost;

static const int64_t COIN = 100000000;
// gryfencrypto
static const long hextable[] =
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 10-19
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 30-39
    -1, -1, -1, -1, -1, -1, -1, -1,  0,  1,
     2,  3,  4,  5,  6,  7,  8,  9, -1, -1,		// 50-59
    -1, -1, -1, -1, -1, 10, 11, 12, 13, 14,
    15, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 70-79
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 10, 11, 12,		// 90-99
    13, 14, 15, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 110-109
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 130-139
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 150-159
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 170-179
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 190-199
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 210-219
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,		// 230-239
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1
};

long hex2long(const char* hexString)
{
    long ret = 0;

    while (*hexString && ret >= 0)
    {
        ret = (ret << 4) | hextable[*hexString++];
    }

    return ret;
}

int static generateMTRandom(unsigned int s, int range)
{
    random::mt19937 gen(s);
    random::uniform_int_distribution<> dist(1, range);
    return dist(gen);
}


// gryfencrypto:
unsigned int nTargetSpacing = 1 * 60;
static const int64_t nLowEndSubsidy = 50 * COIN;
static const int64_t nHighEndSubsidy = 50000 * COIN;
static const int nOfMostProfitableBlock=(60*60*24*50)/nTargetSpacing; // # of blocks in 50 days
static const int nStartingRandomRange = 100000;

int64_t GetProofOfWorkReward(int64_t nFees,int nTestBlockHeight)
{
    int64_t nSubsidy = nLowEndSubsidy;
    int nBlockHeight = nTestBlockHeight;

    if (nBlockHeight == 1)
    {
        nSubsidy = nHighEndSubsidy;//150000 * COIN; // first block is very generous!

    }
    else
    {
        // a larger number means less probabilty to find a high reward
        int nRandomRangeMax=nStartingRandomRange;
        double nMaxRewardAreaPercentage=0.01;

        // for the first 50 days we are going to be more generous
        // then every 50 day the odds of high rewards get lower
        int factor = nBlockHeight/nOfMostProfitableBlock;

        nRandomRangeMax = (factor+1) * nStartingRandomRange;


        // probability partions of the range:
        int nMaxRewardRange=(nMaxRewardAreaPercentage*0.01*nRandomRangeMax);
        int nMaxRewardRangeStart=1;

        int n2ndRewardRange= 2 * nMaxRewardRange;
        int n2ndRewardRangeStart = nMaxRewardRangeStart + nMaxRewardRange;

        int n3dRewardRange= 2 * n2ndRewardRange;
        int n3dRewardRangeStart = n2ndRewardRangeStart + n2ndRewardRange;

        int nNormalRewardRangeStart=n3dRewardRangeStart + n3dRewardRange;
        int nNormalRewardRange = (nRandomRangeMax- nNormalRewardRangeStart)/2;

        int nLowRewardRangeStart = nNormalRewardRangeStart + nNormalRewardRange;
        int nLowRewardRange = nNormalRewardRange;


        std::string fakeHash = "00000a721a62a6e0vcbcvbncvcvcvncvncvn81cc6440a07b0dd0b7918d2842debe19d1ad25411ea1a4bfd";
        std::string cseed_str = fakeHash.substr(1,20);
        const char* cseed = cseed_str.c_str();
        long seed = hex2long(cseed);

        int rand = generateMTRandom(seed, nRandomRangeMax);

        if(rand >= nMaxRewardRangeStart && rand < nMaxRewardRangeStart + nMaxRewardRange)
            nSubsidy = nHighEndSubsidy;
        else if(rand >= n2ndRewardRangeStart && rand < n2ndRewardRangeStart + n2ndRewardRange)
            nSubsidy = nHighEndSubsidy/10;
        else if(rand >= n3dRewardRangeStart && rand < n3dRewardRangeStart + n3dRewardRange)
            nSubsidy = nHighEndSubsidy/20;
        else if(rand >= n3dRewardRangeStart && rand < n3dRewardRangeStart + n3dRewardRange)
            nSubsidy = nHighEndSubsidy/20;
        else if(rand >= nNormalRewardRangeStart && rand < nNormalRewardRangeStart + nNormalRewardRange)
            nSubsidy = nLowEndSubsidy;
        else if(rand >= nLowRewardRangeStart && rand < nLowRewardRangeStart + nLowRewardRange)
            nSubsidy = nHighEndSubsidy/100;



//        return nSubsidy + nFees;
    }

    return nSubsidy + nFees;
}


TEST_CASE( "GetProofOfWorkReward", "[GetProofOfWorkReward]" ) {
     int fees=1;
   SECTION( "first block" ) {

    REQUIRE( GetProofOfWorkReward(fees,1) == (nHighEndSubsidy+fees) );
   }

   SECTION( "less than 50 days" ) {

    REQUIRE( GetProofOfWorkReward(fees,1000) < (nHighEndSubsidy+fees) );
   }
}

