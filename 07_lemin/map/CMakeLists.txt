cmake_minimum_required(VERSION 3.13)
project(lem_in C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Werror -Wextra")

include_directories(./include/ ./libft/)

file(GLOB LIBFT libft/*.c libft/*.h libft/ft_printf/*.c libft/ft_printf/*.h)

add_executable(lem_in ${LIBFT} ./src/main.c src/scan_param.c src/val_param.c src/ft_struct.c src/func_for_val.c src/func_for_val_p2.c src/step_2.c src/step_3.c src/sort_list.c src/alg_lem.c src/struct_for_queue.c src/ft_queue.c)