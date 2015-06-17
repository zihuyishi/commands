//
// Created by 李冲 on 15/6/17.
//
#include "../pathCore/Path.h"
#include <gtest/gtest.h>
namespace {
    using namespace cmd;
    class PathTest : public ::testing::Test {
    protected:
        PathTest() {
            _path1 = Path("/usr/local/include/saye.cxx");
            _path2 = Path("../a");
        }
        virtual ~PathTest() {

        }

        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
        Path _path1;
        Path _path2;
    };

    TEST_F(PathTest, PathGetterAndSetter) {
        Path path1;
        path1.setPath("nihaola");
        EXPECT_EQ(std::string("nihaola"), path1.getPath());
    }

    TEST_F(PathTest, GetDirectoryTest) {
        EXPECT_EQ(std::string("/usr/local/include"), _path1.getDirectory());
        EXPECT_EQ(std::string(".."), _path2.getDirectory());
    }

    TEST_F(PathTest, GetFilenameTest) {
        EXPECT_EQ(std::string("saye.cxx"), _path1.getFilename());
        EXPECT_EQ(std::string("a"), _path2.getFilename());
    }

}