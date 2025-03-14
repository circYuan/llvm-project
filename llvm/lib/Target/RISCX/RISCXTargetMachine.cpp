#include "llvm/MC/TargetRegistry.h"
#include "TargetInfo/RISCXTargetInfo.h"
#include "RISCXTargetMachine.h"

#include <string>

using namespace llvm;

static StringRef computeDataLayout(const Triple &TT){
    return "e-m:e";
    //if(TT.isArch64Bit()){
    //}
}

// meaning the default linkage to static link, can refer to the Reloc enum
static Reloc::Model getEffectiveRelocModel(const Triple, std::optional<Reloc::Model> RM){
  return RM.value_or(Reloc::Static);
}

RISCXTargetMachine::RISCXTargetMachine(const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       std::optional<Reloc::Model> RM, std::optional<CodeModel::Model> CM,
                                       CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, computeDataLayout(TT), TT, CPU, FS, Options,
            getEffectiveRelocModel(TT,RM), getEffectiveCodeModel(CM, CodeModel::Small), OL) {

    // must call it to create the MC Info
    initAsmInfo();
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeRISCXTarget() {
  RegisterTargetMachine<RISCXTargetMachine> X(getTheRISCX32Target());

}
