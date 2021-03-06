#ifndef LLARP_PATH_TYPES_HPP
#define LLARP_PATH_TYPES_HPP

#include <aligned.hpp>
#include <crypto.h>

namespace llarp
{
  using PathID_t = AlignedBuffer< PATHIDSIZE >;
}

#endif
