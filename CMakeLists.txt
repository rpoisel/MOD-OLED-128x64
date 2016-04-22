file(GLOB OLED_LIB_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
)

add_library(esp8266oled STATIC
    ${OLED_LIB_SRC}
)

target_include_directories(esp8266oled PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src
)

target_link_libraries(esp8266oled PUBLIC
    arduino
    esp8266wire
)




