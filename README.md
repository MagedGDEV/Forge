# Forge ⚒️

Forge is a lightweight 2D game engine built in C++ with Lua scripting for flexible game logic.
It’s designed to be simple to set up, fast to build, and easy to extend, making it a solid foundation for creating 2D games.

- C++ core for performance.
- Lua + Sol2 integration for intuitive scripting.
- Dependency management with CPM — no manual library setup.
- Currently focused on 2D development (future-ready for more).

## Recommended Built Setup

- Use **CMake with Ninja** for faster builds.
- Add the following to your CMake configure arguments:

    ```bash
    -DCMAKE_POLICY_VERSION_MINIMUM=3.5
    ```

## Dependencies

The engine depends on the following libraries:

- SDL2
- SDL2_ttf
- SDL2_image
- SDL2_mixer
- GLM
- Dear ImGui
- Lua
- Sol2

> [!WARNING]
> You need a **GitHub account** configured on your machine (SSH or HTTPS) since all libraries are fetched directly from GitHub.

## CPM Setup (Required)

Forge uses CPM.cmake a CMake-based package manager that automatically fetches dependencies (like SDL, ImGui, Lua, etc.) directly from GitHub. This means you don’t need to install these libraries manually.

To make CPM efficient:

1. Create an environment variable called `CPM_SOURCE_CACHE`.
2. Point it to an empty folder where CPM will store downloaded dependencies.

> [!CAUTION]
> Without this, CPM will re-download all libraries every time you do a clean build.

## Platform Setup

Each operating system requires a different setup process to ensure SDL and its dependencies work correctly.
If you don’t follow these steps, CMake will fail during configuration and let you know exactly which libraries or tools are missing.

### macOS 🍎

- Install required SDL dependencies with Homebrew:

    ```bash
    brew install opus
    brew install libxmp
    brew install fluidsynth
    brew install wavpack
    ```

- Fix: In `opusfile.h`, replace

    ```cpp
    #include <opus_multistream.h>
    ```

    with

    ```cpp
    #include "opus_multistream.h"
    ```

### Windows 🪟

1. Install **[NASM Assembler](https://www.nasm.us/)** (stable version).
2. Add it's path to your **environment variables**.
3. Run CMake from **Developer Command Prompt for VS** (required for Microsoft Macro Assembler).

If using **VSCode / VSCodium**, configure your terminal to always launch Developer Command Prompt as example below:

```json
"terminal.integrated.profiles.windows": {
    "VS": {
        "path": "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/Tools/VSDevCmd.bat",
        "args": []
    }
},
"terminal.integrated.defaultProfile.windows": "VS",
```

> [!NOTE]
> Make sure to add your actaul path to VSDevCmd.bat

### Linux 🐧

Coming soon 🚧
