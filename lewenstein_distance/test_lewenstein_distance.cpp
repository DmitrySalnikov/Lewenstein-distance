#include "lewenstein_distance.h"
#include <gtest/gtest.h>

TEST(lewenstein_distance, Simple) {
	EXPECT_EQ(2, lewenstein_distance("abc", "bce"));
	EXPECT_EQ(3, lewenstein_distance("babc", "bce"));
	EXPECT_EQ(4, lewenstein_distance("beabc", "bce"));
	EXPECT_EQ(3, lewenstein_distance("adf", "bce"));
	EXPECT_EQ(2, lewenstein_distance("mama", "papa"));
	EXPECT_EQ(4, lewenstein_distance("bce", "beabc"));
	EXPECT_EQ(5, lewenstein_distance("qwert", ""));
	EXPECT_EQ(5, lewenstein_distance("", "qwert"));
	EXPECT_EQ(0, lewenstein_distance("", ""));
	EXPECT_EQ(0, lewenstein_distance("qwert", "qwert"));
}
