#include "PixelArtify/image_processor.h"
#include <iostream>
#include <numeric>
#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

namespace pixel_artify {

bool ImageProcessor::process_image_from_file(const std::string& input_path, const std::string& output_path, int block_size, bool apply_grayscale) {
    int width, height, channels;

    unsigned char *data = stbi_load(input_path.c_str(), &width, &height, &channels, 0);
    if (!data) {
        std::cerr << "Error: Could not load image from path: " << input_path << std::endl;
        return false;
    }

    std::vector<unsigned char> image_data(data, data + width * height * channels);
    stbi_image_free(data);

    if (apply_grayscale) {
        image_data = convert_to_grayscale(image_data, width, height, channels);
        channels = 1;
    }

    std::vector<unsigned char> output_data = pixelate(image_data, width, height, channels, block_size);

    std::string ext = output_path.substr(output_path.find_last_of(".") + 1);
    int success = 0;
    if (ext == "png") {
        success = stbi_write_png(output_path.c_str(), width, height, channels, output_data.data(), width * channels);
    } else if (ext == "jpg" || ext == "jpeg") {
        success = stbi_write_jpg(output_path.c_str(), width, height, channels, output_data.data(), 90);
    } else if (ext == "bmp") {
        success = stbi_write_bmp(output_path.c_str(), width, height, channels, output_data.data());
    } else {
        std::cerr << "Error: Unsupported output file format: " << ext << std::endl;
        return false;
    }

    if (!success) {
        std::cerr << "Error: Could not save image to path: " << output_path << std::endl;
        return false;
    }

    return true;
}

std::vector<unsigned char> ImageProcessor::pixelate(const std::vector<unsigned char>& image_data, int width, int height, int channels, int block_size) {
    std::vector<unsigned char> output_data(width * height * channels);

    for (int y = 0; y < height; y += block_size) {
        for (int x = 0; x < width; x += block_size) {
            int x_end = std::min(x + block_size, width);
            int y_end = std::min(y + block_size, height);
            
            std::vector<long long> avg_color(channels, 0);
            int pixel_count = 0;

            for (int by = y; by < y_end; ++by) {
                for (int bx = x; bx < x_end; ++bx) {
                    for (int c = 0; c < channels; ++c) {
                        avg_color[c] += image_data[(by * width + bx) * channels + c];
                    }
                    pixel_count++;
                }
            }

            if (pixel_count > 0) {
                for (int c = 0; c < channels; ++c) {
                    avg_color[c] /= pixel_count;
                }
            }

            for (int by = y; by < y_end; ++by) {
                for (int bx = x; bx < x_end; ++bx) {
                    for (int c = 0; c < channels; ++c) {
                        output_data[(by * width + bx) * channels + c] = static_cast<unsigned char>(avg_color[c]);
                    }
                }
            }
        }
    }
    return output_data;
}

std::vector<unsigned char> ImageProcessor::convert_to_grayscale(const std::vector<unsigned char>& image_data, int width, int height, int channels) {
    if (channels == 1) return image_data;

    std::vector<unsigned char> gray_data(width * height);
    for (int i = 0; i < width * height; ++i) {
        int r = image_data[i * channels + 0];
        int g = image_data[i * channels + 1];
        int b = image_data[i * channels + 2];
        gray_data[i] = static_cast<unsigned char>(0.21 * r + 0.72 * g + 0.07 * b);
    }
    return gray_data;
}

} // namespace pixel_artify
