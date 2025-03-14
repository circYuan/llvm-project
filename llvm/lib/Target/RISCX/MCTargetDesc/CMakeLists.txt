add_llvm_component_library(LLVMRISCXDesc
  RISCXMCTargetDesc.cpp

  LINK_COMPONENTS
  MC
  RISCXInfo

  ADD_TO_COMPONENT
  RISCX
  )
