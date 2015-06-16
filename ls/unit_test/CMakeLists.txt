set(GMOCK_DIR "../thirdpart/gmock-1.7.0" CHACHE PATH
    "The path to the GoogleMock test framework.")

include_directories(SYSTEM ${GMOCK_DIR}/gtest/include
                           ${GMOCK_DIR}/include)