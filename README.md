# Code Starter

**Code Starter** is a tool that simplifies the process of starting new coding projects. With just a few steps, users can set up a fully functional project, complete with essential files, templates, and build scripts.

## Features

- **Multi-Language Support**: Code Starter comes with built-in templates for various programming languages, including C, Java, Python, C++, Rust, and more.
- **Build Script Generation**: Automatically generates a Makefile or bash/batch script for supported projects. For Python projects, it creates a `setup.py` file.
- **Library Management**: For languages like C, C++, and Rust, Code Starter creates a `libs` folder and offers a command-line interface to install packages similarly to `pip`. The installed libraries are tracked in a `.json` file and integrated into the Makefile for building.
- **Main File Creation**: A simple main file is generated for each language, containing a default output statement: `"Hello from Code Starter"`.
- **Custom Header File**: Automatically adds a custom header file (or equivalent) with version information and a compile number, which is incremented by the Makefile with each build.
- **Project Structure**: Creates a project directory structure, with separate folders for source code and build files. The project directory includes:
  - A source code folder with the main file.
  - A `build` folder where compiled files are stored.
  - A `.gitignore` file.
  - A `README.md` file.
- **File Header Comments**: Automatically adds a header of comments to the main file, including the author's name, license information, copyright details, and project description.
- **Compiler Detection**: Detects whether the correct compiler is installed on the system. If not, it provides a URL for downloading the appropriate compiler.
- **Custom Templates and Licenses**: Users can create custom templates and licenses. Additional libraries can be added to projects, with each library stored on GitHub in a JSON file. The necessary files are downloaded into the `libs` directory and built into a library archive (`.a` or the equivalent on Windows).

## Future Plans

- **Library Management Enhancements**: The way libraries are managed may evolve, with potential changes to how they are stored, built, and integrated into projects.

## Getting Started

To get started with Code Starter, simply run the tool and follow the on-screen prompts to create your project. The tool will guide you through the process of naming your project, providing a description, selecting a license, and more.

---

**Note**: Code Starter is a work in progress, and features may be added, modified, or removed in future updates. Stay tuned for improvements and new functionalities.
