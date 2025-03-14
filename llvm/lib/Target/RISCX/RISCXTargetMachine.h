#ifndef LLVM_LIB_TARGET_RISCX_RISCXTARGETMACHINE_H
#define LLVM_LIB_TARGET_RISCX_RISCXTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

namespace llvm {

class RISCXTargetMachine : public CodeGenTargetMachineImpl {
public:
  RISCXTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                     StringRef FS, const TargetOptions &Options,
                     std::optional<llvm::Reloc::Model> RM, std::optional<CodeModel::Model> CM, CodeGenOptLevel OL, bool JIT);
};

} // namespace llvm

#endif
