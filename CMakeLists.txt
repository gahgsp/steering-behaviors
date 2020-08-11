cmake_minimum_required(VERSION 3.15)
project(ai_steering_behavior)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32")

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(ai_steering_behavior main.cpp src/Application.cpp src/Application.h src/Agent.cpp src/Agent.h src/Utils.cpp src/Utils.h src/SteeringBehavior.cpp src/SteeringBehavior.h src/Seek.cpp src/Seek.h src/Showcase.cpp src/Showcase.h src/SeekBehaviorShowcase.cpp src/SeekBehaviorShowcase.h src/Flee.cpp src/Flee.h src/FleeBehaviorShowcase.cpp src/FleeBehaviorShowcase.h src/Arrive.cpp src/Arrive.h src/ArriveBehaviorShowcase.cpp src/ArriveBehaviorShowcase.h src/Wander.cpp src/Wander.h src/WanderBehaviorShowcase.cpp src/WanderBehaviorShowcase.h)

target_link_libraries(ai_steering_behavior SDL2main SDL2)