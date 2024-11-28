# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("Homework_17")

set(INCLUDE
	"inc/main.h"
)

set(SRC
	"src/main.cpp"
)

add_executable (Homework_17
	${INCLUDE} 
	${SRC}
 )

target_include_directories(Homework_17
        PUBLIC
        ./inc
        ./src
)
