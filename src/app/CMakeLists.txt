set_source_files_properties(
  ../ui/qml/Main.qml
  PROPERTIES QT_RESOURCE_ALIAS Main.qml
)

set_source_files_properties(
  ../ui/assets/icons/app.svg
  PROPERTIES QT_RESOURCE_ALIAS icons/app.svg
)

qt_add_executable(projet_cfr_app
  main.cpp
)

qt_add_qml_module(projet_cfr_app
  URI MyApp
  VERSION 1.0
  QML_FILES
    ../ui/qml/Main.qml
  RESOURCES
    ../ui/assets/icons/app.svg
)

target_link_libraries(projet_cfr_app PRIVATE
  Qt6::Core
  Qt6::Quick
  Qt6::Multimedia
  projet_cfr_core
  projet_cfr_services
)
