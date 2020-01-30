project(AutoTrader)

add_library(ATStrategy
  template.cpp
)

add_dependencies(ATStrategy
  ATData
  ATOrder
  ATUtils
)