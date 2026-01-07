# PixelArtify

<div align="center">

[![CI/CD Pipeline](https://github.com/firrthecreator/PixelArtify/actions/workflows/ci.yml/badge.svg)](https://github.com/firrthecreator/PixelArtify/actions/workflows/ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![C++ Standard](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![CMake](https://img.shields.io/badge/CMake-3.16+-blue.svg)](https://cmake.org/)

**Transform your images into stunning pixel art with blazing-fast performance**

[Features](#-features) • [Quick Start](#-quick-start) • [Installation](#-installation) • [Usage](#-usage) • [Contributing](#-contributing)

</div>

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Prerequisites](#-prerequisites)
- [Installation](#-installation)
- [Quick Start](#-quick-start)
- [Usage](#-usage)
- [Architecture](#-architecture)
- [Contributing](#-contributing)
- [Performance](#-performance)
- [FAQ](#-faq)
- [License](#-license)

---

## 🎨 Overview

**PixelArtify** is a high-performance, production-ready C++ command-line tool designed to convert any image into beautiful, customizable pixel art. Built with modern C++ (C++17), it combines speed, flexibility, and ease of use to deliver professional-quality results.

Whether you're a digital artist, game developer, or hobbyist, PixelArtify provides the tools you need to create pixel art from your photos with precision and control.

### Why PixelArtify?

- ⚡ **Lightning Fast**: Optimized C++ implementation for rapid image processing
- 🎯 **Production Ready**: Battle-tested, thoroughly tested codebase
- 🛠️ **Zero Dependencies**: Header-only libraries included in the project
- 📦 **Easy Distribution**: No external runtime dependencies required
- 🎮 **Developer Friendly**: Clean, well-documented API and CLI interface

---

## ✨ Features

| Feature | Description |
|---------|-------------|
| **High Performance** | Built with modern C++17 for blazing-fast image processing |
| **Customizable Pixel Size** | Fine-grained control over the level of pixelation (block size from 1 to 256 pixels) |
| **Multiple Output Formats** | Supports PNG, JPG, BMP, and TGA formats |
| **Grayscale Mode** | Convert images to grayscale pixel art with optional color reduction |
| **Batch Processing** | Process multiple images efficiently |
| **Dithering Support** | Optional dithering for improved color representation |
| **Self-Contained** | All dependencies included - no external installations needed |
| **Cross-Platform** | Works on Linux, macOS, and Windows |

---

## 🛠️ Tech Stack

- **Language**: C++17
- **Build System**: CMake 3.16+
- **Testing Framework**: Built-in CTest
- **Dependencies**:
  - [cxxopts](https://github.com/jarro2783/cxxopts) - Command-line argument parsing
  - [stb_image](https://github.com/nothings/stb) - Image loading
  - [stb_image_write](https://github.com/nothings/stb) - Image writing
- **CI/CD**: GitHub Actions

---

## 📋 Prerequisites

Before you begin, ensure you have the following installed:

| Requirement | Version | Notes |
|-------------|---------|-------|
| C++ Compiler | C++17+ | GCC 7+, Clang 5+, or MSVC 2017+ |
| CMake | 3.16+ | [Download](https://cmake.org/download/) |
| Git | Latest | For cloning the repository |
| Make | Latest | For building on Linux/macOS (or use your preferred build tool) |

### Platform-Specific Setup

**Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install build-essential cmake git
```

**macOS:**
```bash
brew install cmake
# Xcode Command Line Tools (if not already installed)
xcode-select --install
```

**Windows:**
- Install [CMake](https://cmake.org/download/)
- Install Visual Studio 2017 or later, or use MinGW-w64

---

## 💾 Installation

### Option 1: Clone and Build from Source (Recommended)

```bash
# Clone the repository
git clone https://github.com/firrthecreator/PixelArtify.git
cd PixelArtify

# Create and enter build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make -j$(nproc)  # Linux/macOS
# or for Windows:
# cmake --build . --config Release

# Optional: Run tests
ctest --output-on-failure
```

The executable `pixel_artify` will be created in the `build/` directory.

### Option 2: Automated Setup Script

```bash
git clone https://github.com/firrthecreator/PixelArtify.git
cd PixelArtify

# Run automated build
./scripts/build.sh  # Linux/macOS
# or
.\scripts\build.bat  # Windows
```

### Option 3: Install to System Path

```bash
cd build
sudo make install  # Linux/macOS
# This installs the binary to /usr/local/bin/pixel_artify
```

---

## 🚀 Quick Start

### Basic Usage

```bash
./pixel_artify -i input.jpg -o output.png -s 16
```

### Common Examples

**Convert with different pixel sizes:**
```bash
# Small pixels (more detail)
./pixel_artify -i photo.jpg -o output.png -s 8

# Large pixels (less detail)
./pixel_artify -i photo.jpg -o output.png -s 32
```

**Grayscale conversion:**
```bash
./pixel_artify -i photo.jpg -o output.png -s 16 -g
```

**Batch processing:**
```bash
for file in *.jpg; do
  ./pixel_artify -i "$file" -o "pixelated_${file%.jpg}.png" -s 16
done
```

---

## 📖 Usage

### Command-Line Options

```
USAGE:
  pixel_artify [OPTION...]

OPTIONS:
  -i, --input FILE         Input image file path (required)
  -o, --output FILE        Output image file path (required)
  -s, --size SIZE          Pixel block size in pixels (default: 16)
  -g, --grayscale          Convert to grayscale
  -d, --dither             Enable dithering for better color representation
  -q, --quality NUM        Output quality for JPG (0-100, default: 95)
  -h, --help               Show help message
  -v, --version            Show version information
```

### Examples with Detailed Options

**High-quality pixelated output:**
```bash
./pixel_artify -i original.png -o artistic.png -s 20
```

**Retro-style grayscale art:**
```bash
./pixel_artify -i photo.jpg -o retro.png -s 32 -g
```

**Fine detail preservation:**
```bash
./pixel_artify -i detailed.jpg -o output.png -s 4 -d
```

For comprehensive documentation, see [USAGE.md](docs/USAGE.md).

---

## 🏗️ Architecture

### Project Structure

```
PixelArtify/
├── CMakeLists.txt           # Build configuration
├── include/
│   └── PixelArtify/
│       └── image_processor.h  # Main processing API
├── src/
│   ├── main.cpp            # CLI entry point
│   └── image_processor.cpp  # Core implementation
├── tests/
│   └── test_image_processor.cpp  # Unit tests
├── third_party/            # Header-only dependencies
│   ├── cxxopts.hpp
│   ├── stb_image.h
│   └── stb_image_write.h
├── docs/
│   └── USAGE.md            # Detailed usage guide
└── build/                  # Build artifacts
```

### Core Components

**ImageProcessor** - Main class handling pixel art conversion
- Loads images in multiple formats (PNG, JPG, BMP, TGA)
- Applies pixelation algorithm with configurable block size
- Supports grayscale conversion
- Exports to multiple output formats with quality control

### Algorithm

The pixelation algorithm works by:
1. Dividing the image into blocks of configurable size
2. Computing the average color of each block
3. Replacing the block with a single color
4. Optional: Applying dithering for smoother color transitions

---

## 🧪 Testing

### Run All Tests

```bash
cd build
ctest --output-on-failure
```

### Run Specific Tests

```bash
ctest -R image_processor --verbose
```

### Test Coverage

```bash
cmake -DCMAKE_BUILD_TYPE=Coverage ..
make
ctest --output-on-failure
# View coverage report in coverage/ directory
```

---

## 🤝 Contributing

We welcome contributions from the community! Please follow these guidelines:

### Getting Started

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Development Guidelines

- Follow the [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines)
- Use clang-format for code formatting: `clang-format -i src/*.cpp`
- Ensure all tests pass: `ctest`
- Add tests for new features
- Update documentation as needed

### Code Style

- Use 4-space indentation
- Use meaningful variable names
- Add comments for complex logic
- Keep functions small and focused

### Pull Request Process

1. Update the README.md with details of changes if applicable
2. Update CHANGELOG.md with notes on your changes
3. Ensure the test suite passes
4. Request review from maintainers

---

## 📊 Performance

### Benchmarks

Typical processing times (on Intel i7-9700K, 8GB RAM):

| Image Size | Pixel Size | Time (Grayscale) | Time (Color) |
|-----------|-----------|------------------|------------|
| 1920x1080 | 16        | ~45ms           | ~52ms      |
| 4096x2160 | 32        | ~120ms          | ~140ms     |
| 8192x4320 | 64        | ~280ms          | ~320ms     |

*Benchmarks are approximate and may vary based on hardware and image complexity.*

---

## ❓ FAQ

<details>
<summary><b>What formats does PixelArtify support?</b></summary>

PixelArtify can read: PNG, JPG, BMP, TGA
PixelArtify can write: PNG, JPG, BMP, TGA

</details>

<details>
<summary><b>What's the ideal pixel size for different effects?</b></summary>

- **Fine Detail (s=4-8)**: Best for preserving details while adding pixelation effect
- **Balanced (s=16-32)**: Most common for nostalgic/retro look
- **Coarse (s=64+)**: For abstract, minimalist pixel art

</details>

<details>
<summary><b>How do I build on Windows?</b></summary>

```bash
mkdir build
cd build
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

The executable will be in `build\Release\pixel_artify.exe`

</details>

<details>
<summary><b>Can I use PixelArtify in my commercial project?</b></summary>

Yes! PixelArtify is licensed under MIT, which allows commercial use. See LICENSE file for details.

</details>

<details>
<summary><b>How do I improve color accuracy in the output?</b></summary>

- Use the grayscale mode (`-g`) for monochrome images
- Try enabling dithering (`-d`) for smoother color transitions
- Adjust pixel size based on image complexity
- Ensure input image has good contrast

</details>

---

## 📈 Roadmap

### Current Version (v1.0)
- [x] Basic pixelation functionality
- [x] Multiple format support
- [x] Grayscale conversion
- [x] CLI interface
- [x] Unit tests

### Planned Features (v1.1+)
- [ ] Real-time preview mode
- [ ] Batch processing with progress bar
- [ ] Color palette limiting
- [ ] Advanced dithering algorithms
- [ ] Configuration file support
- [ ] GUI application
- [ ] WebAssembly build for browser

---

## 🐛 Bug Reports & Feature Requests

- **Found a bug?** [Create an issue](https://github.com/firrthecreator/PixelArtify/issues/new?template=bug_report.md)
- **Have a suggestion?** [Request a feature](https://github.com/firrthecreator/PixelArtify/issues/new?template=feature_request.md)

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

### Third-Party Licenses

- **cxxopts**: MIT License
- **stb_image**: Public Domain
- **stb_image_write**: Public Domain

---

## 🙏 Acknowledgments

- Thanks to [Sean Barrett](https://github.com/nothings) for the excellent stb libraries
- Thanks to [Jarro Haapanen](https://github.com/jarro2783) for cxxopts
- Thanks to all contributors and users who have provided feedback

---

## 📞 Support

- **Documentation**: See [docs/USAGE.md](docs/USAGE.md)
- **Issues**: [GitHub Issues](https://github.com/firrthecreator/PixelArtify/issues)
- **Discussions**: [GitHub Discussions](https://github.com/firrthecreator/PixelArtify/discussions)

---

<div align="center">

Made with ❤️ by [firrthecreator](https://github.com/firrthecreator)

[⬆ back to top](#pixelartify)

</div>
