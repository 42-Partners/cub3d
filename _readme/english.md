# cub3d

![project 125/100 outstanding_project](./cub3dbanner.png)
![intra evals](./evals.png)

[ 🇧🇷 Versão em Português 🇧🇷](https://github.com/42-Partners/cub3d) ‎ ‎ ‎ ‎ | ‎ ‎ ‎ ‎ [Project Link (Intra)](https://projects.intra.42.fr/projects/cub3d/projects_users/4864496)

# Demo

[![demo video](./videodemo.png)](https://github.com/42-Partners/cub3d/blob/main/./cub3demo.mp4)

# Screenshots

![Demo](./demo01.png)
![Demo](./demo02.png)
![Demo](./demo03.png)
![Demo](./demo04.png)
![Demo](./demo05.png)

# Summary

**cub3d** is a project from the 42 curriculum that challenges students to create a functional graphic engine inspired by the legendary *Wolfenstein 3D* (1992). The main goal is to explore the **Raycasting** technique, transforming a purely two-dimensional map into a 3D visual representation in real-time, using mathematical concepts of trigonometry, vectors, and the efficient DDA algorithm.

# Introduction

Before the era of modern GPUs and complex polygons, computers had extremely limited resources. In 1992, id Software revolutionized the gaming industry by launching the first successful FPS (*First Person Shooter*): Wolfenstein 3D.

The secret behind this "magic" wasn't a real 3D environment, but a technique called **Raycasting**. Unlike modern Raytracing, which simulates the physical behavior of light in all directions, Raycasting simplifies the world into a 2D grid, allowing rendering to happen extremely fast, even on legacy hardware.

# Context: The 2D World

For the computer, the game map is just a matrix (grid) of integers. A `1` might represent a wall and a `0` an empty space. The challenge is: how to determine what the player sees from a coordinate `(x, y)` and a specific viewing angle?

Unlike modern 3D engines where you define "cameras", here we work with **Direction Vectors** and the **Camera Plane**.

* **Direction Vector (Dir):** Where the player is looking at.
* **Camera Plane (Plane):** A line perpendicular to the direction vector that defines the FOV (*Field of View*).

# The Core of the Engine: Raycasting

The fundamental logic of Raycasting is that for every vertical column of pixels on your screen, you "cast" a ray from the player's position.

The process follows these steps for each ray:

1. **Direction Calculation:** We determine the ray's direction based on the camera plane and the screen's `x` column.
2. **Grid Localization:** We identify which map square the player is currently in.
3. **Ray Path:** We calculate how far the ray must travel to cross a grid line (either horizontal or vertical).

# The DDA Algorithm (Digital Differential Analyzer)

Checking point-by-point if a ray hit a wall would be computationally expensive and imprecise. To solve this, we use the **DDA**.

DDA is a "grid jumping" algorithm. Instead of advancing in tiny steps, the ray jumps directly to the next vertical or horizontal grid line, whichever is closest.

### DDA Critical Variables:

* **`deltaDistX/Y`**: The distance the ray travels from one grid line to the next.
* **`sideDistX/Y`**: The distance from the player's current position to the first grid line.
* **`stepX/Y`**: The jump direction (positive or negative).

When the DDA detects that the current map square is a wall (`1`), it stops. At that moment, we know the exact distance traveled.

# Rendering and Perspective

Once we have the ray distance, we need to project it onto the screen. This is where **Perspective Projection** comes in.

### Fish-eye Effect Correction

If we used the Euclidean distance (direct from player to wall), the walls would appear curved because the rays at the edges of the vision are naturally longer than those in the center. To fix this, we calculate the **Perpendicular Distance** relative to the camera plane.

### Wall Height

The height of the line we draw on the screen is inversely proportional to the distance: the further the wall, the smaller it appears.

```c
lineHeight = (int)(h / perpWallDist);

```

# Dynamic UI and Advanced Features

We enhanced immersion with an interface built via direct buffer manipulation, ensuring fluid transitions and interactive elements that go beyond static patterns:

* **Hover Animations:** Instant visual feedback on buttons via mouse coordinate detection.
* **State Management:** A dedicated loop for stable and performant transitions between menus and gameplay.
* **Real-time Minimap:** A 2D navigation system synchronized with the player's position and direction.
* **Vertical Look:** Logical expansion of the engine to allow *pitching* movement (looking up/down).

# Conclusion

**cub3d** is more than just a game; it is a deep lesson on how mathematics can be used to create complex visual illusions. By implementing DDA and Raycasting from scratch, we understand the foundations that allowed the birth of the golden age of 3D gaming.

"The real Cub3d are the friends we make along the way"

---

### How to Run

1. Clone the repository:

```bash
git clone https://github.com/42-Partners/cub3d.git

```

2. Compile and run the project:

```bash
make bonus

```

### Controls and Shortcuts

The key mapping was designed to offer a fluid navigation experience and total control over the graphic engine:

| Key | Function |
| --- | --- |
| **`W` `A` `S` `D`** | Movement (Forward, Left, Backward, Right) |
| **`←` `→`** | Horizontal camera rotation |
| **`↑` `↓`** | Vertical look (*Pitching*) |
| **`MOUSE`** | Look horizontally and vertically |
| **`SHIFT`** | Sprint (Speed boost) |
| **`M`** | Toggle Minimap display |
| **`ESC`** | Close the game and exit process |

---

Made by:

* [gustaoli](https://github.com/Gus1331)
* [rafaoliv](https://github.com/devrafaelly)

![Creators](./credits.png)
