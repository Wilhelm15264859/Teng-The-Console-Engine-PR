# TENG: Simple console engine
The lib was built for C.

It was created to simplify the creating of console projects.

It's WIP so it may be worse than you think, but I'm working on it.
## How to use?
1. Install lib
2. Move teng.c and teng.h to your project's dir
3. Type `#include "teng.h"` 
4. Use!
## How to create a console projects?
This lib contains some functions for creating console projects:

| Function | Args | Description |
| :--- | :--- | :--- |
| `create_area` | int width, int height | Creates area |
| `update` | area_t area | Prints area |
| `change_buffer` | area_t *area, char buffer[] | Changes area's buffer |
| `update_with_buffer` | area_t *area, char buffer[] | Changes area's buffer, then prints area |