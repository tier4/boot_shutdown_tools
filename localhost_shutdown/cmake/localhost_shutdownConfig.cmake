# prevent multiple inclusion
if(_localhost_shutdown_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED localhost_shutdown_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(localhost_shutdown_FOUND FALSE)
  elseif(NOT localhost_shutdown_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(localhost_shutdown_FOUND FALSE)
  endif()
  return()
endif()
set(_localhost_shutdown_CONFIG_INCLUDED TRUE)

# include all config extra files
set(_extras "export_localhost_shutdownExport.cmake")
foreach(_extra ${_extras})
  include("${localhost_shutdown_DIR}/${_extra}")
endforeach()
