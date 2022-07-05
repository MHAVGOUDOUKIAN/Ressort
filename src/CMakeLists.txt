cmake_minimum_required(VERSION 3.0)

#Set a normal variable to a given value
set(PROJECT_NAME $ENV{TITLE})
project(${PROJECT_NAME})

# Very important, otherwise your executable will be considered as a shared library by your OS and no as an executable
set (CMAKE_CXX_FLAGS "-no-pie")

set(PERMISSIONS OWNER_READ 
    OWNER_WRITE 
    OWNER_EXECUTE 
    GROUP_READ 
    GROUP_WRITE 
    GROUP_EXECUTE 
    WORLD_READ 
    WORLD_WRITE 
    WORLD_EXECUTE
)

include_directories(${PROJECT_SOURCE_DIR})

# Select the sources files to use in the current directory
set( SOURCES
    main.cpp

    Engine/Engine.cpp
    Engine/EventHandler.cpp
    Engine/TimeManager.cpp
    Engine/Network.cpp
    Engine/GUIConsole.cpp
    Engine/GUILogger.cpp

    Application/App.cpp
    Application/Masse.cpp
    Application/Support.cpp
    Application/Spring.cpp
    Application/Resolver.cpp
)

# //   headers file //
set( HEADERS
    Engine/Engine.hpp
    Engine/EventHandler.hpp
    Engine/TimeManager.hpp
    Engine/Observer.hpp
    Engine/Network.hpp
    Engine/GUIConsole.hpp
    Engine/GUILogger.hpp

    Application/App.hpp
    Application/Masse.hpp
    Application/Support.hpp
    Application/Spring.hpp
    Application/utils.hpp
    Application/Resolver.hpp
)

add_executable(${PROJECT_NAME} # Name of the executable
    ${SOURCES}
    ${HEADERS})
    
target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system 
    sfml-audio
    sfml-network
    pthread
)

install(FILES ${PROJECT_NAME}  DESTINATION ${PROJECT_SOURCE_DIR}/.. PERMISSIONS ${PERMISSIONS} )
