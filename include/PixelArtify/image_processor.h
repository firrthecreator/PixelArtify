#ifndef PIXEL_ARTIFY_IMAGE_PROCESSOR_H
#define PIXEL_ARTIFY_IMAGE_PROCESSOR_H

#include <string>
#include <vector>

namespace pixel_artify {

class ImageProcessor {
public:
    bool process_image_from_file(const std::string& input_path, const std::string& output_path, int block_size, bool grayscale);
    std::vector<unsigned char> pixelate(const std::vector<unsigned char>& image_data, int width, int height, int channels, int block_size);
    std::vector<unsigned char> convert_to_grayscale(const std::vector<unsigned char>& image_data, int width, int height, int channels);
};

} // namespace pixel_artify

#endif // PIXEL_ARTIFY_IMAGE_PROCESSOR_H
