#include <gtest/gtest.h>
#include "../headers/Point2D.hpp"

TEST(Point2D, Constructor) {
    {
        SCOPED_TRACE("Testing default constructor");
        Point2D<int> p1;
        EXPECT_EQ(p1.getX(), 0);
        EXPECT_EQ(p1.getY(), 0);
    }

    {
        SCOPED_TRACE("Testing parameterized constructor");
        Point2D<int> p2(1, 2);
        EXPECT_EQ(p2.getX(), 1);
        EXPECT_EQ(p2.getY(), 2);
    }

    {
        SCOPED_TRACE("Testing copy constructor");
        Point2D<int> p3(Point2D<int>(3, 4));
        EXPECT_EQ(p3.getX(), 3);
        EXPECT_EQ(p3.getY(), 4);
    }
}

TEST(Point2D, Setters) {
    Point2D<int> p;
    p.setX(1);
    p.setY(2);
    EXPECT_EQ(p.getX(), 1);
    EXPECT_EQ(p.getY(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




