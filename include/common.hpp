
// SPDX-License-Identifier: SPDX

#pragma once

#include <span>

namespace soc_model {

enum class Isa { kRiscV, kArm };
enum class IsaWordLength { k32Bit, k64Bit };

template <class AddressType> struct MemoryMappedTransaction {
  enum class CommandType { kRead, kWrite };

  AddressType address{0};
  CommandType command{CommandType::kRead};
  std::span<std::byte> data{};
};

} // namespace soc_model
