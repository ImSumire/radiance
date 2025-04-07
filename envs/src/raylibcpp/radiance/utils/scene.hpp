#pragma once

#include <vector>
#include <memory>
#include <stdexcept>

#include "types.hpp"
#include "../../src/common/state.hpp"


struct Scene {
    // Once
    virtual void init(State* state) {}
    virtual void drop(State* state) {}

    // Each tick
    virtual Option<usize> update(State* state) {
        return None;
    }
    virtual void render(State* state) {}
    
    // At join/quit
    virtual void join(State* state) {}
    virtual void quit(State* state) {}
};

struct SceneManager {
    std::vector<std::unique_ptr<Scene>> scenes;
    Scene* current = nullptr;

    void add(Scene* scene, State* state) {
        scene->init(state);
        scenes.push_back(std::unique_ptr<Scene>(scene));

        if (!current) {
            change(scenes.size() - 1, state);
        }
    }

    void change(usize index, State* state) {
        if (index >= scenes.size()) {
            throw std::out_of_range("Scene index is out of range");
        }
        if (current) {
            current->quit(state);
        }

        current = scenes[index].get();
        current->join(state);
    }

    void update(State* state) {
        if (current) {
            Option<usize> new_scene = current->update(state);

            if (new_scene.has_value()) {
                change(new_scene.value(), state);
            }
        }
    }

    void render(State* state) {
        if (current) {
            current->render(state);
        }
    }
};
