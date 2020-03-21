set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES ulamspiral.cpp main.cpp)
 
add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

if (USE_DEBUG)
  add_definitions(-DDEBUG)
endif()