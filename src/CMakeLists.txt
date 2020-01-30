project(AutoTrader)

set(EXECUTABLE_OUTPUT_PATH ${AT_APPLICATION_PATH})
set(LIBRARY_OUTPUT_PATH ${AT_LIBRARY_PATH})

add_subdirectory(data)
add_subdirectory(order)
add_subdirectory(pricing)
add_subdirectory(simulator)
add_subdirectory(strategy)
add_subdirectory(utils)