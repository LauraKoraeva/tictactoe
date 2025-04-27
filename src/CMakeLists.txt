cmake_minimum_required(VERSION 3.17)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
add_executable(TicTacToe
	main.cpp 
	${MY_INCLUDE_DIR}/Board.h 
	Board.cpp
	${MY_INCLUDE_DIR}/ComputerPlayer.h 
	ComputerPlayer.cpp
	${MY_INCLUDE_DIR}/HumanPlayer.h 
	HumanPlayer.cpp
	${MY_INCLUDE_DIR}/Player.h 
	Player.cpp
	${MY_INCLUDE_DIR}/Game.h 
	Game.cpp 
	${MY_INCLUDE_DIR}/Utility.h 
	Utility.cpp
)
target_include_directories(TicTacToe PUBLIC ${MY_INCLUDE_DIR})