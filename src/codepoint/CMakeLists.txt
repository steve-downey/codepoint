add_library(codepoint STATIC "")

target_sources(
  codepoint
  PRIVATE
  codepoint.cpp)

include(GNUInstallDirs)

target_include_directories(codepoint PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_LOWER_PROJECT_NAME}>  # <prefix>/include/codepoint
  )

target_link_libraries(codepoint stl2)

install(
  TARGETS codepoint
  EXPORT ${TARGETS_EXPORT_NAME}
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

string(TOLOWER ${CMAKE_PROJECT_NAME} CMAKE_LOWER_PROJECT_NAME)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_LOWER_PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h"
  )


## Tests
add_executable(codepoint_test "")

target_sources(
  codepoint_test
  PRIVATE
  codepoint.t.cpp)

target_link_libraries(codepoint_test codepoint)
target_link_libraries(codepoint_test gtest)
target_link_libraries(codepoint_test gtest_main)

include(GoogleTest)
gtest_discover_tests(codepoint_test)
