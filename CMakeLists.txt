cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(pencerahandatanglahApp LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Core Gui Qml Quick Mqtt)

if (Qt6_VERSION VERSION_GREATER_EQUAL 6.3)
    qt_standard_project_setup()
endif()

qt_add_executable(pencerahandatanglahApp src/main.cpp
    qmlmqttclient.h qmlmqttclient.cpp)

qt_add_resources(pencerahandatanglahApp "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf
)

set_property(TARGET pencerahandatanglahApp PROPERTY QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set_property(TARGET pencerahandatanglahApp PROPERTY QML_IMPORT_RESOURCE_FILES "qmlmqttclient.qml")

target_link_libraries(pencerahandatanglahApp PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Mqtt
)

if (BUILD_QDS_COMPONENTS)
    include(${CMAKE_CURRENT_SOURCE_DIR}/qmlcomponents)
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/qmlmodules)

if (LINK_INSIGHT)
    include(${CMAKE_CURRENT_SOURCE_DIR}/insight)
endif ()

include(GNUInstallDirs)
install(TARGETS pencerahandatanglahApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

set(QML_IMPORT_PATH ${PROJECT_BINARY_DIR}/qml CACHE PATH
    "Path to the custom QML components defined by the project")
