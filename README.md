<div align="center">
  <img alt="Logo" src="logo.png" align="left" width="168px">
  <section>
    <h3>✨ Radiance</h3>
    <b>Radiance is a game framework</b> based on multiple back-ends, featuring <b>hot-reloading, scene management & build system</b>. Inspired by the <a href="https://doc.rust-lang.org/cargo/">Cargo</a> environment, it offers a complete env without the need to open a new window. Radiance is <b>designed to be minimal</b>, with a few built-ins added to facilitate the creation of games such as: Static globals, Networking, Physics, Pathfinding, UI system & Entity Component System.
  </section>
</div>
<br>

### Why code a game at low-level?
Everyone's entitled to their own opinion, but personally I just can't get to grips with game engines like Godot, Unreal and Unity. Yet I've really tried, but find the progression line exponential: at the start, everything's very easy, everything's already done, but as soon as you want to add a specific feature, it takes an enormous amount of time. On several occasions, I've spent hours trying to figure out how to do something that would have taken me about 10 minutes with pure code. I also remember that during a game jam, I had implemented a particle system to make wind, but after adding a scene (completely independent of the wind scene and the scene that uses it), it no longer worked, the debugs worked but the display didn't... So after spending 2 hours on a 48-hour game jam, it hurt... That's why I want to make a framework (not a game engine, because there probably won't be any graphical interface) that installs a full environment, with plenty of built-ins but without the limitation of a restrictive scene and node system.

### Installation
Create a new folder, open a terminal in it and run:
##### C & Raylib
`curl https://imsumire.github.io/radiance/raylibc.sh | sh`

##### C++ & Raylib
`curl https://imsumire.github.io/radiance/raylibcpp.sh | sh`

> The project creation page will soon be available!
