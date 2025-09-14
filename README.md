# PixelArtify

[![CI](https://github.com/firrthecreator/PixelArtify/actions/workflows/ci.yml/badge.svg)](https://github.com/firrthecreator/PixelArtify/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

A simple, fast, and modern C++ command-line tool to convert any image into beautiful pixel art.

## Features

- **High Performance**: Built with modern C++ for fast image processing.
- **Customizable Pixel Size**: Control the level of detail in your pixel art.
- **Multiple Output Formats**: Supports PNG, JPG, BMP, and TGA output.
- **Grayscale Mode**: Easily convert images to grayscale pixel art.
- **Self-Contained Dependencies**: Uses header-only libraries stored in the `third_party/` directory for easy building.

---

## Prerequisites

- A C++17 compatible compiler (e.g., GCC, Clang, MSVC).
- CMake (version 3.16 or higher).
- Git.

---

## Setup & Building

This project includes its dependencies directly in the `third_party/` directory.

### 1. Clone the repository

```bash
git clone https://github.com/firrthecreator/PixelArtify.git
cd PixelArtify
```

### 2. Download Dependencies

Place the following header-only libraries into the `third_party/` folder:

- `cxxopts.hpp`: https://github.com/jarro2783/cxxopts
- `stb_image.h`: https://github.com/nothings/stb
- `stb_image_write.h`: https://github.com/nothings/stb

Or run this script:

```bash
mkdir -p third_party
curl -o third_party/cxxopts.hpp https://raw.githubusercontent.com/jarro2783/cxxopts/master/include/cxxopts.hpp
curl -o third_party/stb_image.h https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
curl -o third_party/stb_image_write.h https://raw.githubusercontent.com/nothings/stb/master/stb_image_write.h
```

### 3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

The executable `pixel_artify` will be created in the `build/` directory.

---

## Quick Start

```bash
./pixel_artify -i input.jpg -o output.png -s 16
```

See `USAGE.txt` for a complete guide and examples.

---

## Running Tests

```bash
# From the 'build' directory
ctest
```

---

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).
