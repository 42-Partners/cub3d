*This project was created as part of the 42 curriculum by gustaoli, rafaoliv.*

# Cub3D

## Description

Cub3D is a simple 3D game engine inspired by the early days of first-person games like Wolfenstein 3D.  
The project uses a **raycasting algorithm** to render a 3D environment from a 2D map in real-time.

The main objective is to understand how 3D projection works using only basic mathematical concepts such as vectors, trigonometry, and grid traversal (DDA algorithm).

The player navigates through a maze, interacting with walls and the environment while the engine dynamically renders the scene.

The core of the project is based on:

- **Raycasting:** casting rays for each column of the screen
DDA (Digital Differential Analyzer): efficient grid traversal
Vector
- **Math:** direction and camera plane calculations
- **Perspective projection:** calculating wall height based on distance

---

## Instructions

### Requirements

- cc
- Make
- Codam MLX42
- libft

---

### Compilation

```bash
make
```

### Execution

```bash
./build/cub3d maps/your_map.cub
```

### Bonus

```bash
make bonus
```

### Controls

- Move Player: W / A / S / D
- Rotate View: ← / → / mouse
- Exit: ESC
- Run: shift
- Minimap: M

### Resources

- https://lodev.org/cgtutor/raycasting.html
- https://hackmd.io/@nszl/H1LXByIE2#Map-parsing-and-validating
- https://github.com/codam-coding-college/MLX42/tree/master/docs
- https://pt.wikipedia.org/wiki/Matriz_de_rota%C3%A7%C3%A3o

### AI Usage

- Clarify raycasting concepts and mathematical intuition
- Assist in debugging and understanding the DDA algorithm
- Improve code structure and readability
- Help refine explanations