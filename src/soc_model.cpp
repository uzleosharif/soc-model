
// SPDX-License-Identifier: SPDX

#include "soc_model.hpp"
#include "common.hpp"
#include "config.hpp"

namespace soc_model {

auto SimulatePulpissimoSoC(std::size_t number_of_instructions) -> void {

  coro::sync_wait(CpuTask<RiscV32bConfig>(
      number_of_instructions,
      BusTask<RiscV32bConfig, MemoryMappedTransaction<std::uint32_t>>));
}

} // namespace soc_model
