add_library(projet_cfr_core STATIC
  src/dummy.cpp
)

target_include_directories(projet_cfr_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
