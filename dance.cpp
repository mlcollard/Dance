/*
    dance.cpp

    ASCII dancer who dances forever.
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <array>
#include <string_view>
#include <cstdlib>

int main(int argc, char* argv[]) {

    // delay between frames
    int delay = 500;

    if (argc > 2) {
        std::cerr << "Usage: " << argv[0] << " [optional delay]" << '\n';
        return 1;
    }

    // first parameter is the delay
    if (argc == 2) {
        delay = std::atoi(argv[1]);
    }

    // Define the frames of the ASCII dance
    std::array<std::string_view, 4> frames{
        "  O\n /|\\\n / \\\n",
        " \\O/\n  |\n / \\\n",
        "  O\n /|\\\n / \\\n",
        " /O\\\n  |\n / \\\n"
    };

    // Number of frames
    int frameCount = sizeof(frames)/sizeof(frames[0]);

    // Output the dance
    while (true) {

        for (const auto frame : frames) {

            // Clear the screen
            // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
            std::cout << "\033[2J\033[H";

            // Output the frame
            std::cout << frame << '\n';

            // Wait for a bit
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }

    return 0;
}
