file(REMOVE_RECURSE
  "bin/lib/libECSess_static.pdb"
  "bin/lib/libECSess_static.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/ECSess_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
