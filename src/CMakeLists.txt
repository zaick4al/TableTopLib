include(src/Objects/CMakeLists.txt)

set(SOURCES_INCLUDES
    ${SOURCES_PATH}/tabletopobject.h ${SOURCES_PATH}/tabletopobject.cpp
    ${SOURCES_PATH}/TableTopLib_global.h
    ${INCLUDE_LIBOBJECTS}
    src/libcontrol.h src/libcontrol.cpp
)
