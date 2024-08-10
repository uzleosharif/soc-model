

// SPDX-License=Identifier

// Simulates an (embedded) SoC at (RISC) CPU's instruction-accurate level.
// The SoC behavior can also be said to be modelled at transaction-level
// modeling detail.

#pragma once

#include <print>

#include "common.hpp"
#include <coro/coro.hpp>

namespace soc_model {

template <class BusConfig, class MemoryMappedTransactionType>
auto BusTask(MemoryMappedTransactionType source_txn)
    -> coro::task<MemoryMappedTransactionType> {
  co_return source_txn;
}

/// This co-routine models a RISC processor pipeline.
///
/// @param number_of_instructions Number of instructions to simulate through the
/// processor RISC pipeline.
/// @param BusTask The co-routine to request external read/write data (e.g. to
/// memory, peripheral etc.)
template <class CpuConfig>
auto CpuTask(std::size_t number_of_instructions,
             auto BusTask) -> coro::task<void> {

  // NOTE: For simplicity, this model assumes the whole firmware is already in
  // CPU cache hence instruciton-fetches need not go to bus and correspondingly
  // need not be modeled to improve simulation performance.

  for ([[maybe_unused]] auto i :
       std::views::iota(1) | std::views::take(number_of_instructions)) {
    // NOTE: Currently, we are not interested in decoding and executing steps
    // rather async communication with other co-routines/tasks
    //
    // Assume we have decoded the current instruction to be a memory
    // instruciton (say read word from location 0x0)
    if constexpr (CpuConfig::kIsaWordLength == IsaWordLength::k32Bit) {
      using AddressType = std::uint32_t;

      MemoryMappedTransaction<AddressType> memory_txn{
          .address = 0x0,
          .command = MemoryMappedTransaction<AddressType>::CommandType::kRead};
      auto result_txn{co_await BusTask(memory_txn)};
    }

    co_return;
  }
}

/// This is public facing function meant to be called by client/user to start
/// simulation run.
///
/// @param number_of_instructions Number of instructions to simulate on
/// Pulpissimo SoC model.
auto SimulatePulpissimoSoC(std::size_t number_of_instructions) -> void;

} // namespace soc_model
