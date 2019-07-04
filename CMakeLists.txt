include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src

)

set(SRC_LIST
#src
	${PROJECT_SOURCE_DIR}/src/common.cpp
	${PROJECT_SOURCE_DIR}/src/filter-words.cpp
	${PROJECT_SOURCE_DIR}/src/main.cpp
	${PROJECT_SOURCE_DIR}/src/stdafx.cpp
	${PROJECT_SOURCE_DIR}/src/tire-tree.cpp
	${PROJECT_SOURCE_DIR}/src/tree-node.cpp
	)

add_executable(CFILTER ${SRC_LIST})


set_target_properties(CFILTER PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ".."
)

