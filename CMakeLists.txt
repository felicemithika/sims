cmake_minimum_required(VERSION 3.21)

project(SIMS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load qt6
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

# Find Python
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Enable automatic qt handling 
set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Collect all .ui files
file(GLOB UI_FILES "ui_files/*.ui")

# Generate headers for all UI files
qt6_wrap_ui(GENERATED_UI_HEADERS ${UI_FILES})

# automatically generate a ui_all.h files
set(WRAPPER_HEADER "${CMAKE_CURRENT_BINARY_DIR}/ui_all.h")
file(WRITE ${WRAPPER_HEADER} "// Auto-generated wrapper header\n\n")

foreach(ui_header ${GENERATED_UI_HEADERS})
  # Get only the file name (without path)
  get_filename_component(header_name ${ui_header} NAME)
  file(APPEND ${WRAPPER_HEADER} "#include \"${header_name}\"\n")
endforeach()

# Collect .cpp sources
file(GLOB CPP_SOURCES "cpp/*.cpp")

#QRC resources
file(GLOB RESOURCE_FILES "resources/*.qrc")

# Add executable
add_executable(${PROJECT_NAME}
  ${CPP_SOURCES}
  ${GENERATED_UI_HEADERS}
  ${WRAPPER_HEADER}
  ${RESOURCE_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Link Qt
target_link_libraries(${PROJECT_NAME}  Qt6::Widgets Qt6::Sql)

# Copy Python script to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/python/barcode_generator.py
    ${CMAKE_CURRENT_BINARY_DIR}/python/barcode_generator.py
)