project(AutoTrader)

add_library(ATStrategy
  strategy.cpp
)

add_dependencies(ATStrategy
  ATData
  ATUtils
)
