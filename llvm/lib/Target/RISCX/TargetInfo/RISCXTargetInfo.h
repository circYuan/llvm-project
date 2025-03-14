#ifndef LLVM_LIB_TARGET_RISCX_TARGETINFO_RISCXTARGETINFO_H
#define LLVM_LIB_TARGET_RISCX_TARGETINFO_RISCXTARGETINFO_H

namespace llvm {

class Target;

Target &getTheRISCX32Target();
Target &getTheRISCX64Target();

} // namespace llvm
#endif
