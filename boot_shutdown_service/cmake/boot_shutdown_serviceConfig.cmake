# prevent multiple inclusion
if(_boot_shutdown_service_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED boot_shutdown_service_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(boot_shutdown_service_FOUND FALSE)
  elseif(NOT boot_shutdown_service_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(boot_shutdown_service_FOUND FALSE)
  endif()
  return()
endif()
set(_boot_shutdown_service_CONFIG_INCLUDED TRUE)

# include all config extra files
set(_extras "export_boot_shutdown_serviceExport.cmake")
foreach(_extra ${_extras})
  include("${boot_shutdown_service_DIR}/${_extra}")
endforeach()
