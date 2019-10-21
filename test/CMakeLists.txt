set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    MockUtils.cpp
    MockYOLOv3.cpp
    MockRobot.cpp
    ${CMAKE_SOURCE_DIR}/app/YOLOv3.cpp
    ${CMAKE_SOURCE_DIR}/app/Utils.cpp
    ${CMAKE_SOURCE_DIR}/app/Robot.cpp
    ${OpenCV_INCLUDE_DIRS}
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
