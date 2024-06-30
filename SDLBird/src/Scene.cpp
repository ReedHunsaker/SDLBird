//
//  Scene.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/27/24.
//

#include "Scene.hpp"

Scene::Scene(SDL_Window *window, SDL_Renderer *renderer) {
    this->window = window;
    this->renderer = renderer;
}

void Scene::addEntity(Entity *entity) {
    entities.push_back(entity);
}

void Scene::removeEntity(Entity *entity) {
    entities.remove(entity);
}

void Scene::setup() {
    // Captures a reference to the class in order to use window and renderer
    forEachEntity([this](Entity* entity) {
        entity->setup(window, renderer);
    });
}

void Scene::input(Uint32 eventType) {
    // Captures the extra event type context for the `forEachEntity`
    forEachEntity([eventType](Entity* entity) {
        entity->input(eventType);
    });
}

void Scene::update() {
    forEachEntity([](Entity* entity) {
        entity->update();
    });
}

void Scene::render() {
    forEachEntity([this](Entity* entity) {
        entity->render(renderer);
    });
}
