# Learning OpenGL: 3D Renderer

A custom 3D rendering engine built from scratch using Modern OpenGL (3.3) and C++. I put this project together while diving deep into computer graphics, shader programming, and GPU memory management via the LearnOpenGL guides.

---

## Media Showcase

### 3D Rotation & Texture Mapping
Demonstrating real-time 3D coordinate transformations and texture mapping onto a rotating primitive object:

https://github.com/your-username/your-repo-name/blob/main/Screen%20Recording%202026-07-02%20000803.mp4

### Lighting & Multi-Cube Rendering
Testing the Phong lighting setup (ambient, diffuse, and specular reflections) against a dynamic light source, alongside multi-object rendering passes.

| Specular & Diffuse Pass | Multi-Object Texture Rendering |
|---|---|
| ![Lighting Test 1](Screenshot%202026-07-02%20000407.png) | ![Textured Cube Field](Screenshot%202026-07-02%20000708.jpg) |
| ![Lighting Test 2](Screenshot%202026-07-02%20000419.png) | *(Close-up of the specular highlight behavior)* |

---

## Core Features Implemented

*   **Modern OpenGL Pipeline:** No deprecated fixed functions. Everything uses VAOs, VBOs, and EBOs to stream vertex data directly to the GPU for efficient rendering.
*   **Custom GLSL Shaders:** Wrote custom vertex and fragment shaders to handle pixel colors, transformations, and vertex manipulation in real-time.
*   **Phong Lighting Model:** Implemented real-time lighting math into the fragment shader to process Ambient, Diffuse, and Specular light components relative to a moving light source.
*   **Texture Mapping:** Integrated a 2D texture loading pipeline using `stb_image` to map textures onto 3D coordinates smoothly.
*   **MVP Matrix Math:** Handled the linear algebra behind Model, View, and Projection matrices to simulate realistic perspective depth and a controllable camera system.

---

## Tech Stack

*   **Language:** C++
*   **Graphics API:** Modern OpenGL (Core Profile)
*   **Libraries:** GLFW (Windowing & Input), GLAD (Extension Loader), GLM (3D Math), `stb_image` (Texture Loading)

---

## How to Run It Locally

### Prerequisites
You'll need a C++ compiler and CMake installed. Make sure GLFW, GLAD, and GLM are properly configured in your system environment.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/your-username/your-repo-name.git](https://github.com/your-username/your-repo-name.git)
   cd your-repo-name
