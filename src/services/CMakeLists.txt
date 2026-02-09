add_library(projet_cfr_services STATIC
  src/BpmnEditorModel.cpp
  src/CameraService.cpp
  src/CameraViewModel.cpp
  include/projet_cfr/services/BpmnEditorModel.h
  include/projet_cfr/services/CameraService.h
  include/projet_cfr/services/CameraViewModel.h
)

target_include_directories(projet_cfr_services PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(projet_cfr_services PUBLIC
  Qt6::Core
  Qt6::Multimedia
  projet_cfr_core
)
