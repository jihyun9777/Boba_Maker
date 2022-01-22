cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME sfml_project)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp EventHandler.h States.h Snapshot.h GUI.h History.h TextInput.h SnapshotInterface.h TextInput.cpp Cursor.h Cursor.cpp MouseEvents.h TextBox.h States.cpp Fonts.h Label.h Stack.h DNode.h DList.h Typing.cpp Typing.h Shortcuts.h ColorText.cpp ColorText.h History.cpp Item.cpp Item.h ItemList.cpp ItemList.h InputBox.cpp InputBox.h DropdownMenu.cpp DropdownMenu.h MultiText.cpp MultiText.h Menubar.cpp Menubar.h Fonts.cpp Label.cpp TextBox.cpp Menu.cpp Menu.h RectBox.cpp RectBox.h FileItem.cpp FileItem.h Image.cpp Image.h FileNode.cpp FileNode.h FileTree.cpp FileTree.h DrinkMain.cpp DrinkMain.h LogIn.cpp LogIn.h Customer.cpp Customer.h Option.cpp Option.h Favorite.cpp Favorite.h Payment.cpp Payment.h DrinkTree.cpp DrinkTree.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()