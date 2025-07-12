set(_lib_bitmap ${CMAKE_CURRENT_LIST_DIR}/bitmap.cpp)
set(_lib_textrenderer ${CMAKE_CURRENT_LIST_DIR}/text_renderer.cpp)

add_library(TextToBitmapLib SHARED ${_lib_bitmap} ${_lib_textrenderer})
target_include_directories(TextToBitmapLib PUBLIC ${CMAKE_SOURCE_DIR}/include)