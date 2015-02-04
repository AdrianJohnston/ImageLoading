
/**
* This is a basic example of how to use the stb_image library. The stb_image library is a single header library.
* All that is required is to include the header and define the implementation flag (see below).
* stb_image.h was taken from https://github.com/nothings/stb . There are also other header only libraries that
* might be of use. stb_image_write.h and stb_image_resize.h . Both of these have a similar API and usage.
**/
#include <stdio.h>
#include <string>
#include <iostream>

// Include GLEW before GLFW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

/* The flag must be set before the header. !!!BUT ONLY ONCE!!! in your main file.*/
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using std::string;

//Global Window object
GLFWwindow* window;

/*Could use a class here, but want to maintain C backward compatibility for examples*/
//struct Texture{
//    unsigned char* pixels;
//    int width;
//    int height;
//
////    Texture(unsigned char* pixels, int width, int height){
////        this->pixels = pixels;
////        this->width = width;
////        this->height = height;
////    }
//};

class Texture{
public:
    Texture(unsigned char* pixels, int width, int height){
        this->pixels = pixels;
        this->width = width;
        this->height = height;
    }

    ~Texture(){
        delete(this->pixels);
    }

    unsigned char* pixels;
    int width;
    int height;
};



unsigned char* load_image(string file_path, int* x, int* y){
    /**
    * Wrapper function for loading an image using sbt_image. Sets default number of components.
    * string file_path: Path to the image to load
    * int* x: address to store the width of the image
    * int* y: address to store the height of the image
    */
    int n;
    unsigned char *data = stbi_load(
            file_path.c_str(), /*char* filepath */
            x, /*The address to store the width of the image*/
            y, /*The address to store the height of the image*/
            &n  /*Number of channels in the image*/,
            0   /*Force number of channels if > 0*/
    );

    return data;
}



const char* image_failure_message(){
    /**
    * Wrapper function for getting the error message from the stb_image library
    */
    return stbi_failure_reason();
}

Texture* init_resources(){
    string image_path = "sphere_map.jpg";
    string output_path = "output.png";

    std::cout << "Input File path:" << image_path << std::endl;
    std::cout << "Output File path:" << output_path << std::endl;

    int width, height;
    unsigned char* data = load_image(image_path, &width, &height);

    /*Check to see if the image was loaded correctly*/
    if (data == NULL){
        std::cerr << "Error Loading: " << image_path << " " << image_failure_message() << std::endl;
    }

    Texture *texture = new Texture(data, width, height);
    return texture;
}

void init_display(){
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
}

void render(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}

int main(){

    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return -1;
    }

//
//    glfwWindowHint(GLFW_SAMPLES, 4);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 512, 512, "Image Viewer", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n" );
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


    Texture* image = init_resources();
    std::cout << "Width: " << image->width << std::endl;
    std::cout << "Height: " << image->height << std::endl;

    while (!glfwWindowShouldClose(window))
    {
        init_display();
        //render();
        glDrawPixels(image->width, image->height, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete(image);

    //End the application
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}