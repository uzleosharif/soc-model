
// SPDX-License-Identifier: SPDX

#pragma once

#include "common.hpp"

namespace soc_model {

struct RiscV32bConfig {
  static auto constexpr kIsa{Isa::kRiscV};
  static auto constexpr kIsaWordLength{IsaWordLength::k32Bit};
};

struct RiscV64bConfig {
  static auto constexpr kIsa{Isa::kRiscV};
  static auto constexpr kIsaWordLength{IsaWordLength::k64Bit};
};

struct PulpinoBusConfig {};

struct PulpissimoBusConfig {};

} // namespace soc_model
