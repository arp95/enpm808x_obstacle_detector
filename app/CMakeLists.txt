add_executable(shell-app main.cpp Robot.cpp Utils.cpp YOLOv3.cpp)

# Link OpenCV
target_link_libraries( shell-app ${OpenCV_LIBS} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
