# Install script for directory: C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames

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
   "/usr/local/include/taglib/attachedpictureframe.h;/usr/local/include/taglib/commentsframe.h;/usr/local/include/taglib/generalencapsulatedobjectframe.h;/usr/local/include/taglib/popularimeterframe.h;/usr/local/include/taglib/privateframe.h;/usr/local/include/taglib/relativevolumeframe.h;/usr/local/include/taglib/textidentificationframe.h;/usr/local/include/taglib/uniquefileidentifierframe.h;/usr/local/include/taglib/unknownframe.h;/usr/local/include/taglib/unsynchronizedlyricsframe.h;/usr/local/include/taglib/urllinkframe.h")
FILE(INSTALL DESTINATION "/usr/local/include/taglib" TYPE FILE FILES
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/attachedpictureframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/commentsframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/popularimeterframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/privateframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/relativevolumeframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/textidentificationframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/unknownframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h"
    "C:/Users/Admin/Documents/IceCast/MBCS2.0/taglib-1.7.2/taglib-1.7.2/taglib/mpeg/id3v2/frames/urllinkframe.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

