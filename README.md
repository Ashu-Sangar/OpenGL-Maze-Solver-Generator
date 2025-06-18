# OpenGL Maze Solver Generator

An interactive 3D maze generation and solving application built with OpenGL and C. This project creates procedurally generated mazes that can be navigated in first-person view and automatically solved using pathfinding algorithms.

## 🎮 Features

### Core Functionality
- **Procedural Maze Generation**: Creates random mazes using recursive algorithms
- **3D Visualization**: Full 3D rendering with OpenGL and textured surfaces
- **Interactive Navigation**: First-person maze exploration with smooth animations
- **Automatic Solving**: Built-in maze solver using breadth-first search (BFS) and left-hand rule algorithms
- **Multiple Lighting Modes**: Ambient, diffuse, specular lighting with flashlight mode
- **Smooth Animations**: Fluid movement transitions and camera rotations

### Interactive Controls
- **Movement**: WASD keys for forward/backward/strafe movement
- **Looking**: Arrow keys for camera rotation
- **Mouse Controls**: Click and drag for manual camera control with scaling
- **Maze Solving**: Automatic pathfinding visualization
- **Lighting**: Toggle between different lighting modes
- **Reset**: Platform reset functionality with smooth animations

### Technical Features
- **Custom Math Library**: Complete vector and matrix operations
- **Shader Pipeline**: Custom vertex and fragment shaders for lighting and texturing
- **Texture Mapping**: Applied textures for realistic surfaces
- **Animation System**: Queued movement system for smooth transitions
- **Memory Management**: Dynamic allocation for scalable maze sizes

## 🏗️ Architecture

### Project Structure
```
OpenGL-Maze-Solver-Generator/
├── template/
│   ├── template.c          # Main application logic
│   ├── tempLib.c           # Custom math and utility library
│   ├── tempLib.h           # Library header file
│   ├── initShader.c        # Shader initialization
│   ├── initShader.h        # Shader header
│   ├── vshader.glsl        # Vertex shader
│   ├── fshader.glsl        # Fragment shader
│   ├── textures02.jpg      # Texture file
│   ├── textures02.raw      # Raw texture data
│   ├── makefile            # Build configuration
│   └── makefile.window     # Windows build configuration
├── .gitattributes
└── README.md
```

### Core Components

#### 1. Maze Generation (`template.c`)
- **Algorithm**: Recursive maze generation with wall carving
- **Data Structure**: 2D array of `Cell` structures with wall states
- **Customizable**: Variable maze dimensions via user input

#### 2. 3D Rendering Pipeline
- **Vertex Shader**: Handles transformations and lighting calculations
- **Fragment Shader**: Applies textures, lighting effects, and flashlight mode
- **Geometry**: Dynamic vertex generation for maze structures

#### 3. Navigation System
- **Player Tracking**: Position and orientation within maze coordinates
- **Collision Detection**: Prevents movement through walls
- **Smooth Animation**: Interpolated movement between positions

#### 4. Pathfinding Algorithms
- **BFS Shortest Path**: Finds optimal route through maze
- **Left-Hand Rule**: Wall-following algorithm for maze solving
- **Movement Queue**: Animated playback of solution path

## 🛠️ Technical Implementation

### Mathematics Library (`tempLib.c/h`)
```c
// Vector operations
vec4 vv_addition(vec4 v1, vec4 v2);
vec4 normalize(vec4 v);
float dot_product(vec4 v1, vec4 v2);

// Matrix operations
mat4 mm_multiplication(mat4 m1, mat4 m2);
mat4 look_at(vec4 eye, vec4 at, vec4 up);
mat4 translate(float x, float y, float z);
```

### Maze Data Structure
```c
typedef struct {
    bool top_wall;
    bool bottom_wall;
    bool left_wall;
    bool right_wall;
} Cell;

Cell **maze; // 2D dynamic array
```

### Movement Animation System
```c
typedef enum {
    MOVE_FORWARD, MOVE_BACKWARD,
    SLIDE_LEFT, SLIDE_RIGHT,
    TURN_LEFT, TURN_RIGHT
} MovementType;

// Queue system for smooth movement sequences
MovementCommand movement_queue[QUEUE_SIZE];
```

## 🚀 Getting Started

### Prerequisites
- **macOS**: Xcode Command Line Tools
- **OpenGL**: Built-in with macOS
- **GLUT**: Built-in with macOS
- **GCC**: For compilation

