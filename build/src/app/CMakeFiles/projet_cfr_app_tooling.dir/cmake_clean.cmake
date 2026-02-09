file(REMOVE_RECURSE
  "MyApp/Main.qml"
  "MyApp/icons/app.svg"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/projet_cfr_app_tooling.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
