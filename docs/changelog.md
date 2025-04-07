# Changelog

| Development stage  | Simplified semantic versioning |
|--------------------|--------------------------------|
| Alpha              | 1.2.0a1                        |
| Beta               | 1.2.0b2                        |
| Release candidate  | 1.2.0rc3                       |
| Release            | 1.2.0                          |
| Post-release fixes | 1.2.0pr1                       |

Source: [Wikipedia](https://en.wikipedia.org/wiki/Software_versioning)


## @0.0.1pr1
- Added banners to commands
- Empty web pages

## @0.0.1
- Removed useless code
- Added C++ & Raylib environment
- Added `docs` command
- Added scene management system for C++ (`radiance/utils/scene.hpp`)
- Added setup system (`raylibcpp.sh`)

## @0.0.1b2
- Re-structured the repository
- Added setup system (`raylibc.sh`)
- Compressed `logo.png` (38kB → 2.6kB)
- Created the tar compression automation for each envs
- Added `clean` command
- Renaming `dev` command to `hot`
- Simplified access to radiance sources (`radiance/src` → `radiance`)

## @0.0.1b1
- Added C (not 99) & Raylib environment
- Added build & hot-reloading implementation
- Added project maker design
