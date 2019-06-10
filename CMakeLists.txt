cmake_minimum_required(VERSION 3.10.2)
project(extractors)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wextra -Wno-unused-function -Wno-unused-variable") # -Werror
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native")

find_library(NTL_LIB ntl REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

add_library(extractors
        utils/Bitstring.h
        extractor/seeded/ISeededExtractor.h
        extractor/condenser/ICondenser.h
        expander/bipartite/IBipartiteExpander.h
        utils/types.h
        extractor/condenser/ExpanderCondenser.cpp
        extractor/condenser/ExpanderCondenser.h
        utils/WeakSource.cpp
        utils/WeakSource.h
        extractor/seeded/BlockSourceExtractorComposition.cpp
        extractor/seeded/BlockSourceExtractorComposition.h
        extractor/seeded/LHLExtractor.cpp
        extractor/seeded/LHLExtractor.h
        utils/Bitstring.cpp
        expander/bipartite/PVExpander.cpp
        expander/bipartite/PVExpander.h
        expander/spectral/ISpectralExpander.h
        expander/spectral/MargulisExpander.cpp
        expander/spectral/MargulisExpander.h
        extractor/seeded/InflateOutputComposition.cpp
        extractor/seeded/InflateOutputComposition.h)
target_link_libraries(extractors ntl)
