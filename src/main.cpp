
#include <vishwakarma/graphics/DeviceFactory.hpp>
#include <vishwakarma/platform/Window.hpp>

#include <cstdlib>
#include <exception>
#include <iostream>

int main() {
    try {
        vishwakarma::platform::WindowDesc windowDesc;
        windowDesc.width = 1280;
        windowDesc.height = 800;
        windowDesc.title = "CTMRI Workstation";
        windowDesc.debugContext = true;

        vishwakarma::platform::Window window(windowDesc);

        auto device = vishwakarma::graphics::createDevice(
            vishwakarma::graphics::Backend::OpenGL,
            window
        );

        window.setResizeCallback(
            [&device](int width, int height) {
                device->resize(width, height);
            }
        );

        // Position + RGBA color per vertex.
        constexpr float triangle[] = {
            // x      y      z      r     g     b     a
             0.0f,  0.6f,  0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            -0.6f, -0.5f,  0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
             0.6f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f
        };

        const vishwakarma::graphics::Color clearColor = {
            0.08f, 0.09f, 0.12f, 1.0f
        };

        std::cout << "Renderer: " << device->name() << '\n';

        while (!window.shouldClose()) {
            window.pollEvents();

            device->beginFrame(clearColor);
            device->drawTriangles(triangle, 3);
            device->endFrame();

            window.swapBuffers();
        }

        // Destroy GPU resources while the window context is alive.
        device.reset();

    } catch (const std::exception& exception) {
        std::cerr << "CTMRI startup/runtime error: "
                  << exception.what() << '\n';

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
