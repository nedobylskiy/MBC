# Install script for directory: C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/bindings/c

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/libtag_c.dll.a")
FILE(INSTALL DESTINATION "/usr/local/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/bindings/c/libtag_c.dll.a")
  IF(EXISTS "$ENV{DESTDIR}/usr/local/lib/libtag_c.dll.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/lib/libtag_c.dll.a")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "C:/Dev-Cpp/bin/strip.exe" "$ENV{DESTDIR}/usr/local/lib/libtag_c.dll.a")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/local/bin/libtag_c.dll")
FILE(INSTALL DESTINATION "/usr/local/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/bindings/c/libtag_c.dll")
  IF(EXISTS "$ENV{DESTDIR}/usr/local/bin/libtag_c.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/bin/libtag_c.dll")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "C:/Dev-Cpp/bin/strip.exe" "$ENV{DESTDIR}/usr/local/bin/libtag_c.dll")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/local/lib/pkgconfig/taglib_c.pc")
FILE(INSTALL DESTINATION "/usr/local/lib/pkgconfig" TYPE FILE FILES "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/bindings/c/taglib_c.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/taglib/tag_c.h")
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/bindings/c/tag_c.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

