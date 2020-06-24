#include "tree-info.hh"
#include "store-api.hh"

#include <nlohmann/json.hpp>

namespace nix::fetchers {

StorePath TreeInfo::computeStorePath(Store & store) const
{
    assert(narHash);
    return store.makeFixedOutputPath("source", FixedOutputHash {
        .method = FileIngestionMethod::Recursive,
        .hash = narHash,
    });
}

}
