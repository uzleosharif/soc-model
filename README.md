

# SoC Model

This project aims to try out modeling SoC components (processor, peripherals etc) 
in a transaction-level modeling details without using external libraries like 
SystemC etc.

## Design

Try out C++ co-routines to model each HW device behavior. This way we can introduce 
concurrency between HW device threads within the simulation run.

### Limitation

- Currently we do not see any real need for a memory device but it could be added later
if needed.
- Being behavioral model, we aim to just ensure functional correctness of the 
  firmware targeted for the CPU. No timing estimates are made.
