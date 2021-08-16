cmake_minimum_required(VERSION 3.19)
project(lobo_brain)

set(CMAKE_CXX_STANDARD 14)

include_directories(reinforcement-learning/alinhamento)
include_directories(src)
include_directories(src/Games)
include_directories(src/LoBoBrain)
include_directories(src/MiniMax)

add_executable(lobo_brain
        reinforcement-learning/alinhamento/Agent.cpp
        reinforcement-learning/alinhamento/Agent.hpp
        reinforcement-learning/alinhamento/Global.cpp
        reinforcement-learning/alinhamento/Global.hpp
        reinforcement-learning/alinhamento/State.cpp
        reinforcement-learning/alinhamento/State.hpp
        reinforcement-learning/alinhamento/test.cpp
        reinforcement-learning/alinhamento/test_play.cpp
        reinforcement-learning/alinhamento/test_train.cpp
        src/Games/tapatan.cpp
        src/Games/tapatan.hpp
        src/LoBoBrain/board.cpp
        src/LoBoBrain/board.hpp
        src/LoBoBrain/player.cpp
        src/LoBoBrain/player.hpp
        src/MiniMax/minimaxNode.cpp
        src/MiniMax/minimaxNode.hpp
        src/MiniMax/minimaxTree.cpp
        src/MiniMax/minimaxTree.hpp
        src/LoBoBrain.cpp
        src/LoBoBrain.hpp
        src/MiniMax.cpp
        src/MiniMax.hpp)
