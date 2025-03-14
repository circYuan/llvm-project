#include "llvm/MC/TargetRegistry.h"
#include "RISCXTargetInfo.h"
using namespace llvm;

Target &llvm::getTheRISCX32Target(){
  static Target TheRISCX32Target;
  return TheRISCX32Target;
}

Target &llvm::getTheRISCX64Target(){
  static Target TheRISCX64Target;
  return TheRISCX64Target;
}


extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeRISCXTargetInfo() {
  RegisterTarget<Triple::riscx32, false> X(getTheRISCX32Target(), "riscx32", "RISC-X (32-bit little endian)", "RISCX");
  RegisterTarget<Triple::riscx64, false> Y(getTheRISCX64Target(), "riscx64", "RISC-X (64-bit little endian)", "RISCX");
}
