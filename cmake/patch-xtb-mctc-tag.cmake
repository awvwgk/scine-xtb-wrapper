get_filename_component(cwd "." ABSOLUTE)
set(target_file "${cwd}/cmake/modules/xtb-utils.cmake")
if(NOT EXISTS "${target_file}")
  message(FATAL_ERROR "expected file not found: ${target_file}")
endif()

file(READ "${target_file}" contents)

if(contents MATCHES "_git_tag")
  message(STATUS "xtb-utils.cmake already patched, skipping")
else()
  string(REPLACE
    "FetchContent_Declare("
    "if(\${url} MATCHES \"mctc\")\n        set(_git_tag \"v0.5.1\")\n      else()\n        set(_git_tag \"HEAD\")\n      endif()\n      FetchContent_Declare("
    contents "${contents}")

  string(REPLACE
    "GIT_TAG \"HEAD\""
    "GIT_TAG \"\${_git_tag}\""
    contents "${contents}")

  file(WRITE "${target_file}" "${contents}")
endif()