### Installation & Build

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/OpenGL-Maze-Solver-Generator.git
   cd OpenGL-Maze-Solver-Generator/template
   ```

2. **Compile the project**:
   ```bash
   make
   ```

3. **Run the application**:
   ```bash
   ./template
   ```

### For Windows Users
Use the Windows makefile:
```bash
make -f makefile.window
```

## 🎮 Controls & Usage

### Keyboard Controls
| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `↑` | Look up |
| `↓` | Look down |
| `←` | Turn left |
| `→` | Turn right |
| `L` | Toggle lighting modes |
| `F` | Toggle flashlight |
| `Space` | Solve maze automatically |
| `R` | Reset platform |
| `Q` | Quit application |

### Mouse Controls
- **Left Click + Drag**: Rotate camera view
- **Right Click + Drag**: Scale view
- **Scroll**: Zoom in/out

### Getting Started
1. **Launch**: Run the executable to start with maze generation prompt
2. **Set Size**: Enter desired maze dimensions (e.g., 10x10)
3. **Navigate**: Use WASD keys to explore the generated maze
4. **Solve**: Press Space to watch the automatic solver in action
5. **Experiment**: Try different lighting modes and camera angles

## 🧩 Algorithms

### Maze Generation
- **Recursive Division**: Creates maze by recursively dividing space and adding passages
- **Wall Carving**: Ensures all areas are reachable by selectively removing walls
- **Randomization**: Uses seeded random number generation for reproducible mazes

### Pathfinding
- **Breadth-First Search (BFS)**:
  - Guarantees shortest path solution
  - Explores all possible paths systematically
  - Reconstructs path from goal to start

- **Left-Hand Rule**:
  - Simple wall-following algorithm
  - Always keeps left hand on wall
  - Guarantees maze completion (for simply connected mazes)

### Animation System
- **Interpolation**: Smooth transitions between positions
- **Queuing**: Sequential execution of movement commands
- **Timing**: Frame-rate independent animation timing

## 🎨 Rendering Features

### Lighting Models
- **Ambient Lighting**: Base illumination level
- **Diffuse Lighting**: Surface angle-dependent lighting
- **Specular Lighting**: Reflective highlights
- **Flashlight Mode**: Directional cone lighting from player position

### Texturing
- **Wall Textures**: Applied to maze walls for visual depth
- **Floor Textures**: Ground surface texturing
- **UV Mapping**: Proper texture coordinate mapping

### Visual Effects
- **Smooth Animations**: Interpolated movement and rotation
- **Dynamic Lighting**: Real-time lighting calculations
- **Perspective Projection**: 3D depth perception
- **Texture Filtering**: Smooth texture rendering

## 📊 Performance Considerations

### Optimization Techniques
- **Frustum Culling**: Only render visible geometry
- **Level of Detail**: Adaptive geometry complexity
- **Batch Rendering**: Minimize draw calls
- **Memory Pooling**: Efficient vertex buffer management

### Scalability
- **Dynamic Allocation**: Supports variable maze sizes
- **Configurable Quality**: Adjustable rendering settings
- **Platform Optimization**: Compiler-specific optimizations

## 🔧 Customization

### Maze Parameters
```c
// Modify in template.c
int maze_x_size = 20;  // Width
int maze_z_size = 20;  // Height
```

### Animation Speed
```c
int max_steps = 40;    // Higher = slower animations
```

### Lighting Settings
```c
float ambient_coefficient = 0.3;
float specular_power = 80.0;
```

### Camera Settings
```c
float eye_height = 0.5;  // Player eye level
float movement_speed = 1.0; 
```

## 🐛 Troubleshooting

### Common Issues

**Compilation Errors**:
- Ensure Xcode Command Line Tools are installed
- Check OpenGL framework availability
- Verify file permissions

**Runtime Issues**:
- **Black Screen**: Check shader compilation
- **Texture Problems**: Verify texture file paths
- **Movement Issues**: Check collision detection logic

**Performance Issues**:
- Reduce maze size for better performance
- Disable specular lighting for faster rendering
- Lower animation step count

### Debug Features
- **Console Output**: Position and state information
- **Error Checking**: OpenGL error detection
- **Memory Monitoring**: Allocation/deallocation tracking

## 🤝 Contributing

### Development Setup
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

### Code Style
- Follow existing naming conventions
- Comment complex algorithms
- Use consistent indentation
- Document new features

### Areas for Contribution
- Additional maze generation algorithms
- New pathfinding methods
- Enhanced visual effects
- Performance optimizations
- Cross-platform compatibility

## 📚 Technical Documentation

### Shader Variables
```glsl
// Vertex Shader Uniforms
uniform mat4 model_view;
uniform mat4 projection;
uniform mat4 ctm;
uniform vec4 light_position;

// Fragment Shader Uniforms
uniform sampler2D texture;
uniform int enable_light;
uniform int flashlight;
```

### Matrix Transformations
- **Model Matrix**: Object-to-world transformation
- **View Matrix**: World-to-camera transformation  
- **Projection Matrix**: 3D-to-2D screen projection
- **CTM (Current Transformation Matrix)**: Combined transformations

## 📄 License

This project is open source. Feel free to use, modify, and distribute according to your needs.

## 🙏 Acknowledgments

- OpenGL community for excellent documentation
- GLUT library for window management
- Contributors to maze generation algorithms
- Graphics programming community

---

**Enjoy exploring and solving mazes in 3D!** 🎮✨ 