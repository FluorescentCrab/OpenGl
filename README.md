# Learning OpenGL: 3D Renderer

A custom 3D rendering engine built from scratch using Modern OpenGL (3.3) and C++. I put this project together while diving deep into computer graphics, shader programming, and GPU memory management via the LearnOpenGL guides.

---

## 📸 Media Showcase

### 3D Rotation & Texture Mapping
Demonstrating real-time 3D coordinate transformations and texture mapping onto a rotating primitive object:

<video src="Screen Recording 2026-07-02 000803.mp4" controls width="100%" muted loop>
  Your browser does not support the video tag.
</video>

### Lighting & Multi-Cube Rendering
Testing the Phong lighting setup (ambient, diffuse, and specular reflections) against a dynamic light source, alongside multi-object rendering passes.

| Specular & Diffuse Pass | Multi-Object Texture Rendering |
|---|---|
| ![Lighting Test 1](Screenshot%202026-07-02%20000407.png) | ![Textured Cube Field](Screenshot%202026-07-02%20000708.jpg) |
| ![Lighting Test 2](Screenshot%202026-07-02%20000419.png) | *(Close-up of the specular highlight behavior)* |

---

## 📁 Project Structure

```text
├── src/
│   ├── main.cpp             # Engine entry point, GLFW loop, and window config
│   ├── Shader.cpp           # Shader compilation and linking logic
│   ├── Shader.h             
│   ├── Camera.cpp           # View matrix calculations and mouse/keyboard input
│   └── Camera.h             
├── shaders/
│   ├── vertex_shader.glsl   # Vertex transformation & MVP multiplication
│   └── fragment_shader.glsl # Phong lighting math & texture sampling
├── textures/
│   └── container.jpg        # Diffuse map textures
├── CMakeLists.txt           # Build configuration script
└── README.md
