cmake_minimum_required(VERSION 3.20)
project(shad_algorithms_part_2)


function(add_all_subdirectories)
    file(GLOB V_GLOB LIST_DIRECTORIES true "*")
    foreach(item ${V_GLOB})
        if(IS_DIRECTORY ${item})
            add_subdirectory(${item})
        endif()
    endforeach()
endfunction()


add_all_subdirectories()
