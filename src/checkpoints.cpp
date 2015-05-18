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
			(     38, uint256("0xd980e61ece174baf76f7667ccb88344019f5988f22141990c53c47a17cba0bfc"))
			(     20000, uint256("0xdedca5aa154c1ec0eed994930fe2dc606a0a4a7b992c657822bf70dab865ffd9"))
			(     33333, uint256("0x47237006e77e567d5e6baf3cc40356fa10474efef99edcbfb065a5455e103227"))
			(     44444, uint256("0x06fa66866ebe356a0253d0b8f981ffa4cda19f908cb738eadbdf4ab370859d74"))
			(     38888, uint256("0x406404f4c03fc2a90321ed60b229c3b5f18c7d3bf64049f106f350005aa2cc95"))
			(     47680, uint256("0xe8f3183ff62bbe68da77e9d2b0bc2b41833706d9d1cf4d36f78b568de66d74c8"))
			(     47690, uint256("0x221571eb0572ad610194d99620c6c7f86cbfb368b989f5fda99bfe55432146c8"))
			(     55555, uint256("0x4423f448732a89983572a54ff74694df83349abcaf49941a83e8ef5e3ddbc4ec"))
			(     63834, uint256("0x356cf7536b61beed63846803da9502199fcd7b3dc91741a71bbe92f3a7ba00ac"))
			(     63852, uint256("0x4020c54c2d4ad11c71a52488cb4c5922241e4eb47551b8265af069688af03abd"))
			(     68975, uint256("0xffb3470a03c7c142de77f7902134bf60d60e7caa579c9df14fe241a2044d32ab"))
			(     71394, uint256("0x625f68083b671ee12763aa004c9853d232ba3043c109115155b3a068bac0380d"))
			(     79762, uint256("0xae7e8355625d52fab1d5d30283925f75f31f8e8af2df8fdb7643483a8b97645d"))
			(     79764, uint256("0xfa9531b566a52fed88fdb80e89f7e3bb05d8892e1408714724c324f72b4e35b4"))
			(     92460, uint256("0xad206b5adc46ab903873c4cd7af402c4411b3b6b32b5908267bd441e53897a14"))
			(     92469, uint256("0x1486d1d1a565b3ad3b359d8174242fe7a84184f473b94fc8321e39412ebc55b3"))
			(     116973, uint256("0xf4745f7c16bc4e8920fd32390890408fae80088d53693af108883897d472bba9"))
			(     126980, uint256("0x442443ebc0b8eadcb087d83654c71229a7b28ac8b1f9b9d767cc678e7ea9c132"))
			(     136973, uint256("0x5f7c7b76abac890e9673f3f214cfb3a41c6060f880bcce43bf64a0a143058a49"))
			(     156982, uint256("0xccc08e483aa5d6d6f979c1b75d44e62ea5ac3c8abac7c5f73784afe7950f469a"))
			(     166897, uint256("0xff6473c4d50c6c5680881649f868c112d5ec5a2e7109944250d42b0eba400636"))
			(     166973, uint256("0xaf0307187ee4fbf6b9f124f4a003bfbd44420e1d307a5ad5fb80d2f38deb1a32"))
			(     226351, uint256("0xacea108185911eb95e18682ed9ce0804ee7776867bb151ef7b2cb15f3c07f3fc"))
			(     226373, uint256("0x543162c69d2019f60c591f95553b1b4aef1253c3ef86e37ab03faab8b59ff070"))
			(     226412, uint256("0x266c535790001dba413478305bae8867d516bb90a2719a8f261e9cb7a62c40cf"))
			(     226453, uint256("0x4feb348792925dfe38ff11b6bbb10e7ccdd903a800345f1b7789fba77ed1e5c1"))
			(     313848, uint256("0x6922d7c1efd91e21801d86182be9779caa171808b23f252bc7853e14d6844af3"))
			(     314860, uint256("0xd1f3d2b69dbe5dd4d07c0845611e602ea769a4c5e50895f65d9ee9335908a930"))
			(     316317, uint256("0x33cefcdb034889ec6af5593943fcc3b89a4c3869e27e7f3b1a5b16d3c6ed856a"))
			(     316326, uint256("0xc614f8ca20f56eb9717e1b455c72addb2b0ab6bf5f89cef2121b8f435ca1ff50"))
			(     316404, uint256("0xd5ac56759e398ecf3040d2e6415df642416260265c3e9ba1ceae2d2ff991117f"))
			(     369100, uint256("0x2e17cd391e02a24e2953b2184b5b50add7378ba6678d806e471fbb3001aad445"))
			(     369300, uint256("0x4b5835a92a73cedd00f3c9081b32c532e93f0905682ac2998b8279f795d50697"))
			(     920000, uint256("0x2da3848a57f7fe88b2b3c11957bb70a10468186e2ac5c871a1cf771df3291640"))
			(     950000, uint256("0x8d5ba9c6b831de153db47e5cb4a9fac4332e194d409bb4c3ac4a90be33151cce"))
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
