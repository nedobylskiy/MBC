# Install script for directory: C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4

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
   "/usr/local/include/taglib/mp4file.h;/usr/local/include/taglib/mp4atom.h;/usr/local/include/taglib/mp4tag.h;/usr/local/include/taglib/mp4item.h;/usr/local/include/taglib/mp4properties.h;/usr/local/include/taglib/mp4coverart.h")
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4/mp4file.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4/mp4atom.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4/mp4tag.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4/mp4item.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4/mp4properties.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mp4/mp4coverart.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

