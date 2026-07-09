##### Declaration of PTR

```cpp
\b[\w:<>]+\s*\*+\s*\w+\b

\b(?:const\s+)?[\w:<>]+\s*(?:const\s+)?\*+\s*\w+\b
```

#### Delete SDL2 from or Sample how to delete pacman packanges
```
sudo pacman -Rns $(pacman -Qq | grep '^sdl2')
```