# PixelArtify Usage Guide

This guide provides detailed information on all available command-line options for PixelArtify.

---

## Synopsis

```bash
./pixel_artify -i <input_file> -o <output_file> -s <pixel_size> [options]
```

---

## Required Arguments

| Option     | Short | Description                                | Example               |
|------------|-------|--------------------------------------------|-----------------------|
| `--input`  | `-i`  | Path to the source image file              | `-i my_photo.png`     |
| `--output` | `-o`  | Path to save the resulting pixel art image | `-o result.jpg`       |
| `--size`   | `-s`  | The size (in pixels) of each block         | `-s 12`               |

---

## Optional Arguments

| Option       | Short | Description                                          |
|--------------|-------|------------------------------------------------------|
| `--grayscale`| `-g`  | Convert the image to grayscale before pixelating     |
| `--help`     | `-h`  | Display the help message with all available options  |

---

## Examples

### 1. Basic Conversion

```bash
./pixel_artify -i ./assets/landscape.jpg -o ./output/landscape_pixel_10.png -s 10
```

Effect: This will create a moderately pixelated version of the original image.

---

### 2. High Detail Pixelation

```bash
./pixel_artify -i ./assets/portrait.jpg -o ./output/portrait_pixel_4.png -s 4
```

Effect: The output retains more features but still looks like pixel art.

---

### 3. Abstract Pixelation (Large Blocks)

```bash
./pixel_artify -i ./assets/city.png -o ./output/city_pixel_32.png -s 32
```

Effect: The image becomes highly simplified and blocky.

---

### 4. Grayscale Conversion

```bash
./pixel_artify -i ./assets/forest.jpg -o ./output/forest_grayscale_16.png -s 16 -g
```

Effect: Resulting image will be both pixelated and black-and-white.
