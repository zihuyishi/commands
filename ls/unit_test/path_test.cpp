//
// Created by 李冲 on 15/6/17.
//
#include "../pathCore/Path.h"
#include <gtest/gtest.h>
namespace {
    using namespace cmd::sys;
    class PathTest : public ::testing::Test {
    protected:
        PathTest() {
            _path1 = Path("/usr/local/include/saye.cxx", false);
            _path2 = Path("../a", false);
            _path3 = Path("c:\\saye", true);
            _path4 = Path("d:\\kaka\\asdf.exe", false);
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
        Path _path3;
        Path _path4;
    };

    TEST_F(PathTest, PathGetterAndSetter) {
        Path path1;
        path1.setPath("nihaola");
        EXPECT_EQ(std::string("nihaola"), path1.getPath());
    }

    TEST_F(PathTest, GetDirectoryTest) {
        EXPECT_EQ(std::string("/usr/local/include"), _path1.getDirectory());
        EXPECT_EQ(std::string(".."), _path2.getDirectory());
        EXPECT_EQ(std::string("c:"), _path3.getDirectory());
        EXPECT_EQ(std::string("d:\\kaka"), _path4.getDirectory());
    }

    TEST_F(PathTest, GetFilenameTest) {
        EXPECT_EQ(std::string("saye.cxx"), _path1.getFilename());
        EXPECT_EQ(std::string("a"), _path2.getFilename());
        EXPECT_EQ(std::string("saye"), _path3.getFilename());
        EXPECT_EQ(std::string("asdf.exe"), _path4.getFilename());
    }

    TEST_F(PathTest, OperateTest) {
        Path path1 = _path1;
        Path path2 = _path2;
        EXPECT_EQ(path1, _path1);
        EXPECT_EQ(path2, _path2);
    }

}