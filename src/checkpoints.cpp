// Copyright (c) 2009-2015 The Bitcoin developers
// Copyright (c) 2011-2015 Litecoin Developers
// Copyright (c) 2013-2015 MemeCoin Developers

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     0, uint256("0xe8a2eaf89eb794aeee1ab448053e3badbecc63d45b638633edcfdd60a02100c4"))
			(     1, uint256("0xb9fe56beca6d379c4af46e2817c6eaa9d3431dba9157ca77dcac58ae1b4df9e8"))
			(     5, uint256("0x38bffe92ab73ba46b601ffa0e87188c9a2c807da38172b14d2360af09df5d889"))
			(     20000, uint256("0xdedca5aa154c1ec0eed994930fe2dc606a0a4a7b992c657822bf70dab865ffd9"))
			(     55555, uint256("0x4423f448732a89983572a54ff74694df83349abcaf49941a83e8ef5e3ddbc4ec"))
			(     63834, uint256("0x356cf7536b61beed63846803da9502199fcd7b3dc91741a71bbe92f3a7ba00ac"))
			(     92460, uint256("0xad206b5adc46ab903873c4cd7af402c4411b3b6b32b5908267bd441e53897a14"))
			(     166973, uint256("0xaf0307187ee4fbf6b9f124f4a003bfbd44420e1d307a5ad5fb80d2f38deb1a32"))
			(     226351, uint256("0xacea108185911eb95e18682ed9ce0804ee7776867bb151ef7b2cb15f3c07f3fc"))
			(     369300, uint256("0x4b5835a92a73cedd00f3c9081b32c532e93f0905682ac2998b8279f795d50697"))
			(     920000, uint256("0x2da3848a57f7fe88b2b3c11957bb70a10468186e2ac5c871a1cf771df3291640"))
			(     950000, uint256("0x8d5ba9c6b831de153db47e5cb4a9fac4332e194d409bb4c3ac4a90be33151cce"))
			(     1004999, uint256("0x92c9e26042d5632802b5c79bfc769900a7bc57b4169e7053374eafcba76d3bc4"))
			(     1005000, uint256("0xf88317aa0a5da890ea2790e85e420a18bac6cfdcadf146a0ced4eb7c202acecb"))
			(     1005001, uint256("0x902c79df1b3a4b9e702f209d73d5d92cd295cf2d6b656b93565f655bff9d1515"))
			(     1250000, uint256("0xe8313869a05959dc3b6d7693089c6aa305c8c3ff0a88f10f1c4a9817f4273d8c"))
            (     1285000, uint256("0x0333a9bd7098a8d97e959405586f7b9f88546dfc7c9d166ae3b31584308ef065"))

            ;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
