add_llvm_component_group(RISCX)
set(LLVM_TARGET_DEFINITIONS RISCX.td)

tablegen(LLVM RISCXGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(RISCXCommonTableGen)

add_llvm_target(RISCXCodeGen
  RISCXTargetMachine.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  IPO
  MC
  RISCXDesc
  RISCXInfo
  Scalar
  SelectionDAG
  Support
  Target
  TargetParser

  ADD_TO_COMPONENT
  RISCX
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
