project(AutoTrader)

add_library(ATData
  bitmex_data.cpp
)

add_dependencies(ATData
  ATUtils
)

target_link_libraries(ATData
  ATUtils
)
