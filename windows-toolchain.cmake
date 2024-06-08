# windows-toolchain.cmake

# Specify the cross compiler
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 1)

# Specify the cross compiler
set(CMAKE_C_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/x86_64-w64-mingw32-g++)
set(CMAKE_AR /opt/homebrew/bin/x86_64-w64-mingw32-ar)
set(CMAKE_RANLIB /opt/homebrew/bin/x86_64-w64-mingw32-ranlib)

# Specify the target environment
set(CMAKE_FIND_ROOT_PATH /opt/homebrew/opt/mingw-w64/toolchain-x86_64 /opt/homebrew/x86_64-w64-mingw32 /opt/raylib-windows)

# Search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# For libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(raylib_DIR /opt/raylib-windows/cmake)
