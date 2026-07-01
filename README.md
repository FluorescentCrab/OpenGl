# Learning OpenGL: 3D Renderer

A custom 3D rendering engine built from scratch using Modern OpenGL (3.3) and C++. I put this project together while diving deep into computer graphics, shader programming, and GPU memory management via the LearnOpenGL guides.[cite: 1]

---

## 📸 Media Showcase

### 3D Rotation & Texture Mapping
Demonstrating real-time 3D coordinate transformations and texture mapping onto a rotating primitive object:[cite: 1]

<video src="ss_/Screen%20Recording%202026-07-02%20000803.mp4" controls width="100%" muted loop>
  Your browser does not support the video tag.
</video>[cite: 1]

### Lighting & Multi-Cube Rendering
Testing the Phong lighting setup (ambient, diffuse, and specular reflections) against a dynamic light source, alongside multi-object rendering passes.[cite: 1]

| Specular & Diffuse Pass | Multi-Object Texture Rendering |
|---|---|
| ![Lighting Test 1](ss_/Screenshot%202026-07-02%20000407.png) | ![Textured Cube Field](ss_/Screenshot%202026-07-02%20000708.png) |
| ![Lighting Test 2](ss_/Screenshot%202026-07-02%20000419.png) | *(Close-up of the specular highlight behavior)* |[cite: 1]

---

## 📁 Project Structure

```text
---

## 🛠️ Core Features Implemented

* **Modern OpenGL Pipeline:** No deprecated fixed functions. Everything uses VAOs, VBOs, and EBOs to stream vertex data directly to the GPU for efficient rendering.[cite: 1]
* **Custom GLSL Shaders:** Wrote custom vertex and fragment shaders to handle pixel colors, transformations, and vertex manipulation in real-time.[cite: 1]
* **Phong Lighting Model:** Implemented real-time lighting math into the fragment shader to process Ambient, Diffuse, and Specular light components relative to a moving light source.[cite: 1]
* **Texture Mapping:** Integrated a 2D texture loading pipeline using `stb_image` to map textures onto 3D coordinates smoothly.[cite: 1]
* **MVP Matrix Math:** Handled the linear algebra behind Model, View, and Projection matrices to simulate realistic perspective depth and a controllable camera system.[cite: 1]

---

## 🧰 Tech Stack

* **Language:** C++[cite: 1]
* **Graphics API:** Modern OpenGL (Core Profile)[cite: 1]
* **Libraries:** GLFW (Windowing & Input), GLAD (Extension Loader), GLM (3D Math), `stb_image` (Texture Loading)[cite: 1]
