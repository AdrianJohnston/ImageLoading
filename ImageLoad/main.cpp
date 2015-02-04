
/**
* This is a basic example of how to use the stb_image library. The stb_image library is a single header library.
* All that is required is to include the header and define the implementation flag (see below).
* stb_image.h was taken from https://github.com/nothings/stb . There are also other header only libraries that
* might be of use. stb_image_write.h and stb_image_resize.h . Both of these have a similar API and usage.
**/

#include <string>
#include <iostream>

/* The flag must be set before the header. !!!BUT ONLY ONCE!!! in your main file.*/
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


using std::string;

int main(){
    string image_path = "sphere_map.jpg";
    string output_path = "output.png";

    std::cout << "Input File path:" << image_path << std::endl;
    std::cout << "Output File path:" << output_path << std::endl;


    /*Loading a PNG/JPEG Image.*/

    int x,y,n;

    /*Unsigned char works well for 8bits per channel e.g. Standard PNG/JPEG images*/
    unsigned char *data = stbi_load(
            image_path.c_str(), /*char* filepath */
            &x, /*The address to store the width of the image*/
            &y, /*The address to store the height of the image*/
            &n  /*Number of channels in the image*/,
            0   /*Force number of channels if > 0*/
    );

    if (data == NULL){
        std::cerr << "Error loading: " << image_path << std::endl;

        /*Print the error message*/
        std::cerr << stbi_failure_reason() << std::endl;
        exit(-1);
    }

    std::cout << "Width: " << x << std::endl;
    std::cout << "Height: " << y << std::endl;
    std::cout << "Number of Channels: " << n << std::endl;



    return 0;
}