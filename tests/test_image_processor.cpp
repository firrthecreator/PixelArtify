#include "gtest/gtest.h"
#include "PixelArtify/image_processor.h"
#include <vector>

class ImageProcessorTest : public ::testing::Test {
protected:
    pixel_artify::ImageProcessor processor;
};

TEST_F(ImageProcessorTest, BasicPixelation) {
    const int width = 2, height = 2, channels = 3, block_size = 2;
    std::vector<unsigned char> input_data = {
        255, 0,   0,
        0,   255, 0,
        0,   0,   255,
        255, 255, 255
    };
    std::vector<unsigned char> expected_data = {
        127, 127, 127,
        127, 127, 127,
        127, 127, 127,
        127, 127, 127
    };
    auto result_data = processor.pixelate(input_data, width, height, channels, block_size);
    ASSERT_EQ(result_data.size(), expected_data.size());
    EXPECT_EQ(result_data, expected_data);
}

TEST_F(ImageProcessorTest, GrayscaleConversion) {
    const int width = 2, height = 1, channels = 3;
    std::vector<unsigned char> input_data = {
        255, 0, 0,
        0, 255, 0
    };
    std::vector<unsigned char> expected_data = {53, 183};
    auto result_data = processor.convert_to_grayscale(input_data, width, height, channels);
    ASSERT_EQ(result_data.size(), expected_data.size());
    EXPECT_EQ(result_data, expected_data);
}
