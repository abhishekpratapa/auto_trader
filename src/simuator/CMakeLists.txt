project(AutoTrader)

add_library(ATSimulator
  simulator.cpp
)

add_dependencies(ATSimulator
  ATData
  ATStrategy
  ATUtils
)
