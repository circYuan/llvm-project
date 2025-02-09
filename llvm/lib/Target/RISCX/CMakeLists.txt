add_llvm_component_group(RISCX)
set(LLVM_TARGET_DEFINITIONS RISCX.td)

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
  Scalar
  SelectionDAG
  Support
  Target
  TargetParser

  ADD_TO_COMPONENT
  RISCX

  )
