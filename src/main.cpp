#include <iostream>
#include <string>
#include "cxxopts.hpp"
#include "PixelArtify/image_processor.h"

int main(int argc, char** argv) {
    cxxopts::Options options("PixelArtify", "A C++ tool to convert images into pixel art.");

    options.add_options()
        ("i,input", "Input image file path", cxxopts::value<std::string>())
        ("o,output", "Output image file path", cxxopts::value<std::string>())
        ("s,size", "Pixel block size (e.g., 10)", cxxopts::value<int>()->default_value("10"))
        ("g,grayscale", "Convert to grayscale", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage");

    try {
        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            return 0;
        }

        if (!result.count("input") || !result.count("output")) {
            std::cerr << "Error: Input and output file paths are required." << std::endl;
            std::cerr << options.help() << std::endl;
            return 1;
        }
        
        const std::string input_path = result["input"].as<std::string>();
        const std::string output_path = result["output"].as<std::string>();
        const int block_size = result["size"].as<int>();
        const bool grayscale = result["grayscale"].as<bool>();
        
        if (block_size <= 0) {
            std::cerr << "Error: Block size must be a positive integer." << std::endl;
            return 1;
        }

        pixel_artify::ImageProcessor processor;
        if (processor.process_image_from_file(input_path, output_path, block_size, grayscale)) {
            std::cout << "Successfully created pixel art: " << output_path << std::endl;
        } else {
            std::cerr << "An error occurred during image processing." << std::endl;
            return 1;
        }

    } catch (const cxxopts::exceptions::exception& e) {
        std::cerr << "Error parsing options: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
