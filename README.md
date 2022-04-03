# ImageProcessor
ImageProcessor is a CLI program for applying various filters to images (currently only BMP is available).

## Program usage
You should run the program with the following arguments:

`./image_processor {input_path.bmp} {output_path.bmp}
[-{filter name 1} [params ...]]
[-{filter name 2} [params ...]] ...`

When run without arguments or with `--help` argument, the program displays help.

### Example:

`./image_processor input.bmp /tmp/output.bmp -crop 800 600 -gs -blur 0.5`

In this example
1. Image is loaded from file `input.bmp`
2. Image is cropped to the size of 800x600 starting from the point of upper left corner
3. Converted to shades of gray
4. Gaussian blur with `sigma = 0.5` applied
5. The resulting image is saved to the file `/tmp/output.bmp`

Filters are applied in the order they are listed in the command line arguments.

## Available filters
1. `-crop [int:width] [int:height]` crops the image leaving `width`x`height` image counting from upper left corner
2. `-gs` makes the image grayscale
3. `-sharp` slightly increases image sharpness
4. `-edge [float:threshold]` _(0 < threshold < 1)_ highlights image edges
5. `-blur [float:sigma]` applies [Gaussian blur](https://en.wikipedia.org/wiki/Gaussian_blur) to the image
6. `-median [int:size]` applies [Median blur](https://en.wikipedia.org/wiki/Median_filter) to the image (sets each pixel to the median of nearest `size`x`size` pixels)
