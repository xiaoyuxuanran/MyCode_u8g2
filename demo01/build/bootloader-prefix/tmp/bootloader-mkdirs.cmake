# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Espressif/frameworks/esp-idf-v5.1.2/components/bootloader/subproject"
  "E:/U8G2/demo01/build/bootloader"
  "E:/U8G2/demo01/build/bootloader-prefix"
  "E:/U8G2/demo01/build/bootloader-prefix/tmp"
  "E:/U8G2/demo01/build/bootloader-prefix/src/bootloader-stamp"
  "E:/U8G2/demo01/build/bootloader-prefix/src"
  "E:/U8G2/demo01/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/U8G2/demo01/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/U8G2/demo01/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
