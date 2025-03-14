#include "RISCXMCTargetDesc.h"
#include "TargetInfo/RISCXTargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

#define GET_SUBTARGETINFO_MC_DESC
#include "RISCXGenSubtargetInfo.inc"

using namespace llvm;

static MCAsmInfo *createRISCXMCAsmInfo(const MCRegisterInfo &MRI,
        const Triple &TT, const MCTargetOptions &Options){
  MCAsmInfo *MAI = new MCAsmInfo();
  return MAI;
}

static MCInstrInfo *createRISCXMCInstrInfo() {
    MCInstrInfo * MII = new MCInstrInfo();
    return MII;
}

static MCRegisterInfo *createRISCXMCRegInfo(const Triple & TT) {
    MCRegisterInfo * MRI = new MCRegisterInfo();
    return MRI;
}

static MCSubtargetInfo *createRISCXMCSubtargetInfo(const Triple & TT, StringRef CPU, StringRef Features) {
    return createRISCXMCSubtargetInfoImpl(TT, CPU, CPU, Features);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeRISCXTargetMC(){
    // create many MC Info and need to create them from TargetMachine, CTOR
    for (Target *T : {&getTheRISCX32Target(), &getTheRISCX64Target()}){
        // register many class here. We should refer to the TargetRegistry.h
        // should with check each Functor's argument list
        TargetRegistry::RegisterMCAsmInfo(*T, createRISCXMCAsmInfo);
        // since its default creator has created the object, can ignore it.
        //TargetRegistry::RegisterMCObjectFileInfo(*T, );
        TargetRegistry::RegisterMCInstrInfo(*T, createRISCXMCInstrInfo);
        TargetRegistry::RegisterMCRegInfo(*T, createRISCXMCRegInfo);
        TargetRegistry::RegisterMCSubtargetInfo(*T, createRISCXMCSubtargetInfo);
    }
}
